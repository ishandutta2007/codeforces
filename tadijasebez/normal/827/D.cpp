#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=200050;
const int M=2*N;
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int p[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
int x[M],ls[M],rs[M],clock,root[N];
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(qs>qe) return;
	if(ss>qe || qs>se) return;
	if(!c) c=++clock,x[c]=inf;
	if(qs<=ss && qe>=se){ x[c]=min(x[c],val);return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return min(x[c],Get(ls[c],ss,mid,qi));
	else return min(x[c],Get(rs[c],mid+1,se,qi));
}
int dep[N],par[N][18],rmq[N][18],sz[N],edg[N];
vector<pair<int,pair<int,int> > > E[N];
void DFS(int u, int p, int w, int e)
{
	par[u][0]=p;
	rmq[u][0]=w;
	dep[u]=dep[p]+1;
	edg[u]=e;
	sz[u]=1;
	int i;
	for(i=1;i<18;i++)
	{
		par[u][i]=par[par[u][i-1]][i-1];
		rmq[u][i]=max(rmq[u][i-1],rmq[par[u][i-1]][i-1]);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p) DFS(v,u,E[u][i].second.first,E[u][i].second.second),sz[u]+=sz[v];
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=17;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=17;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
vector<int> Head;
int csz[N],Chain[N],idx[N];
void HLD(int u, int p)
{
	if(!Chain[u])
	{
		Chain[u]=Head.size();
		Head.push_back(u);
	}
	idx[u]=++csz[Chain[u]];
	int i,HC=0;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && sz[v]>sz[HC]) HC=v;
	}
	if(HC)
	{
		Chain[HC]=Chain[u];
		HLD(HC,u);
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i].first;
			if(v!=p && v!=HC) HLD(v,u);
		}
	}
}
vector<pair<pair<int,int> ,pair<int,int> > > edges;
vector<int> unused;
int sol[N];
int main()
{
	x[0]=inf;
	Head.pb(69&-69);
	int n,m,i,u,v,w,j,k;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		edges.pb(mp(mp(w,i),mp(u,v)));
	}
	Init();
	sort(edges.begin(),edges.end());
	for(i=0;i<m;i++)
	{
		u=edges[i].second.first;
		v=edges[i].second.second;
		w=edges[i].first.first;
		j=edges[i].first.second;
		if(Find(u)==Find(v))
		{
			unused.pb(i);
		}
		else
		{
			Union(u,v);
			E[u].pb(mp(v,mp(w,j)));
			E[v].pb(mp(u,mp(w,j)));
		}
	}
	DFS(1,0,0,0);
	HLD(1,0);
	for(i=0;i<unused.size();i++)
	{
		int id=unused[i];
		u=edges[id].second.first;
		v=edges[id].second.second;
		w=edges[id].first.first;
		j=edges[id].first.second;
		int lca=LCA(u,v);
		int Max=0;
		int tmp=u;
		for(k=17;~k;k--) if(dep[par[tmp][k]]>=dep[lca]) Max=max(Max,rmq[tmp][k]),tmp=par[tmp][k];
		tmp=v;
		for(k=17;~k;k--) if(dep[par[tmp][k]]>=dep[lca]) Max=max(Max,rmq[tmp][k]),tmp=par[tmp][k];
		sol[j]=Max-1;
		tmp=u;
		while(Chain[tmp]!=Chain[lca])
		{
			Set(root[Chain[tmp]],1,csz[Chain[tmp]],1,idx[tmp],w);
			tmp=par[Head[Chain[tmp]]][0];
		}
		Set(root[Chain[tmp]],1,csz[Chain[tmp]],idx[lca]+1,idx[tmp],w);
		tmp=v;
		while(Chain[tmp]!=Chain[lca])
		{
			Set(root[Chain[tmp]],1,csz[Chain[tmp]],1,idx[tmp],w);
			tmp=par[Head[Chain[tmp]]][0];
		}
		Set(root[Chain[tmp]],1,csz[Chain[tmp]],idx[lca]+1,idx[tmp],w);
	}
	for(i=2;i<=n;i++) sol[edg[i]]=Get(root[Chain[i]],1,csz[Chain[i]],idx[i])-1;
	for(i=1;i<=m;i++)
	{
		if(sol[i]==inf-1) printf("-1 ");
		else printf("%i ",sol[i]);
	}
	return 0;
}