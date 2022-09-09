#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void MustBe(bool ok)
{
	if(!ok)
	{
		printf(":D");
		exit(0);
	}
}
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
const int M=3*N;
const int inf=1e9+7;
ll min(ll a, ll b){ return a>b?b:a;}
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],clock,root[N];
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(!c) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int p[N];
void Init(int n){ for(int i=1;i<=n;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
vector< pair<int,int> > E[N];
vector<int> edges,Head;
int sz[N],CS[N],Index[N],Chain[N],time,dep[N],par[N][19],edg[N];
void DFS(int u, int p)
{
	dep[u]=dep[p]+1;
	par[u][0]=p;
	sz[u]=1;
	int i;
	for(i=1;i<19;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int e=E[u][i].second;
		if(v!=p) DFS(v,u),edg[v]=e,sz[u]+=sz[v];
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=18;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=18;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	if(u==v) return v;
	return par[v][0];
}
void HLD(int u, int p)
{
	if(!Chain[u])
	{
		Chain[u]=Head.size();
		Head.pb(u);
		time=0;
	}
	Index[u]=++time;
	CS[Chain[u]]=time;
	int HC=0,i;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && sz[HC]<sz[v]) HC=v;
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
int u[N],v[N],w[N],c[N];
vector<int> es;
bool comp(int a, int b){ return w[a]<w[b];}
int main()
{
	Head.pb(69&-69);
	int n,m,i;
	scanf("%i %i",&n,&m);
	Init(n);
	for(i=1;i<=m;i++) scanf("%i",&w[i]);
	for(i=1;i<=m;i++) scanf("%i",&c[i]);
	for(i=1;i<=m;i++) scanf("%i %i",&u[i],&v[i]);
	for(i=1;i<=m;i++) es.pb(i);
	int s;
	scanf("%i",&s);
	sort(es.begin(),es.end(),comp);
	ll MST=0;
	int Min=inf;
	for(i=0;i<es.size();i++)
	{
		int a=u[es[i]];
		int b=v[es[i]];
		if(Find(a)==Find(b))
		{
			edges.pb(es[i]);
		}
		else
		{
			MST+=w[es[i]];
			E[a].pb(mp(b,es[i]));
			E[b].pb(mp(a,es[i]));
			Union(a,b);
			Min=min(Min,c[es[i]]);
		}
	}
	DFS(1,0);
	HLD(1,0);
	for(i=2;i<=n;i++)
	{
		MustBe(Chain[i] && CS[Chain[i]] && Index[i]);
		Set(root[Chain[i]],1,CS[Chain[i]],Index[i],w[edg[i]]);
	}
	ll sol=MST-s/Min;
	int taj=-1;
	//printf("%lld\n",sol);
	for(i=0;i<edges.size();i++)
	{
		int a=u[edges[i]];
		int b=v[edges[i]];
		int lca=LCA(a,b);
		ll ans=MST;
		int Max=0;
		while(Chain[a]!=Chain[lca])
		{
			Max=max(Max,Get(root[Chain[a]],1,CS[Chain[a]],1,Index[a]));
			a=par[Head[Chain[a]]][0];
		}
		Max=max(Max,Get(root[Chain[a]],1,CS[Chain[a]],Index[lca]+1,Index[a]));
		while(Chain[b]!=Chain[lca])
		{
			Max=max(Max,Get(root[Chain[b]],1,CS[Chain[b]],1,Index[b]));
			b=par[Head[Chain[b]]][0];
		}
		Max=max(Max,Get(root[Chain[b]],1,CS[Chain[b]],Index[lca]+1,Index[b]));
		ans-=Max;
		ans+=w[edges[i]];
		ans-=(ll)s/c[edges[i]];
		//printf("%i %lld\n",edges[i],ans);
		sol=min(sol,ans);
		if(sol==ans) taj=i;
	}
	printf("%lld\n",sol);
	if(~taj)
	{
		int banned=0;
		int a=u[edges[taj]];
		int b=v[edges[taj]];
		int lca=LCA(a,b);
		int Max=0;
		while(a!=lca)
		{
			if(w[edg[a]]>Max)
			{
				banned=edg[a];
				Max=w[edg[a]];
			}
			a=par[a][0];
		}
		while(b!=lca)
		{
			if(w[edg[b]]>Max)
			{
				banned=edg[b];
				Max=w[edg[b]];
			}
			b=par[b][0];
		}
		for(i=2;i<=n;i++)
		{
			if(banned==edg[i]) continue;
			printf("%i %i\n",edg[i],w[edg[i]]);
		}
		printf("%i %i\n",edges[taj],w[edges[taj]]-s/c[edges[taj]]);
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			printf("%i ",edg[i]);
			if(c[edg[i]]==Min) printf("%i\n",w[edg[i]]-s/Min),Min=-inf;
			else printf("%i\n",w[edg[i]]);
		}
	}
	return 0;
}