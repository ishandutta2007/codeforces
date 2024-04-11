#include<bits/stdc++.h>
using namespace std;
const int N=2005;
vector<int>e[N],g[N],x;
int n,m,dfn[N],low[N],st[N],k,t,cnt,a[N],vis[N],dis[N],ans;
set<pair<int,int>>s;
void dfs(int u,int f)
{
	dfn[u]=low[u]=++cnt;
	st[++t]=u;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}
		else
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		k++;
		while(1)
		{
			int v=st[t];
			a[v]=k;
			t--;
			if(v==u)
				break;
			ans++;
		}
	}
}
void dfs2(int u,int f)
{
	dis[u]=dis[f]+1;
	vis[u]=1;
	x.push_back(u);
	if(g[u].size()==1)
		ans--;
	for(auto v:g[u])
		if(v!=f)
			dfs2(v,u);
}
void dfs3(int u,int f)
{
	dis[u]=dis[f]+1;
	for(auto v:g[u])
		if(v!=f)
			dfs3(v,u);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,0);
	ans+=k;
	for(int u=1;u<=n;u++)
	{
		for(auto v:e[u])
		{
			if(a[u]==a[v])
				continue;
			if(!s.count(make_pair(min(a[u],a[v]),max(a[u],a[v]))))
			{
				s.insert(make_pair(min(a[u],a[v]),max(a[u],a[v])));
				g[a[u]].push_back(a[v]);
				g[a[v]].push_back(a[u]);
			}
		}
	}
	//cout<<ans<<endl;
	for(int i=1;i<=k;i++)
	{
		if(!vis[i])
		{
			if(!g[i].size())
				continue;
			x.clear();
			dfs2(i,0);
			int x1=i,x2=i;
			for(auto u:x)
				if(dis[u]>dis[x1])
					x1=u;
			dfs3(x1,0);
			for(auto u:x)
				if(dis[u]>dis[x2])
					x2=u;
			ans-=dis[x2]-2;
			ans++;
		}
	}
	ans--;
	printf("%d\n",ans);
	return 0;
}