#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,sz[N],mx[N],a[N],vis[N],rt;
vector<int>e[N];
void root(int u,int f)
{
	sz[u]=1,mx[u]=0;
	for(auto v:e[u])
	{
		if(v==f||vis[v])
			continue;
		root(v,u);
		if(sz[v]>mx[u])
			mx[u]=sz[v];
		sz[u]+=sz[v];
	}
	mx[u]=max(mx[u],m-sz[u]);
	if(mx[u]<mx[rt])
		rt=u;
}
void sol(int u,int d)
{
	vis[u]=1,a[u]=d;
	for(auto v:e[u])
	{
		if(vis[v])
			continue;
		rt=0,m=sz[v];
		root(v,0);
		sol(rt,d+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	m=n,mx[0]=1e9,root(1,0);
	sol(rt,0);
	for(int i=1;i<=n;i++)
		printf("%c ",a[i]+'A');
	return 0;
}