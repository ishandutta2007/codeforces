#include<stdio.h>
int x,y,l,r;
int main()
{
	scanf("%d %d",&x,&y);
	l=x*x+y*y;
	for(r=1;r*r<l;r++)
		;
	puts(r*r==l||(r&1)^(x*y<0)?"black":"white");
}