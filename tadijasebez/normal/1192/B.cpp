#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int L=20;
vector<int> E[N];
vector<pair<int,ll>> G[N];
void AddEdge(int u, int v, ll w)
{
	E[u].pb(v);
	E[v].pb(u);
	G[u].pb({v,w});
	G[v].pb({u,w});
}
ll Z[N];
struct SegmentTree
{
	vector<ll> mx,lzy;
	int n;
	SegmentTree(){}
	void Build(int c, int ss, int se)
	{
		if(ss==se){ mx[c]=Z[ss];return;}
		int mid=ss+se>>1;
		Build(c<<1,ss,mid);
		Build(c<<1|1,mid+1,se);
		mx[c]=max(mx[c<<1],mx[c<<1|1]);
	}
	void init(int _n)
	{
		n=_n;mx.resize(n*4+1);
		lzy.resize(n*4+1);
		Build(1,1,n);
	}
	void Set(int qs, int qe, ll f, int c, int ss, int se)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(qs<=ss && qe>=se){ mx[c]+=f;lzy[c]+=f;return;}
		int mid=ss+se>>1;
		Set(qs,qe,f,c<<1,ss,mid);
		Set(qs,qe,f,c<<1|1,mid+1,se);
		mx[c]=max(mx[c<<1],mx[c<<1|1])+lzy[c];
	}
	void Set(int qs, int qe, ll f){ Set(qs,qe,f,1,1,n);}
	ll Get(){ return mx[1];}
} ST[N][L];
bool was[N];
int sz[N];
void DFSSZ(int u, int p){ sz[u]=1;for(int v:E[u]) if(v!=p && !was[v]) DFSSZ(v,u),sz[u]+=sz[v];}
int Find(int u, int p, int n){ for(int v:E[u]) if(v!=p && !was[v] && sz[v]>n/2) return Find(v,u,n);return u;}
int Find(int u){ DFSSZ(u,0);return Find(u,0,sz[u]);}
int cen_par[N],cen_dep[N],cen_root;
int dep[N][L],lid[N][L],rid[N][L],tid,my_sub[N][L],my_lvl[N][L];
vector<int> bck;
void Build(int u, int p, int sub, int lvl, ll d)
{
	dep[u][lvl]=d;
	lid[u][lvl]=++tid;
	my_sub[u][lvl]=sub;
	my_lvl[u][lvl]=my_lvl[p][lvl]+1;
	Z[tid]=d;
	for(auto e:G[u]) if(!was[e.first] && e.first!=p)
	{
		int v=e.first;
		ll w=e.second;
		Build(v,u,sub,lvl,d+w);
	}
	rid[u][lvl]=tid;
}
multiset<ll> sbs[N],all;
ll Ans(int u)
{
	if(sbs[u].empty()) return 0;
	else if(sbs[u].size()==1) return *sbs[u].begin();
	auto it=--sbs[u].end();
	ll ans=*it;
	it--;ans+=*it;
	return ans;
}
ll Answer(){ return *all.rbegin();}
int Decompose(int u, int d)
{
	u=Find(u);was[u]=1;cen_dep[u]=d;
	//printf("CEN:%i cen_dep:%i\n",u,d);
	for(auto e:G[u]) if(!was[e.first])
	{
		int v=e.first;
		ll w=e.second;
		tid=0;
		Build(v,u,v,d,w);
		ST[v][d].init(tid);
		sbs[u].insert(ST[v][d].Get());
	}
	all.insert(Ans(u));
	for(int v:E[u]) if(!was[v])
	{
		int t=Decompose(v,d+1);
		cen_par[t]=u;
	}
	return u;
}
void Upd(int u, int v, ll dif)
{
	if(cen_dep[u]>cen_dep[v]) swap(u,v);
	for(int i=u;i;i=cen_par[i])
	{
		int d=cen_dep[i];
		int sub=my_sub[v][d];
		all.erase(all.find(Ans(i)));
		sbs[i].erase(sbs[i].find(ST[sub][d].Get()));
		/*if(cen_dep[i]==1)
		{
			printf("PRE i:%i sub:%i ST[sub][d].Get()=%lld\n",i,sub,ST[sub][d].Get());
		}*/
		if(i==u || my_lvl[v][d]>my_lvl[u][d]) ST[sub][d].Set(lid[v][d],rid[v][d],dif);
		else ST[sub][d].Set(lid[u][d],rid[u][d],dif);
		/*if(cen_dep[i]==1)
		{
			printf("POSLE i:%i sub:%i ST[sub][d].Get()=%lld\n",i,sub,ST[sub][d].Get());
		}*/
		sbs[i].insert(ST[sub][d].Get());
		/*if(cen_dep[i]==1)
		{
			for(ll z:sbs[i]) printf("%lld ",z);printf("\n");
		}*/
		all.insert(Ans(i));
	}
}
int u[N],v[N];
ll w[N];
int main()
{
	int n,q;ll W;
	scanf("%i %i %lld",&n,&q,&W);
	for(int i=1;i<n;i++)
	{
		scanf("%i %i %lld",&u[i],&v[i],&w[i]);
		AddEdge(u[i],v[i],w[i]);
	}
	ll last=0;
	cen_root=Decompose(1,1);
	while(q--)
	{
		int d;ll e;
		scanf("%i %lld",&d,&e);
		d=((ll)d+last)%(n-1)+1;
		e=((ll)e+last)%W;
		//printf("real:%i (%i - %i) %lld\n",d,u[d],v[d],e);
        ll dif=e-w[d];
        Upd(u[d],v[d],dif);
		last=Answer();
        printf("%lld\n",last);
        w[d]=e;
	}
	return 0;
}