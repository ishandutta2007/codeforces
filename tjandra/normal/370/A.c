#include<stdio.h>
typedef unsigned u;
int main()
{
	u a,b,x,y,s;
	scanf("%u%u%u%u",&a,&b,&x,&y);
	x=x>a?x-a:a-x;
	y=y>b?y-b:b-y;
	s=x>y?x-y:y-x;
	printf("%u %u %u\n",(x>0)+(y>0),x==0&&y==0?0:(s&1?0:1+(s>0)),x>y?x:y);
	return 0;
}