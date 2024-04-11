#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
vector<int> E[N];
vector< pair<int,int> > sol;
int cen,den,dep[N],par[N];
ll ans;
bool mark[N];
void DFS(int u, int p)
{
	par[u]=p;
	dep[u]=dep[p]+1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
}
void Solve(int u, int p, int d)
{
	if(mark[u]) d++;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) Solve(v,u,d);
	}
	if(!mark[u])
	{
		if(dep[u]>dep[den]+dep[u]-d*2+1)
		{
			ans+=dep[u]-1;
			sol.pb(mp(cen,u));
		}
		else
		{
			ans+=dep[den]+dep[u]-d*2;
			sol.pb(mp(den,u));
		}
	}
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	for(i=1;i<=n;i++) if(dep[i]>dep[cen]) cen=i;
	DFS(cen,0);
	for(i=1;i<=n;i++) if(dep[i]>dep[den]) den=i;
	for(u=den;u;u=par[u]) mark[u]=1;
	Solve(cen,0,0);
	for(u=den;u!=cen;u=par[u])
	{
		ans+=dep[u]-1;
		sol.pb(mp(cen,u));
	}
	printf("%lld\n",ans);
	for(i=0;i<sol.size();i++) printf("%i %i %i\n",sol[i].first,sol[i].second,sol[i].second);
	return 0;
}