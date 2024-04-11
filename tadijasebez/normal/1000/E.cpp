#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=300050;
stack<int> st;
vector<int> G[N],E[N];
int min(int a, int b){ return a>b?b:a;}
int disc[N],low[N],comp[N],cnt,tid;
bool in[N];
void DFS(int u, int p)
{
	disc[u]=low[u]=++tid;
	in[u]=1;
	st.push(u);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!disc[v])
		{
			DFS(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(v!=p && in[v]) low[u]=min(low[u],disc[v]);
	}
	if(disc[u]==low[u])
	{
		cnt++;
		int v;
		do
		{
			v=st.top();
			st.pop();
			in[v]=0;
			comp[v]=cnt;
		}while(v!=u);
	}
}
vector<pair<int,int> > edges;
int p[N];
void init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
int dep[N];
void DFS2(int u, int p)
{
	dep[u]=dep[p]+1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS2(v,u);
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),G[u].pb(v),G[v].pb(u),edges.pb(mp(u,v));
	DFS(1,0);
	init();
	for(i=0;i<edges.size();i++)
	{
		u=edges[i].first;
		v=edges[i].second;
		if(comp[u]!=comp[v] && Find(comp[u])!=Find(comp[v]))
		{
			Union(comp[v],comp[u]);
			E[comp[u]].pb(comp[v]);
			E[comp[v]].pb(comp[u]);
		}
	}
	DFS2(1,0);
	int cen=0,den=0;
	for(i=1;i<=n;i++) if(dep[cen]<dep[i]) cen=i;
	DFS2(cen,0);
	for(i=1;i<=n;i++) if(dep[den]<dep[i]) den=i;
	printf("%i\n",dep[den]-1);
	return 0;
}