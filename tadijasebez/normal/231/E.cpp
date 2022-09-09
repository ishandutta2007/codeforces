#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=100050;
const int mod=1e9+7;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int p[N];
void Init(int n){ for(int i=1;i<=n;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
vector<int> E[N];
vector< pair<int,int> > edges;
int par[N][17],jump[N],dep[N],mark[N];
void DFS(int u, int p)
{
	par[u][0]=p;
	dep[u]=dep[p]+1;
	int i;
	for(i=1;i<17;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	if(v==u) return v;
	return par[v][0];
}
void Prepare(int u, int p, int j)
{
	if(mark[u]) j=u;
	else jump[u]=j;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) Prepare(v,u,j);
	}
}
int sum[N];
bool vis[N];
void DFS2(int u, int p)
{
	sum[u]=sum[p];
	bool b=0;
	if(mark[u] && !vis[mark[u]]) sum[u]++,vis[mark[u]]=1,b=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS2(v,u); 
	}
	if(b) vis[mark[u]]=0;
}
int main()
{
	edges.pb(mp(69,69&-69));
	int n,m,q,u,v,i;
	scanf("%i %i",&n,&m);
	Init(n);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		if(Find(u)==Find(v)) edges.pb(mp(u,v));
		else
		{
			Union(u,v);
			E[u].pb(v);
			E[v].pb(u);
		}
	}
	DFS(1,0);
	for(i=1;i<edges.size();i++)
	{
		u=edges[i].first;
		v=edges[i].second;
		int lca=LCA(u,v);
		//printf("%i\n",lca);
		while(u!=lca)
		{
			mark[u]=i;
			jump[u]=par[lca][0];
			u=par[u][0];
		}
		while(v!=lca)
		{
			mark[v]=i;
			jump[v]=par[lca][0];
			v=par[v][0];
		}
		mark[lca]=i;
		jump[lca]=par[lca][0];
	}
	Prepare(1,0,0);
	//for(i=1;i<=n;i++) printf("%i ",jump[i]);printf("\n");
	DFS2(1,0);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&u,&v);
		int lca=LCA(u,v);
		int sol=0;
		sol=sum[u]+sum[v]-2*sum[lca];
		if(mark[lca]) sol++;
		/*int sol=0,last1=0,last2=0;
		while(dep[u]>=dep[lca])
		{
			if(mark[u]) sol++,last1=mark[u];
			u=jump[u];
		}
		while(dep[v]>=dep[lca])
		{
			if(mark[v]) sol++,last2=mark[v];
			v=jump[v];
		}
		if(last1 && last2 && last1==last2) sol--;*/
		printf("%i\n",pow(2,sol));
	}
	return 0;
}