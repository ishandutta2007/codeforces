#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
const int S=317;
map<int,int> id;
vector<int> E[N];
int a[N],t[N],cnt,c[N][2],lid[N],rid[N],tid,par[N][17],dep[N],nod[N];
ll sol;
void DFS(int u, int p)
{
	lid[u]=++tid;
	nod[tid]=u;
	par[u][0]=p;
	dep[u]=dep[p]+1;
	int i;
	for(i=1;i<17;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	rid[u]=++tid;
	nod[tid]=u;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
struct Query
{
	int l,r,t,u,i;
	Query(int a=0, int b=0, int c=0, int d=0, int e=0){ l=a,r=b,t=c,u=d,i=e;}
	bool operator < (Query b) const { return (r/S==b.r/S && l<b.l) || r/S<b.r/S;}
} Q[N];
void Swap(int &a, int &b){ a^=b,b^=a,a^=b;}
bool was[N];
void Add(int u);
void Del(int u);
void Add(int u)
{
	int y=a[u],ty=t[u];
	if(was[u]) Del(u);
	else
	{
		sol+=c[y][ty^1];
		c[y][ty]++;
		was[u]=1;
	}
}
void Del(int u)
{
	int y=a[u],ty=t[u];
	if(!was[u]) Add(u);
	else
	{
		sol-=c[y][ty^1];
		c[y][ty]--;
		was[u]=0;
	}
}
ll ans[N];
int main()
{
	int n,q,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&t[i]);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]=(id[a[i]]?id[a[i]]:id[a[i]]=++cnt);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	scanf("%i",&q);
	DFS(1,0);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&u,&v);
		if(lid[u]>lid[v]) Swap(u,v);
		int lca=LCA(u,v);
		if(lca==u) Q[i]=Query(lid[u],lid[v],0,0,i);
		else Q[i]=Query(rid[u],lid[v],1,lca,i);
	}
	sort(Q+1,Q+1+q);
	int L=1,R=0;
	for(i=1;i<=q;i++)
	{
		while(Q[i].l>L) Del(nod[L++]);
		while(Q[i].l<L) Add(nod[--L]);
		while(Q[i].r>R) Add(nod[++R]);
		while(Q[i].r<R) Del(nod[R--]);
		if(Q[i].t) Add(Q[i].u);
		ans[Q[i].i]=sol;
		if(Q[i].t) Del(Q[i].u);
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}