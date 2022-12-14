#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 200005
int fa[20][N],ans[N],n,dep[N],head[N],cnt,l,r;
int get_lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int deep=dep[x]-dep[y];
	for(int i=0;i<=17;i++)
	{
		if((1<<i)&deep)
		{
			x=fa[i][x];
		}
	}
	if(x==y)return x;
	for(int i=17;~i;i--)
	{
		if(fa[i][x]!=fa[i][y])
		{
			x=fa[i][x],y=fa[i][y];
		}
	}
	return fa[0][x];
}
int main()
{
	scanf("%d",&n);l=r=1;dep[1]=1;
	for(int i=2;i<=n;i++)
	{
		ans[i]=ans[i-1];
		scanf("%d",&fa[0][i]);dep[i]=dep[fa[0][i]]+1;
		for(int j=1;j<=17;j++)fa[j][i]=fa[j-1][fa[j-1][i]];
		int lca=get_lca(i,l);
		//printf("%d %d %d %d %d %d\n",lca,l,i,r,dep[lca],dep[i]);
		if(dep[l]+dep[i]-dep[lca]*2>ans[i])
		{
			ans[i]++;
			r=i;
		}else
		{
			lca=get_lca(i,r);
			if(dep[i]+dep[r]-dep[lca]*2>ans[i])
			{
				ans[i]++;
				l=i;
			}
		}
	}
	for(int i=2;i<=n;i++)printf("%d ",ans[i]);
	puts("");
	return 0;
}