#include <stdio.h>
int main()
{
	char start,end;
	int n;
	int startI,endI;
	scanf("%c %c",&start,&end);
	scanf("%i",&n);
	n%=4;
	if(start=='v') startI=0;
	if(start=='<') startI=1;
	if(start=='^') startI=2;
	if(start=='>') startI=3;
	if(end=='v') endI=0;
	if(end=='<') endI=1;
	if(end=='^') endI=2;
	if(end=='>') endI=3;
	int cw=(startI+n)%4;
	int ccw=((startI-n)+4)%4;
	if(cw==endI && ccw!=endI) printf("cw\n");
	else if(cw!=endI && ccw==endI) printf("ccw\n");
	else printf("undefined\n");
	return 0;
}