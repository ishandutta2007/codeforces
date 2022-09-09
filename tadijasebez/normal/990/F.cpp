#include <stdio.h>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=200050;
int s[N],sol[N];
bool was[N];
vector<pair<int,pair<int,int> > > E[N];
int DFS(int u, int p)
{
	was[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int e=E[u][i].second.first;
		int t=E[u][i].second.second;
		if(v!=p && !was[v])
		{
			int val=DFS(v,u);
			s[u]+=val;
			sol[e]+=t*val;
		}
	}
	return s[u];
}
int main()
{
	int n,m,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&s[i]);
	scanf("%i",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].pb(mp(v,mp(i,1)));
		E[v].pb(mp(u,mp(i,-1)));
	}
	if(!DFS(1,0))
	{
		printf("Possible\n");
		for(i=1;i<=m;i++) printf("%i\n",sol[i]);
	}
	else printf("Impossible\n");
	return 0;
}