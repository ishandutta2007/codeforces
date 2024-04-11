#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define pb push_back
#define ll long long
const int N=50050;
const int M=17*17*N;
int ls[M],rs[M],tsz;
map<int,int> root[N];
ll sum[M],lzy[M];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll sec(int l, int r, int L, int R){ return min(R,r)-max(l,L)+1;}
void Add(int &c, int ss, int se, int qs, int qe, ll f)
{
	if(ss>qe || qs>se || qs>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ sum[c]+=f*(se-ss+1);lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	sum[c]=sum[ls[c]]+sum[rs[c]]+lzy[c]*(se-ss+1);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se || qs>qe) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe)+lzy[c]*sec(ss,se,qs,qe);
}
int sz[N],par[N],csz[N],chn[N],idx[N],dep[N];
vector<int> Head,E[N];
void DFS(int u)
{
	dep[u]=dep[par[u]]+1;sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);sz[u]+=sz[v];
	}
}
void HLD(int u)
{
	if(!chn[u]) chn[u]=Head.size(),Head.pb(u);
	idx[u]=++csz[chn[u]];
	int i,HC=0;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(sz[v]>sz[HC]) HC=v;
	}
	if(HC)
	{
		chn[HC]=chn[u];HLD(HC);
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(v!=HC) HLD(v);
		}
	}
}
ll val[N],sq[N];
void AddToRoot(int flav, int u, int f){ while(u) Add(root[flav][chn[u]],1,csz[chn[u]],1,idx[u],f),u=par[Head[chn[u]]];}
ll GetToRoot(int flav, int u){ if(!u) return 0;return Get(root[flav][chn[u]],1,csz[chn[u]],1,idx[u])+GetToRoot(flav,par[Head[chn[u]]]);}
void Add(int flav, int u)
{
	val[flav]+=dep[u];
	AddToRoot(flav,u,1);
	sq[flav]+=GetToRoot(flav,u)*2-dep[u];
}
void Del(int flav, int u)
{
	val[flav]-=dep[u];
	sq[flav]-=GetToRoot(flav,u)*2-dep[u];
	AddToRoot(flav,u,-1);
}
int col[N],cost[N];
int main()
{
	Head.pb(0);
	int n,m,q,C,u,i,t,k,w;
	scanf("%i %i %i %i",&n,&m,&q,&C);
	for(i=1;i<=n;i++) scanf("%i",&col[i]);
	for(i=2;i<=n;i++) scanf("%i",&par[i]),E[par[i]].pb(i);
	for(i=1;i<=m;i++) scanf("%i",&cost[i]);
	DFS(1);HLD(1);
	for(i=1;i<=n;i++) Add(col[i],i);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&u,&w);
			Del(col[u],u);
			col[u]=w;
			Add(col[u],u);
		}
		else
		{
			scanf("%i",&k);
			double ret=((double)n*C*C-(double)2*C*val[k]*cost[k]+(double)sq[k]*cost[k]*cost[k])/n;
			printf("%.15llf\n",ret);
		}
	}
	return 0;
}