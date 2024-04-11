#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
int g[220][220];
int d[220][220];
int v[220],p[220],f[220];
int n,m,x,y,z,w;
void work(int u,int v)
{
	vector<ii>a,b;
	for(int i=1;i<=n;i++)
		a.push_back(ii(d[u][i],d[v][i]));
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
	{
		while(b.size()&&b.back().Y<=a[i].Y)
			b.pop_back();
		b.push_back(a[i]);	
	}
	int d=0x3f3f3f3f,q;
	if(b.size()==1)
		if(b[0].X<b[0].Y)
		{
			q=0;
			d=2*b[0].X;
		}
		else
		{
			q=g[u][v];
			d=2*b[0].Y;
		}
	for(int i=1;i<b.size();i++)
		if(d>g[u][v]+b[i-1].X+b[i].Y)
		{
			q=g[u][v]-b[i-1].X+b[i].Y>>1;
			d=g[u][v]+b[i-1].X+b[i].Y;
		}
	if(d<z)
		z=d,w=q;
}
int main()
{
	scanf("%d %d",&n,&m);
	memset(g,0x3f,sizeof g);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		z*=2;
		g[x][y]=g[y][x]=min(g[x][y],z);
	}
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	memcpy(d,g,sizeof d);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	z=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(g[i][j]<0x3f3f3f3f)
				work(i,j);
	printf("%.6f\n",z/4.);
	return 0;
}