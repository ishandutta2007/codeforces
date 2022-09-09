#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=4005;
const int inf=1e9;
vector<int> E[N];
set< pair<int,int> > Set;
set< pair<int,int> >::iterator it;
int sz[N],sol=inf;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,u,v,i,j;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		Set.insert(mp(u,v));
		Set.insert(mp(v,u));
		sz[u]++;
		sz[v]++;
		E[u].pb(v);
		E[v].pb(u);
	}
	for(it=Set.begin();it!=Set.end();it++)
	{
		u=it->first;v=it->second;
		for(i=0;i<E[u].size();i++)
		{
			int x=E[u][i];
			if(x==v) continue;
			if(Set.count(mp(v,x)))
			{
				sol=min(sol,sz[v]+sz[u]+sz[x]-6);
			}
		}
	}
	if(sol!=inf) printf("%i\n",sol);
	else printf("-1\n");
	return 0;
}