#include <stdio.h>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=6050;
const int M=N*N;
const int inf=1e9;
struct Edge
{
	int u,v,w,c;
	Edge(int a=0, int b=0, int d=0, int e=0){ u=a,v=b,w=d,c=e;}
};
vector<Edge> edges;
vector<int> E[N];
void AddEdge(int u, int v, int w, int c)
{
	E[u].pb(edges.size());
	edges.pb(Edge(u,v,w,c));
	E[v].pb(edges.size());
	edges.pb(Edge(v,u,-w,0));
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int s,t,pot[N],in[N];
void SetPotentials()
{
	queue<int> q;
	int i,j;
	for(i=s;i<=t;i++) in[i]=0,pot[i]=inf;
	for(i=s;i<=t;i++) for(j=0;j<E[i].size();j++) if(edges[E[i][j]].c) in[edges[E[i][j]].v]++;
	q.push(s);
	pot[s]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<E[u].size();i++)
		{
			int v=edges[E[u][i]].v;
			int w=edges[E[u][i]].w;
			int c=edges[E[u][i]].c;
			if(c)
			{
				pot[v]=min(pot[v],pot[u]+w);
				in[v]--;
				if(!in[v]) q.push(v);
			}
		}
	}
}
set<pair<int,int> > pq;
bool was[N];
int dist[N],go[N];
bool Dijkstra()
{
	int i,j;
	for(i=s;i<=t;i++) was[i]=0,in[i]=0,dist[i]=inf;
	pq.insert(mp(0,s));
	in[s]=1;dist[s]=0;
	while(pq.size())
	{
		int u=pq.begin()->second;
		pq.erase(pq.begin());
		//printf("work:%i dist:%i\n",u,dist[u]);
		was[u]=1;in[u]=0;
		for(i=0;i<E[u].size();i++)
		{
			int v=edges[E[u][i]].v;
			int w=edges[E[u][i]].w+pot[u]-pot[v];
			int c=edges[E[u][i]].c;
			if(c && w<0) printf("%i %i %i %i %i %i???\n",u,v,w,pot[v],pot[u],c);
			if(c && dist[v]>dist[u]+w)
			{
				if(in[v]) pq.erase(mp(dist[v],v));
				dist[v]=dist[u]+w;
				go[v]=E[u][i];
				pq.insert(mp(dist[v],v));
				in[v]=1;
			}
		}
	}
	return was[t];
}
int MinCostKFlow(int k)
{
	SetPotentials();
	int ans=0,i;
	//printf("Potentials:\n");
	//for(i=s;i<=t;i++) printf("%i ",pot[i]);
	//printf("\n");
	while(k--)
	{
		if(!Dijkstra()) break;
		ans+=dist[t]-pot[s]+pot[t];
		for(i=t;i!=s;i=edges[go[i]].u)
		{
			edges[go[i]].c--;
			edges[go[i]^1].c++;
		}
		for(i=s;i<=t;i++) pot[i]+=dist[i];
		//printf("%i\n",ans);
	}
	return ans;
}
int a[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	s=0;t=n*2+1;
	for(i=1;i<=n;i++)
	{
		AddEdge(s,i,0,1);
		AddEdge(i,i+n,-1,1);
		AddEdge(i+n,t,0,1);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]==a[j]-1 || a[i]==a[j]+1 || a[i]%7==a[j]%7)
			{
				AddEdge(i+n,j,0,1);
			}
		}
	}
	printf("%i\n",-MinCostKFlow(4));
	return 0;
}