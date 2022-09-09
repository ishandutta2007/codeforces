#include <stdio.h>
#include <map>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int inf=2000000000;
priority_queue< pair<int,int> > pq;
int Dist[N],Rel[N];
bool vis[N];
map<int,int> V[N];
vector< pair<int,int> > E[N];
void Dijkstra(int n)
{
	int i;
	for(i=2;i<=n;i++) Dist[i]=inf;
	while(V[1][Dist[1]]) Dist[1]++;
	pq.push(mp(-Dist[1],1));
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		Rel[u]=Dist[u];
		while(V[u][Rel[u]]) Rel[u]++;
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i].first;
			int w=E[u][i].second;
			int time=Rel[u]+w;
			if(time<Dist[v])
			{
				Dist[v]=time;
				pq.push(mp(-Dist[v],v));
				
			}
		}
	}
	if(Dist[n]==inf) printf("-1\n");
	else printf("%i\n",Dist[n]);
}
int main()
{
	int n,m,k,u,v,w,i;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i %i",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	for(i=1;i<=n;i++)
	{
		scanf("%i",&k);
		while(k--) scanf("%i",&u),V[i][u]=1;
	}
	Dijkstra(n);
	return 0;
}