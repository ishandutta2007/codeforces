#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=300050;
const ll inf=9e18;
vector<pair<ll,ll> > E[N];
ll par[N],dist[N],dep[N],sz[N];
void DFS1(ll u, ll p)
{
	par[u]=p;
	for(ll i=0;i<E[u].size();i++)
	{
		ll v=E[u][i].first;
		ll w=E[u][i].second;
		if(v!=p)
		{
			dist[v]=dist[u]+w;
			DFS1(v,u);
		}
	}
}
bool on[N];
void DFS2(ll u, ll p)
{
	sz[u]=1;
	for(ll i=0;i<E[u].size();i++)
	{
		ll v=E[u][i].first;
		ll w=E[u][i].second;
		if(v!=p && !on[v])
		{
			DFS2(v,u);
			sz[u]+=sz[v];
			dep[u]=w;
		}
	}
}
int main()
{
	ll n,m,u,v,w,i,x;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<n;i++) scanf("%lld %lld %lld",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	DFS1(1,0);
	for(u=n;u;u=par[u]) on[u]=1;
	for(u=n;u;u=par[u]) DFS2(u,0);
	bool best=0;
	ll sol=-inf,msz=-inf,pmsz=-inf;
	v=0;
	for(u=n;u;u=par[u])
	{
		if(sz[u]>2) best=1;
		else
		{
			if(!dep[u] && !dep[v]) sol=max(sol,dist[u]+dep[u]+pmsz);
			else sol=max(sol,dist[u]+dep[u]+msz);
			pmsz=msz;
			msz=max(msz,dist[n]-dist[u]+dep[u]);
		}
		v=u;
		//printf("%lld\n",u);
	}
	while(m--)
	{
		scanf("%lld",&x);
		if(best) printf("%lld\n",dist[n]);
		else printf("%lld\n",min(dist[n],sol+x));
	}
	return 0;
}