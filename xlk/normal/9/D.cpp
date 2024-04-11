#include<stdio.h>
#include<string.h>
long long f[40][40];
long long F(int x,int y)
{
	if(x==0)
		return y>=0;
	if(~f[x][y])
		return f[x][y];
	f[x][y]=0;
	for(int i=0;i<x;i++)
		f[x][y]+=F(i,y-1)*F(x-i-1,y-1);
	return f[x][y];
}
int n,h;
int main()
{
	memset(f,-1,sizeof f);
	scanf("%d %d",&n,&h);
	printf("%I64d\n",F(n,n)-F(n,h-1));
	return 0;
}