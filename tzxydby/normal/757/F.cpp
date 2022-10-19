#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,s,dep[N],fa[N][20],dg[N],q[N],bg,ed,ans[N],p[N],mx;
vector<pair<int,int>>e[N];
vector<int>g[N],h[N];
long long d[N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
int lca(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=17;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=17;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}	
	for(int i=1;i<=n;i++)
		d[i]=(1ll<<60);
	d[s]=0;
	pq.emplace(0,s);
	while(!pq.empty())
	{
		int u=pq.top().second;
		long long ds=pq.top().first;
		pq.pop();
		if(d[u]!=ds)
			continue;
		for(auto [v,w]:e[u])
		{
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				pq.emplace(d[v],v);
			}
		}
	}
	for(int u=1;u<=n;u++)
		for(auto [v,w]:e[u])
			if(d[v]==d[u]+w)
				g[u].push_back(v),h[v].push_back(u),dg[v]++;
	q[ed++]=s;
	while(bg<ed)
	{
		int u=q[bg++];
		if(u!=s)
		{
			p[u]=-1;
			for(auto v:h[u])
			{
				if(p[u]==-1)
					p[u]=v;
				else
					p[u]=lca(p[u],v);
			}
			fa[u][0]=p[u],dep[u]=dep[p[u]]+1;
			ans[p[u]]++;
			for(int j=1;j<=17;j++)
				fa[u][j]=fa[fa[u][j-1]][j-1];
		}
		for(auto v:g[u])
		{
			dg[v]--;
			if(!dg[v])
				q[ed++]=v;
		}
	}
	for(int i=ed-1;i;i--)
		ans[p[q[i]]]+=ans[q[i]];
	for(int i=1;i<=n;i++)
		if(i!=s&&d[i]<(1ll<<60))
			mx=max(mx,ans[i]+1);
	printf("%d\n",mx);
	return 0;
}