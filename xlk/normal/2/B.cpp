#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define fo(i,n) for(int i=1;i<=n;i++)
int a[1020][1020];
int f[1020][1020];
int g[1020][1020];
int p[1020][1020];
int q[1020][1020];
int n;
void pt(int f[1020][1020],int p[1020][1020],int x,int y)
{
	if(x==1&&y==1)
		return;
	if(f[x][y-1]+p[x][y]==f[x][y])
		pt(f,p,x,y-1),printf("R");
	else
		pt(f,p,x-1,y),printf("D");
}
int get(int x,int y)
{
	if(!x)
		return 0xffffff;
	int _=0;
	for(;x%y==0;x/=y)
		_++;
	return _;
}
int z,zx,zy;
int main()
{
	scanf("%d",&n);
	fo(i,n)
		fo(j,n)
		{
			scanf("%d",a[i]+j);
			if(!a[i][j])
				z=1,zx=i,zy=j;
		}
	memset(f,1,sizeof f);
	memset(g,1,sizeof g);
	f[0][1]=g[0][1]=0;
	fo(i,n)
		fo(j,n)
		{
			f[i][j]=min(f[i-1][j],f[i][j-1]);
			p[i][j]=get(a[i][j],2);
			f[i][j]+=p[i][j];
			g[i][j]=min(g[i-1][j],g[i][j-1]);
			q[i][j]=get(a[i][j],5);
			g[i][j]+=q[i][j];
		}
	if(z&&min(f[n][n],g[n][n])>1)
	{
		puts("1");
		cout<<string(zx-1,'D')<<string(n-1,'R')<<string(n-zx,'D')<<endl;
	}
	else
	{
		printf("%d\n",min(f[n][n],g[n][n]));
		if(f[n][n]>g[n][n])
			pt(g,q,n,n);
		else
			pt(f,p,n,n);
	}
	return 0;
}