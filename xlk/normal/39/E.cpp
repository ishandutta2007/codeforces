#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int f[32020][40],n,x,y;
char s[3][20]={"Stas","Missing","Masha"};
int F(int x,int y)
{
	int &t=f[x][y];
	if(~t)
		return t;
	if(pow(x,y)+.5>n)
		return 2;
	if(y>31)
		return 1;
	if(y==1&&x*x>=n)
		return t=(n-x+1)%2*2;
	return t=2-min(F(x+1,y),F(x,y+1));
}
int main()
{
	memset(f,-1,sizeof f);
	scanf("%d %d %d",&x,&y,&n);
	printf("%s\n",s[F(x,y)]);
	return 0;
}