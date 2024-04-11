#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const int L=18;
const ll inf=9e18;
vector<pair<int,int>> E[N];
int par[N][L],sz[N],dep[N],ord[N],osz;
ll dist[N];
int LCA(int u, int v)
{
	if(u==-1) return v;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int main()
{
	int n,m,s,i,j,u,v,w;
	scanf("%i %i %i",&n,&m,&s);
	while(m--) scanf("%i %i %i",&u,&v,&w),E[u].pb({v,w}),E[v].pb({u,w});
    for(i=1;i<=n;i++) dist[i]=inf;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(pq.size())
	{
		u=pq.top().second;
		ll d=-pq.top().first;
		pq.pop();
		if(d!=dist[u]) continue;
		ord[++osz]=u;
		for(auto e:E[u]) if(dist[e.first]>dist[u]+e.second)
		{
			dist[e.first]=dist[u]+e.second;
			pq.push({-dist[e.first],e.first});
		}
	}
	for(j=2;j<=osz;j++)
	{
		i=ord[j];
		int lca=-1;
		for(auto e:E[i]) if(dist[e.first]+e.second==dist[i]) lca=LCA(lca,e.first);
		par[i][0]=lca;
		dep[i]=dep[lca]+1;
		for(int k=1;k<L;k++) par[i][k]=par[par[i][k-1]][k-1];
		sz[i]=1;
	}
	int ans=0;
	for(j=osz;j>1;j--) i=ord[j],ans=max(ans,sz[i]),sz[par[i][0]]+=sz[i];
	printf("%i\n",ans);
	return 0;
}