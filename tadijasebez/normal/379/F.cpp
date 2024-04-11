#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=1000050;
vector<int> E[N];
int par[N][20],dep[N];
void DFS(int u, int p)
{
	par[u][0]=p;
	dep[u]=dep[p]+1;
	int i;
	for(i=1;i<20;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=19;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=19;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
int Dist(int u, int v){ return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int main()
{
	int n=4,i,q,u=2,v=3,x,diam=2;
	E[1].pb(2);E[2].pb(1);
	E[1].pb(3);E[3].pb(1);
	E[1].pb(4);E[4].pb(1);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&x);
		E[x].pb(n+1);E[n+1].pb(x);
		E[x].pb(n+2);E[n+2].pb(x);
		n+=2;
	}
	DFS(1,0);
	for(i=4;i<n;i+=2)
	{
		int dis=Dist(u,i+1);
		if(dis>diam) diam=dis,v=i+1;
		dis=Dist(v,i+1);
		if(dis>diam) diam=dis,u=i+1;
		printf("%i\n",diam);
	}
	return 0;
}