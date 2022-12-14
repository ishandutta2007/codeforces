#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
int a[11][N],p[11][N],n,m,vis[11][N],now[11];ll ans;
bool check()
{
	if(now[1]>=n)return 0;
	int x=a[1][now[1]+1];
	for(int i=2;i<=m;i++)if(a[i][now[i]+1]!=x)return 0;
	return 1;
}
// void update(){for(int i=1;i<=m;i++)now[i]++;}
int find(int j,int x){return vis[j][x]==x?x:vis[j][x]=find(j,vis[j][x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),p[i][a[i][j]]=j,vis[i][j]=j;
		vis[i][n+1]=n+1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)now[j]=find(j,p[j][i]);
		for(;check();)
		{
			for(int j=1;j<=m;j++)vis[j][now[j]]=now[j]+1;
			for(int j=1;j<=m;j++)now[j]=find(j,vis[j][now[j]]);
		}
	}
	for(int i=1;i<=n;i=find(1,vis[1][i])+1)
	{
		ans+=(ll)(find(1,vis[1][i])-i+1)*(find(1,vis[1][i])-i+2);
	}
	printf("%lld\n",ans>>1);
}