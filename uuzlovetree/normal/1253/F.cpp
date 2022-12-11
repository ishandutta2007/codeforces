#include<bits/stdc++.h>
#define ll long long
#define maxn 600005
using namespace std;
int n,m,k,q;
struct Edg
{
	int u,v;
	ll w;
}e[maxn];
bool operator < (Edg A,Edg B){return A.w<B.w;}
int fa[maxn];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
namespace SSSP
{
	vector< pair<ll,int> > g[maxn];
	void addedge(int u,int v,ll w)
	{
		g[u].push_back(make_pair(w,v));
		g[v].push_back(make_pair(w,u));
	}
	priority_queue< pair<ll,int> > q;
	ll dis[maxn];
	bool used[maxn];
	void dijkstra()
	{
		for(int i=1;i<=n;++i)dis[i]=(ll)1e15;
		memset(used,0,sizeof(used));
		for(int i=1;i<=k;++i)q.push(make_pair(0,i)),dis[i]=0;
		while(!q.empty())
		{
			int u=q.top().second;q.pop();
			if(used[u])continue;
			used[u]=1;
			for(auto x:g[u])
			{
				int v=x.second;ll w=x.first;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					q.push(make_pair(-dis[v],v)); 
				}
			}
		}
	}
}
namespace Tree
{
	vector< pair<ll,int> > g[maxn];
	void addedge(int u,int v,ll w)
	{
		g[u].push_back(make_pair(w,v));
		g[v].push_back(make_pair(w,u));
	}
	int d[maxn],anc[maxn][20];
	ll maxv[maxn][20];
	void dfs(int u,int f)
	{
		for(auto x:g[u])
		{
			int v=x.second;ll w=x.first;
			if(v==f)continue;
			d[v]=d[u]+1,anc[v][0]=u,maxv[v][0]=w;
			dfs(v,u);
		}
	}
	void init()
	{
		for(int j=1;j<=18;++j)
			for(int i=1;i<=n;++i)
			{
				anc[i][j]=anc[anc[i][j-1]][j-1];
				maxv[i][j]=max(maxv[i][j-1],maxv[anc[i][j-1]][j-1]);
			}
	}
	ll query(int u,int v)
	{
		ll ans=0;
		if(d[u]<d[v])swap(u,v);
		for(int i=18;i>=0;--i)if(d[anc[u][i]]>=d[v])
		{
			ans=max(ans,maxv[u][i]);
			u=anc[u][i];
		}
		if(u==v)return ans;
		for(int i=18;i>=0;--i)if(anc[u][i]!=anc[v][i])
		{
			ans=max(ans,maxv[u][i]);
			ans=max(ans,maxv[v][i]);
			u=anc[u][i],v=anc[v][i];
		}
		ans=max(ans,max(maxv[u][0],maxv[v][0]));
		return ans;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%I64d",&e[i].u,&e[i].v,&e[i].w);
		SSSP::addedge(e[i].u,e[i].v,e[i].w);
	}
	SSSP::dijkstra();
	for(int i=1;i<=m;++i)e[i].w+=SSSP::dis[e[i].u]+SSSP::dis[e[i].v];
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		Tree::addedge(e[i].u,e[i].v,e[i].w);
		fa[u]=v;
	}
	Tree::dfs(1,0);
	Tree::init();
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%I64d\n",Tree::query(u,v));
	}
}