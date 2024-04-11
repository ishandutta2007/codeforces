#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=200050;
const int K=2*N;
const int M=2*N;//7*20*N;
const int L=18;
int root[N],tsz,ls[M],rs[M],mn[M],cnt[M],lzy[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;cnt[c]=se-ss+1;mn[c]=0;lzy[c]=0;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ mn[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
	cnt[c]=0;
	if(mn[ls[c]]+lzy[c]==mn[c]) cnt[c]+=cnt[ls[c]];
	if(mn[rs[c]]+lzy[c]==mn[c]) cnt[c]+=cnt[rs[c]];
}
int lid[N],rid[N],tid,dep[N],par[N][L],n;
vector<int> E[N];
void DFS(int u, int p)
{
	lid[u]=++tid;
	dep[u]=dep[p]+1;
	par[u][0]=p;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u]) if(v!=p) DFS(v,u);
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	for(int i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
int Kth(int u, int k){ for(int i=L-1;~i;i--) if((k>>i)&1) u=par[u][i];return u;}
void AddPath(int u, int v, int &root, int f)
{
    int lca=LCA(u,v);
    if(u!=lca && v!=lca)
	{
		if(lid[u]>lid[v]) swap(u,v);
		Set(root,1,n,1,lid[u]-1,f);
		Set(root,1,n,rid[u]+1,lid[v]-1,f);
		Set(root,1,n,rid[v]+1,n,f);
	}
	else
	{
		if(u!=lca) swap(v,u);
        int dif=dep[v]-dep[u];
        int tmp=Kth(v,dif-1);
        Set(root,1,n,lid[tmp],lid[v]-1,f);
        Set(root,1,n,rid[v]+1,rid[tmp],f);
	}
}
namespace DC
{
	vector<pair<int,int> > edges[K];
	int ls[K],rs[K],rt;
	void AddEdge(int &c, int ss, int se, int qs, int qe, int u, int v)
	{
		if(qs>qe || qs>se || ss>qe) return;
		if(!c) c=++tsz;
		if(qs<=ss && qe>=se){ edges[c].pb(mp(u,v));return;}
		int mid=ss+se>>1;
		AddEdge(ls[c],ss,mid,qs,qe,u,v);
		AddEdge(rs[c],mid+1,se,qs,qe,u,v);
	}
	int sol[K];
	void Solve(int c, int ss, int se, int d)
	{
		//root[d]=root[d-1];int ptsz=tsz;
		for(auto p:edges[c]) AddPath(p.first,p.second,root[d],1);
        if(ss==se) sol[ss]=cnt[root[d]]*(mn[root[d]]==0);
        else
		{
			int mid=ss+se>>1;
			Solve(ls[c],ss,mid,d+1);
			Solve(rs[c],mid+1,se,d+1);
		}
		for(auto p:edges[c]) AddPath(p.first,p.second,root[d],-1);
		//tsz=ptsz;
	}
};
map<int,int> has[N];
int main()
{
	int q,i,u,v;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	Build(root[0],1,n);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&u,&v);
		if(u>v) swap(u,v);
		if(!has[u][v])
		{
			has[u][v]=i;
			AddPath(u,v,root[0],1);
		}
		else
		{
			//DC::AddEdge(DC::rt,1,q,has[u][v],i-1,u,v);
			has[u][v]=0;
			AddPath(u,v,root[0],-1);
		}
		printf("%i\n",cnt[root[0]]*(mn[root[0]]==0));
	}
	//for(i=1;i<=n;i++) for(auto p:has[i]) if(p.second!=0) DC::AddEdge(DC::rt,1,q,p.second,q,i,p.first);
	//DC::Solve(DC::rt,1,q,1);
	//for(i=1;i<=q;i++) printf("%i\n",DC::sol[i]);
	return 0;
}