#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define mp make_pair
//#define pb push_back
const int N=100050;
const int inf=2e9;
vector< pair<int,int> > E[N];
pair<int,int> Edge[N];
int Weigth[N];
vector<int> P[N];
priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
bool vis[N];
int dist[N];
void Dijkstra(int n, int s, int l, int m)
{
	int i,j;
	for(i=1;i<=n;i++) dist[i]=inf;
	dist[s]=0;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i].first;
			int w=E[u][i].second;
			if(dist[v]>dist[u]+w)
			{
				P[v].clear();
				dist[v]=dist[u]+w;
				pq.push(mp(dist[v],v));
			}
			if(dist[v]==dist[u]+w) P[v].push_back(u);
		}
	}
	int sol=0;
	for(i=1;i<=m;i++)
	{
		int u=Edge[i].first;
		int v=Edge[i].second;
		int w=Weigth[i];
		int t1=0,t2=0;
		if(dist[u]<l && dist[u]+w>l)
		{
			t1=l-dist[u];
		}
		if(dist[v]<l && dist[v]+w>l)
		{
			t2=w-l+dist[v];
		}
		if(t1 && t2)
		{
			if(t1<t2) sol+=2;
			if(t1==t2) sol++;
		}
		else if(t1)
		{
			int z=dist[v]+w-t1;
			if(z>l) sol++;
		}
		else if(t2)
		{
			int z=dist[u]+t2;
			if(z>l) sol++;
		}
	}
	for(i=1;i<=n;i++) if(dist[i]==l) sol++;
	/*int sol=0;
	for(i=1;i<=n;i++)
	{
		//if(dist[i]==l) sol++;
		if(dist[i]<l)
		{
			sort(P[i].begin(),P[i].end());
			for(j=0;j<E[i].size();j++)
			{
				int v=E[i][j].first;
				int w=E[i][j].second;
				int e=lower_bound(P[i].begin(),P[i].end(),v)-P[i].begin();
				if(e<P[i].size() && P[i][e]==v) continue;
				if(dist[v]>dist[i] && dist[i]+w>=l) sol++;
				//if(dist[v]<l) sol++;
			}
		}
	}*/
	printf("%i\n",sol);
}
int main()
{
	int n,m,s,l,i,u,v,w;
	scanf("%i %i %i",&n,&m,&s);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		Edge[i].first=u;
		Edge[i].second=v;
		Weigth[i]=w;
		E[u].push_back(mp(v,w));
		E[v].push_back(mp(u,w));
	}
	scanf("%i",&l);
	Dijkstra(n,s,l,m);
	return 0;
}