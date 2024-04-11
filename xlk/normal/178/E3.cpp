#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[2020][2020];
int b[2020][2020];
int v[2020][2020];
int c;
int x[4000020];
int y[4000020];
int sq,ci,n;
double sx,sy,r,w;
int C(int x,int y)
{
	int _=0;
	for(int i=x-2;i<x+3;i++)
		for(int j=y-2;j<y+3;j++)
			_+=a[x][y];
	return _;
}
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dfs(int i,int j)
{
	v[i][j]=1;
	x[c]=i,y[c]=j;
	c++;
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k];
		int y=j+dy[k];
		if(b[x][y]&&!v[x][y])
			dfs(x,y);
	}
}
int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d",&n);
	for(int i=3;i<n+3;i++)
		for(int j=3;j<n+3;j++)
			scanf("%d",&a[i][j]);
	for(int i=3;i<n+3;i++)
		for(int j=3;j<n+3;j++)
		{
			int t=C(i,j);
			if(t>13)
				b[i][j]=1;
			else if(t<8)
				b[i][j]=0;
			else
				b[i][j]=a[i][j];
		}
	for(int i=3;i<n+3;i++)
		for(int j=3;j<n+3;j++)
			if(b[i][j]&&!v[i][j])
			{
				c=0;
				dfs(i,j);
				if(c<100)
					continue;
				sx=sy=0;
//				for(int k=0;k<c;k++)
//					sx+=x[k],sy+=y[k];
				sx=*max_element(x,x+c)+*min_element(x,x+c);
				sy=*max_element(y,y+c)+*min_element(y,y+c);
				sx/=2;
				sy/=2;
				r=w=0;
				for(int k=0;k<c;k++)
					w=max(w,hypot(x[k]-sx,y[k]-sy));
				for(int k=0;k<c;k++)
					r+=(x[k]-sx)*(x[k]-sx)+(y[k]-sy)*(y[k]-sy);
				r/=c;
//				printf("%.10lf\n",r/w/w);
				if(r/w/w>0.40)
					ci++;
				else
					sq++;
			}
	printf("%d %d\n",ci,sq);
	return 0;
}