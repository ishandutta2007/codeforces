#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=1000050;
vector<int> E[N];
int dep[N],par[N][20],lid[N],rid[N],tid;
void DFS(int u, int p)
{
	lid[u]=++tid;
	dep[u]=dep[p]+1;
	par[u][0]=p;
	int i;
	for(i=1;i<20;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=19;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=19;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int Dist(int u, int v){ return dep[u]+dep[v]-2*dep[LCA(u,v)]+1;}
struct BIT
{
	int sum[N];
	BIT(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} Tree;
bool was[N];
void Mark(int u, int v)
{
	int lca=v,i;//LCA(u,v),i;
	for(i=u;i!=lca;i=par[i][0]) was[i]=1,Tree.Set(lid[i],1);
	//for(i=v;i!=lac;i=par[i][0]) was[i]=1,Tree.Set(lid[i],1);
	//was[lca]=1;Tree.Set(lid[lca],1);
}
int Find(int u)
{
	int i;
	for(i=19;~i;i--) if(par[u][i] && Tree.Get(lid[par[u][i]],rid[par[u][i]])==0) u=par[u][i];
	if(Tree.Get(lid[u],rid[u])) return u;
	return par[u][0];
}
int main()
{
	int n,i,u,v,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(n,0);
	was[n]=1;Tree.Set(lid[n],1);
	k=n-k-1;
	for(i=n-1;i;i--)
	{
		if(!was[i])
		{
			v=Find(i);
			//printf(":D\n");
			if(dep[i]-dep[v]<=k)
			{
				k-=dep[i]-dep[v];
				Mark(i,v);
			}
		}
	}
	//vector<int> sol;
	for(i=1;i<=n;i++) if(!was[i]) printf("%i ",i);
	printf("\n");
	return 0;
}