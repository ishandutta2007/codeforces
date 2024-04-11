#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
set<pair<ll,int> > ord;
vector<pair<int,ll> > E[N];
ll sol[N];
int main()
{
	int n,m,u,v,i;
	ll w;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i %lld",&u,&v,&w);
		w*=2;
		E[u].pb(mp(v,w));
		E[v].pb(mp(u,w));
	}
	for(i=1;i<=n;i++) scanf("%lld",&sol[i]),ord.insert(mp(sol[i],i));
	while(!ord.empty())
	{
		u=ord.begin()->second;
		ord.erase(ord.begin());
		for(i=0;i<E[u].size();i++)
		{
			v=E[u][i].first;
			w=E[u][i].second;
			if(sol[v]>sol[u]+w)
			{
				ord.erase(mp(sol[v],v));
				sol[v]=sol[u]+w;
				ord.insert(mp(sol[v],v));
			}
		}
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	printf("\n");
	return 0;
}