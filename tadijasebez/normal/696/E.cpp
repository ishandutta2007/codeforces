#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=N*2;
const ll inf=4e18;
int ls[M],rs[M],tsz,root[N];
ll lzy[M];
pair<ll,int> node[M];
vector<int> Head;
void Init(){ for(int i=0;i<M;i++) node[i]=mp(inf,0);Head.pb(0);}
pair<ll,int> operator + (pair<ll,int> a, ll k){ a.first+=k;return a;} 
pair<ll,int> min(pair<ll,int> a, pair<ll,int> b){ return a>b?b:a;}
void Set(int &c, int ss, int se, int qi, pair<ll,int> girl)
{
	if(!c) c=++tsz;
	if(ss==se){ node[c]=girl+lzy[c];return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,girl);
	else Set(rs[c],mid+1,se,qi,girl);
	node[c]=min(node[ls[c]],node[rs[c]])+lzy[c];
}
void Set(int &c, int ss, int se, int qs, int qe, ll val)
{
	if(!c) c=++tsz;
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]+=val;node[c]=node[c]+val;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	node[c]=min(node[ls[c]],node[rs[c]])+lzy[c];
}
pair<ll,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return mp(inf,0);
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
ll BIT[N];
void Set(int i, ll f){ for(;i<N;i+=i&-i) BIT[i]+=f;}
void Set(int l, int r, ll f){ Set(l,f);Set(r+1,-f);}
ll Get(int i){ ll ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
vector<int> E[N];
int sz[N],csz[N],chn[N],lid[N],rid[N],tid,idx[N],par[N][17],dep[N];
void DFS(int u, int p)
{
	sz[u]=1;
	lid[u]=++tid;
	par[u][0]=p;
	dep[u]=dep[p]+1;
	int i;
	for(i=1;i<17;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),sz[u]+=sz[v];
	}
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
void HLD(int u, int p)
{
	if(!chn[u])
	{
		chn[u]=Head.size();
		Head.pb(u);
	}
	idx[u]=++csz[chn[u]];
	int HC=0,i;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && sz[v]>sz[HC]) HC=v;
	}
	if(HC)
	{
		chn[HC]=chn[u];HLD(HC,u);
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(v!=p && v!=HC) HLD(v,u);
		}
	}
}
int c[N],was[N];
vector<int> girls[N];
void PushNext(int i)
{
	pair<ll,int> girl=mp(inf,0);
	if(was[i]<girls[i].size())
	{
		girl=mp(girls[i][was[i]],girls[i][was[i]]);
		was[i]++;
	}
	Set(root[chn[i]],1,csz[chn[i]],idx[i],girl);
}
pair<ll,int> Get(int u, int lca)
{
	if(chn[u]==chn[lca]) return Get(root[chn[u]],1,csz[chn[u]],idx[lca],idx[u])+Get(lid[Head[chn[u]]]);
	else return min(Get(par[Head[chn[u]]][0],lca),Get(root[chn[u]],1,csz[chn[u]],1,idx[u])+Get(lid[Head[chn[u]]]));
}
int main()
{
	Init();
	int n,m,q,i,u,v,t,k,x;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=m;i++) scanf("%i",&c[i]),girls[c[i]].pb(i);
	DFS(1,0);HLD(1,0);
	for(i=1;i<=n;i++) PushNext(i);
	vector<int> sol;
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&u,&v,&k);
			int lca=LCA(u,v);
			sol.clear();
			while(k--)
			{
				pair<ll,int> girl=mp(inf,0);
				girl=min(girl,Get(u,lca));
				girl=min(girl,Get(v,lca));
				if(girl.second)
				{
					sol.pb(girl.second);
					PushNext(c[sol.back()]);
				}
				else break;
			}
			printf("%i ",sol.size());
			for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
			printf("\n");
		}
		else
		{
			scanf("%i %i",&u,&x);
			Set(lid[u],rid[u],x);
			if(idx[u]!=1) Set(root[chn[u]],1,csz[chn[u]],idx[u],csz[chn[u]],x);
		}
	}
	return 0;
}