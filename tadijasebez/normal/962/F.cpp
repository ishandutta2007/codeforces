#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=100050;
vector<pair<int,int> > E[N];
int p[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
vector<pair<int,pair<int,int> > > edges;
bool vis[N];
int par[N][18],dep[N],edg[N];
ll cnt[N][18];
void DFS(int u, int p, int e)
{
	vis[u]=1;
	par[u][0]=p;
	dep[u]=dep[p]+1;
	edg[u]=e;
	int i;
	for(i=1;i<18;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int ed=E[u][i].second;
		if(v!=p) DFS(v,u,ed);
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
void Add(int u, int v)
{
	int lca=LCA(u,v),i;
	for(i=17;~i;i--)
	{
		if(dep[lca]<=dep[par[u][i]])
		{
			//printf("Add:%i %i\n",u,i);
			cnt[u][i]++;
			u=par[u][i];
		}
	}
	for(i=17;~i;i--)
	{
		if(dep[lca]<=dep[par[v][i]])
		{
			//printf("Add:%i %i\n",v,i);
			cnt[v][i]++;
			v=par[v][i];
		}
	}
}
void PushDown(int n)
{
	int i,u;
	for(i=17;i;i--)
	{
		for(u=1;u<=n;u++)
		{
			//if(cnt[u][i]) printf("cnt:%i %i %i\n",u,i,cnt[u][i]);
			cnt[u][i-1]+=cnt[u][i];
			if(par[u][i-1]) cnt[par[u][i-1]][i-1]+=cnt[u][i];
		}
	}
}
void PushUp(int n)
{
	int i,u;
	for(i=1;i<18;i++)
	{
		for(u=1;u<=n;u++)
		{
			cnt[u][i]=cnt[u][i-1]+cnt[par[u][i-1]][i-1];
		}
	}
}
int bad[N];
void DFS(int u, int p)
{
	if(cnt[u][0]==1) bad[u]=bad[p];
	else bad[u]=bad[p]+1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p) DFS(v,u);
	}
}
vector<int> sol;
bool Check(int u, int v)
{
	int lca=LCA(u,v);
	int take=bad[u]+bad[v]-2*bad[lca];
	return take==0;
	/*int dist=dep[u]+dep[v]-2*dep[lca];
	ll take=0;
	for(int i=17;~i;i--)
	{
		if(dep[lca]<=dep[par[u][i]])
		{
			take+=cnt[u][i];
			u=par[u][i];
		}
		if(dep[lca]<=dep[par[v][i]])
		{
			take+=cnt[v][i];
			v=par[v][i];
		}
	}
	return take==dist;*/
}
void InitCnt(int n){ for(int i=17;~i;i--) for(int j=1;j<=n;j++) cnt[j][i]=0;}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	Init();
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		if(Find(u)!=Find(v))
		{
			Union(u,v);
			E[u].pb(mp(v,i));
			E[v].pb(mp(u,i));
		}
		else edges.pb(mp(i,mp(u,v)));
	}
	for(i=1;i<=n;i++) if(!vis[i]) DFS(i,0,0);
	for(i=0;i<edges.size();i++)
	{
		Add(edges[i].second.first,edges[i].second.second);
	}
	PushDown(n);
	/*for(i=1;i<=n;i++)
	{
		printf("%i %i %i\n",i,edg[i],cnt[i][0]);
		if(edg[i] && cnt[i][0]==1)
		{
			sol.pb(edg[i]);
		}
	}*/
	//PushUp(n);
	for(i=1;i<=n;i++) if(par[i][0]==0) DFS(i,0);
	InitCnt(n);
	for(i=0;i<edges.size();i++)
	{
		if(Check(edges[i].second.first,edges[i].second.second))
		{
			sol.pb(edges[i].first);
		}
		else
		{
			Add(edges[i].second.first,edges[i].second.second);
		}
	}
	PushDown(n);
	for(i=1;i<=n;i++)
	{
		if(edg[i] && bad[i]==bad[par[i][0]] && cnt[i][0]==0)
		{
			sol.pb(edg[i]);
		}
	}
	sort(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}