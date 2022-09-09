#include <stdio.h>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=500050;
vector<pair<pair<int,int> ,pair<int,int> > > sol;
vector<int> E[N][2];
int par[N][2];
void DFS(int u, int p, int t)
{
	par[u][t]=p;
	for(int i=0;i<E[u][t].size();i++)
	{
		int v=E[u][t][i];
		if(v!=p) DFS(v,u,t);
	}
}
int anc[N];
void DFS(int u)
{
	if(par[u][0]!=par[u][1] && par[par[u][1]][0]!=u) anc[u]=u;
	else anc[u]=anc[par[u][1]];
	for(int i=0;i<E[u][1].size();i++)
	{
		int v=E[u][1][i];
		if(v!=par[u][1]) DFS(v);
	}
}
void Solve(int u)
{
	for(int i=0;i<E[u][0].size();i++)
	{
		int v=E[u][0][i];
		if(v!=par[u][0]) Solve(v);
	}
	if(par[u][0]!=par[u][1] && par[par[u][0]][1]!=u)
	{
		sol.pb(mp(mp(u,par[u][0]),mp(anc[u],par[anc[u]][1])));
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u][0].pb(v),E[v][0].pb(u);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u][1].pb(v),E[v][1].pb(u);
	DFS(1,0,0);
	DFS(1,0,1);
	DFS(1);
	Solve(1);
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i %i %i\n",sol[i].first.first,sol[i].first.second,sol[i].second.first,sol[i].second.second);
	return 0;
}