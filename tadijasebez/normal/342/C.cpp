#include <stdio.h>
main()
{
 float r,h;
 scanf("%f %f",&r,&h);
 int d=h/r+0.5;
 printf("%i\n",(int)((h/r+1-d)*1.154701)+d*2);
}