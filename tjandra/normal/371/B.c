#include<stdio.h>
typedef unsigned u;
u G(u x,u y){return y?G(y,x%y):x;}
int main()
{
	u x,y,g,r=0;
	scanf("%u%u",&x,&y);
	g=G(x,y);
	x/=g;y/=g;
	while(x%2==0)x/=2,r++;
	while(x%3==0)x/=3,r++;
	while(x%5==0)x/=5,r++;
	while(y%2==0)y/=2,r++;
	while(y%3==0)y/=3,r++;
	while(y%5==0)y/=5,r++;
	if(x>1||y>1)printf("-1\n");
	else printf("%u\n",r);
	return 0;
}