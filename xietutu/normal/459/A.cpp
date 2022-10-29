#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm> 
using namespace std;

int x1,x2,x3,x4;
int y1,y2,y3,y4;

void doit()
{
	int L;
	if(x1==x2)
	{
		L=y2-y1;
		x3=x4=x1+L;
		y3=y1 , y4=y2;
		printf("%d %d %d %d",x3,y3,x4,y4);
		return;
	}
	if(y1==y2)
	{
		L=x2-x1;
		y3=y4=y1+L;
		x3=x1 , x4=x2;
		printf("%d %d %d %d",x3,y3,x4,y4);
		return;
	}
	if( abs(x2-x1) != abs(y2-y1) )
	{
		printf("-1");
		return;
	}
	x3=x1 , y3=y2;
	x4=x2 , y4=y1;
	printf("%d %d %d %d",x3,y3,x4,y4);
}
int main()
{
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1>x2)
		swap(x1,x2),swap(y1,y2);
	if(x1==x2 && y1>y2)
		swap(y1,y2);
	doit();
	printf("\n");
	return 0;
}