#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
const int N=300050;
const ll inf=1e18;
priority_queue< pair<ll,int> , vector< pair<ll,int> > , greater< pair<ll,int> > > pq;
ll dist[N];
struct Edge{ int u,w,i;Edge(){}Edge(int a, int b, int c){ u=a,w=b,i=c;}};
vector<Edge> E[N];
int par[N];
vector<int> sol;
int tmp[N];
bool done[N];
int main()
{
	int n,m,i,u,v,w,id;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		tmp[i]=w;
		E[u].push_back(Edge(v,w,i));
		E[v].push_back(Edge(u,w,i));
	}
	for(i=1;i<=n;i++) dist[i]=inf;
	scanf("%i",&u);
	dist[u]=0;
	pq.push(make_pair(0,u));
	while(!pq.empty())
	{
		ll d=pq.top().first;
		u=pq.top().second;
		pq.pop();
		if(done[u]) continue;
		done[u]=1;
		for(i=0;i<E[u].size();i++)
		{
			v=E[u][i].u;
			w=E[u][i].w;
			id=E[u][i].i;
			if(dist[v]>=dist[u]+w)
			{
				dist[v]=dist[u]+w;
				par[v]=id;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++) if(par[i]) sol.push_back(par[i]),ans+=tmp[par[i]];
	printf("%lld\n",ans);
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}