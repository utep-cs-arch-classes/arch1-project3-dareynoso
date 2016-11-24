#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"


AbRect rect10 = {abRectGetBounds, abRectCheck, 10,10};
AbRArrow arrow20 = {abRArrowGetBounds, abRArrowCheck, 20};
AbRect lineh30 ={abLineHGetBounds, abLineHCheck,70,1};
AbRect linev40 ={abLineVGetBounds, abLineVCheck, 1,75};

Region fence = {{10,30}, {SHORT_EDGE_PIXELS-10, LONG_EDGE_PIXELS-10}};


abDrawPos(AbShape *shape,Vec2 *shapeCenter,u_int fg_color, u_int bg_color){
 u_char row,col;
  Region bounds;
  abShapeGetBounds(shape,shapeCenter,&bounds);
  lcd_setArea(bounds.topLeft.axes[0],bounds.topLeft.axes[1],
             bounds.botRight.axes[0]-1, bounds.botRight.axes[1]-1);
  for(row =bounds.topLeft.axes[1];row<bounds.botRight.axes[1];row++){
    for(col=bounds.topLeft.axes[0];col<bounds.botRight.axes[0];col++){
 Vec2 pixelPos ={col,row};
 int color =abShapeCheck(shape,shapeCenter, &pixelPos)?
   fg_color : bg_color;
  lcd_writeColor(color);
  }
 }
}

Layer layer2 = {
  (AbShape *)&arrow20,
  // {screenWidth/2+40, screenHeight/2+10}, 	    /* position */
  // {16,screenHeight-20},
  {screenWidth/2,screenHeight/2},
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_RED,
  0,
};
Layer layer1 = {
  (AbShape *)&linev40,
  {screenWidth/2, (screenHeight/2)-15}, 	    /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLACK,
  &layer2,
};
Layer layer0 = {
  (AbShape *)&linev40,
  {screenWidth/4, (screenHeight/2)-15}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLACK,
  &layer1,
};
Layer layer3 = {
  (AbShape *)&linev40,
  {(screenWidth/2)+(screenWidth/4), (screenHeight/2)-15}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLACK,
  &layer0,
};
Layer layer4 = {
  (AbShape *)&lineh30,
  {screenWidth/2,screenHeight/2+60}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLACK,
  &layer3,
};

Layer layer5 = {
  (AbShape *)&rect10,
  {screenWidth/2-47,screenHeight/2-60}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_GREEN,
  &layer4,
};

Layer layer6 = {
  (AbShape *)&rect10,
  {screenWidth/2-17,screenHeight/2-60}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_ORANGE,
  &layer5,
};

Layer layer7 = {
  (AbShape *)&rect10,
  {screenWidth/2+17,screenHeight/2-60}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_RED,
  &layer6,
};
Layer layer8 = {
  (AbShape *)&rect10,
  {screenWidth/2+47,screenHeight/2-60}, /* position */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_YELLOW,
  &layer7,
};


u_int bgColor = COLOR_BLUE;

main()
{
  configureClocks();
  lcd_init();
  shapeInit();
  Vec2 rectPos = screenCenter, circlePos = {30,screenHeight - 30};

  layerInit(&layer8);
  layerDraw(&layer8);
  
  
  drawString5x7(10,150, "HOT ROAD", COLOR_ORANGE, COLOR_BLUE);
    shapeInit();
  
}


