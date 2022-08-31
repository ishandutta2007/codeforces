#include<stdio.h>
#define inf 1e12
typedef unsigned u;
typedef double d;
int main()
{
	u x,y,j,k;d a,b;a=b=inf;
	scanf("%u%u",&x,&y);
	if(x<y){printf("-1\n");return 0;}
	j=x+y;
	k=j/(y<<1);
	a=((d)j)/((d)(k<<1));
	j=x-y;
	k=j/(y<<1);
	if(k)b=((d)j)/((d)(k<<1));
	printf("%.12lf\n",a>b?b:a);
	return 0;
}