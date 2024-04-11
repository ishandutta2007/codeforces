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
double sx,sy,r;
int C(int x,int y)
{
	int _=0;
	for(int i=x-2;i<x+3;i++)
		for(int j=y-2;j<y+3;j++)
			_+=a[x][y];
	return _;
}
int dfs(int i,int j)
{
	v[i][j]=1;
	x[c]=i,y[c]=j;
	c++;
	for(int x=i-1;x<i+2;x++)
		for(int y=j-1;y<j+2;y++)
			if(b[x][y]&&!v[x][y])
				dfs(x,y);
}
int main()
{
	scanf("%d",&n);
	for(int i=3;i<n+3;i++)
		for(int j=3;j<n+3;j++)
			scanf("%d",&a[i][j]);
	for(int i=3;i<n+3;i++)
		for(int j=3;j<n+3;j++)
		{
//			int t=C(i,j);
//			if(t>15)
//				b[i][j]=1;
//			else if(t<10)
//				b[i][j]=0;
//			else
				b[i][j]=a[i][j];
		}
	for(int i=3;i<n+3;i++)
		for(int j=3;j<n+3;j++)
			if(b[i][j]&&!v[i][j])
			{
				c=0;
				dfs(i,j);
				sx=sy=0;
				for(int k=0;k<c;k++)
					sx+=x[k],sy+=y[k];
				sx/=c;
				sy/=c;
				r=0;
				for(int k=0;k<c;k++)
					r+=(x[k]-sx)*(x[k]-sx)+(y[k]-sy)*(y[k]-sy);
				if(c*c/r>6.1)
					ci++;
				else
					sq++;
			}
	printf("%d %d\n",ci,sq);
	return 0;
}