#include<stdio.h>
int n,x,y;
long long sx,sy,zx,zy;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x,&y),zx+=x*x,zy+=y*y,sx+=x,sy+=y;
	printf("%I64d",n*(zx+zy)-sx*sx-sy*sy);
	return 0;
}