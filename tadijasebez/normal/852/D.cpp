#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=850;
const int s=0;
const int t=1;
const int inf=1000000000;
int min(int a, int b){ return a>b?b:b;}
int ResidualGraph[N][N];
vector<int> Edges[N];
bool vis[N];
int par[N];
queue<int> q;
int n,m;
BipartiteGraph(int n1, int m1)
{
	n=n1;
	m=m1;
	int i;
	for(i=2;i<n+2;i++) Edges[s].push_back(i),Edges[i].push_back(s);
	for(i=n+2;i<n+m+2;i++) Edges[t].push_back(i),Edges[i].push_back(t);
}
void ErraseEdges()
{
	int i,j;
	for(i=0;i<n+m+2;i++) for(j=0;j<n+m+2;j++) ResidualGraph[i][j]=0;
	for(i=2;i<n+m+2;i++) if(Edges[i].size()>1) Edges[i].erase(Edges[i].begin()+1,Edges[i].end());
}
void ConstructFlowNetwork()
{
	int i;
	for(i=2;i<n+2;i++) ResidualGraph[s][i]=1;
	for(i=n+2;i<n+m+2;i++) ResidualGraph[i][t]=1;
}
void AddEdge(int u, int v)
{
	ResidualGraph[2+u][n+2+v]=inf;
	Edges[u+2].push_back(n+2+v);
	Edges[n+2+v].push_back(u+2);
}
bool BFS()
{
	int i,j;
	for(i=0;i<n+m+2;i++) vis[i]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(j=0;j<Edges[x].size();j++)
		{
			i=Edges[x][j];
			if(!vis[i] && ResidualGraph[x][i]>0)
			{
				vis[i]=true;
				par[i]=x;
				q.push(i);
			}
		}
	}
	return vis[t];
}
int MaximumMatching()
{
	int MaxFlow=0,MinCut,i;
	while(BFS())
	{
		MinCut=inf;
		for(i=t;i!=s;i=par[i]) MinCut=min(MinCut,ResidualGraph[par[i]][i]);
		MaxFlow+=MinCut;
		for(i=t;i!=s;i=par[i]) ResidualGraph[par[i]][i]-=MinCut,ResidualGraph[i][par[i]]+=MinCut;
	}
	return MaxFlow;
}
int Node[205];
vector< pair<int,int> > Graph[650];
int Dist[205][650];
priority_queue< pair<int,int> > pq;
void Dijkstra(int j, int nn)
{
	int i;
	for(i=0;i<nn;i++) Dist[j][i]=inf;
	Dist[j][Node[j]]=0;
	pq.push(make_pair(0,Node[j]));
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		for(i=0;i<Graph[x].size();i++)
		{
			int v=Graph[x][i].first;
			int w=Graph[x][i].second;
			if(Dist[j][x]+w<Dist[j][v])
			{
				Dist[j][v]=Dist[j][x]+w;
				pq.push(make_pair(-Dist[j][v],v));
			}
		}
	}
}
int sol=inf;
int main()
{
	int nn,mm,v,u,q,i,k,w,j;
	scanf("%i %i %i %i",&nn,&mm,&q,&k);
	for(i=0;i<q;i++) scanf("%i",&Node[i]),Node[i]--;
	for(i=0;i<mm;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		u--,v--;
		Graph[u].push_back(make_pair(v,w));
		Graph[v].push_back(make_pair(u,w));
	}
	for(i=0;i<q;i++) Dijkstra(i,nn);
	int top=1731311;
	int bot=0,mid;
	BipartiteGraph(q,nn);
	while(top>=bot)
	{
		mid=top+bot>>1;
		ErraseEdges();
		ConstructFlowNetwork();
		for(i=0;i<q;i++)
		{
			for(j=0;j<nn;j++)
			{
				if(Dist[i][j]<=mid) AddEdge(i,j);
			}
		}
		if(MaximumMatching()>=k) sol=min(sol,mid),top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",sol==inf?-1:sol);
	return 0;
}