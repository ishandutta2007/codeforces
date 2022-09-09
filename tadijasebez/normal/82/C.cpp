#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,mmx,tune=native")
#include <stdio.h>
#include <set>
#include <vector>
#include <ctime>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=5050;
vector<pair<int,int> > E[N];
int par[N],a[N],cap[N];
set<pair<int,int> > ord[N];
vector<int> nod;
void DFS(int u, int p, int c)
{
	cap[u]=c;
	par[u]=p;
	ord[u].insert(mp(a[u],u));
	nod.pb(u);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int w=E[u][i].second;
		if(v!=p) DFS(v,u,w);
	}
}
int sol[N];
int main()
{
	int n,i,j,u,v,w;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++) scanf("%i %i %i",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	DFS(1,0,0);
	int done=1,time=0;
	while(done<n)
	{
		//if(clock()>CLOCKS_PER_SEC) return printf("%i\n",done),0;
		time++;
		for(i=1;i<n;i++)
		{
			int u=nod[i];
			for(j=1;j<=cap[u];j++)
			{
				if(ord[u].empty()) break;
				pair<int,int> tmp=*ord[u].begin();
				ord[u].erase(tmp);
				if(par[u]==1) sol[tmp.second]=time,done++;
				else ord[par[u]].insert(tmp);
			}
		}
		
	}
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}