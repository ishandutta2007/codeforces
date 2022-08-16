#include<stdio.h>
#include<math.h>
typedef unsigned u;
typedef double d;
int main()
{
	u x,y,i,j,k;d X,Y;
	scanf("%u%u",&x,&y);X=(d)x;Y=(d)y;
	if(!x)
	{
		printf("%u %u\n%u %u\n%u %u\n%u %u\n",0,1,0,y,0,0,0,y-1);
		return 0;
	}
	if(!y)
	{
		printf("%u %u\n%u %u\n%u %u\n%u %u\n",1,0,x,0,0,0,x-1,0);
		return 0;
	}
	if(y<x)
	{
		if(hypot(X,Y)+X>2.0*hypot(X,Y-1.0))
		printf("%u %u\n%u %u\n%u %u\n%u %u\n",0,0,x,y,0,y,x,0);
		else printf("%u %u\n%u %u\n%u %u\n%u %u\n",0,1,x,y,0,0,x,y-1);
	}
	else
	{
		if(hypot(X,Y)+Y>2.0*hypot(X-1.0,Y))
		printf("%u %u\n%u %u\n%u %u\n%u %u\n",0,0,x,y,x,0,0,y);
		else printf("%u %u\n%u %u\n%u %u\n%u %u\n",1,0,x,y,0,0,x-1,y);
	}
	return 0;
}