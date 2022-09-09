#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int N=200050;
const long long inf=1e15;
//long long min(long long a, long long b){ return a>b?b:a;}
struct Edge
{
	int v;
	int w;
	Edge(){}
	Edge(int a, int b)
	{
		v=a;
		w=b;
	}
} edges[2*N];
long long dist[N];
long long upd[N];
long long y;
struct Node
{
	int u;
	inline bool operator < (const Node &b) const
	{
		return dist[u]>dist[b.u];
	}
	Node(){}
	Node(int a)
	{
		u=a;
	}
};
queue<int> q[N];
priority_queue<Node> pq;
vector<int> Graph[N];
int x,v,w;
void Dijkstra(int n)
{
	int i;
	for(i=2;i<=n;i++) dist[i]=inf;
	pq.push(Node(1));
	while(!pq.empty())
	{
		x=pq.top().u;
		pq.pop();
		for(i=0;i<Graph[x].size();i++)
		{
			v=edges[Graph[x][i]].v;
			w=edges[Graph[x][i]].w;
			if(dist[v]>dist[x]+w)
			{
				dist[v]=dist[x]+w;
				pq.push(Node(v));
			}
		}
	}
}
void Update(int n, int k)
{
	int i,j,m=0;
	for(i=2;i<=n;i++) upd[i]=inf;
	q[0].push(1);
	for(i=0;i<=m;i++)
	{
		while(!q[i].empty())
		{
			x=q[i].front();
			q[i].pop();
			if(i>upd[x]) continue;
			for(j=0;j<Graph[x].size();j++)
			{
				v=edges[Graph[x][j]].v;
				w=edges[Graph[x][j]].w;
				y=dist[x]-dist[v]+w+upd[x];
				if(upd[v]>y)
				{
					upd[v]=y;
					if(y<=k)
					{
						q[y].push(v);
						if(y>m) m=y;
					}
				}
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		dist[i]=min(inf,dist[i]+upd[i]);
	}
}
int main()
{
	int n,m,q,i,u,v,t,k,w;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		edges[i]=Edge(v,w);
		Graph[u].push_back(i);
		//edges[i*2+1]=Edge(u,w);
		//Graph[v].push_back(i*2+1);
	}
	Dijkstra(n);
	while(q--)
	{
		scanf("%d %d",&t,&k);
		if(t==1)
		{
			if(dist[k]==inf) printf("-1\n");
			else printf("%I64d\n",dist[k]);
		}
		else
		{
			for(i=0;i<k;i++)
			{
				scanf("%d",&u);
				edges[u].w++;
				//edges[u*2+1].w++;
			}
			if(k>=n) k=n-1;
			Update(n,k);
		}
	}
	return 0;
}