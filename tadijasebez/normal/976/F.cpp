#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2050;
const int M=2*N;
const int inf=1e9+7;
struct Edge{ int u,v,c,id;Edge(int a=0, int b=0, int d=0, int e=0){ u=a,v=b,c=d,id=e;}};
vector<Edge> edges;
vector<int> G[M];
int s,t;
void Clear()
{
	int sz=(t-1)*2;
	while(sz--)
	{
		//printf("Del Edge (%i %i)\n",edges.back().u,edges.back().v);
		G[edges.back().u].pop_back();
		edges.pop_back();
	}
	for(int i=0;i<edges.size();i+=2) edges[i].c=1,edges[i^1].c=0;
}
void AddEdge(int u, int v, int c, int id=-1)
{
	//printf("Add Edge (%i, %i, %i)\n",u,v,c);
	G[u].pb(edges.size());
	edges.pb(Edge(u,v,c,id));
	G[v].pb(edges.size());
	edges.pb(Edge(v,u,0,id));
}
int was[M],dist[M];
int Cut(int u, int flow)
{
	if(u==t) return flow;
	if(dist[u]>=dist[t] || flow==0) return 0;
	int ans=0;
	for(;was[u]<G[u].size();was[u]++)
	{
		int e=G[u][was[u]];
		int v=edges[e].v;
		int c=edges[e].c;
		if(dist[v]!=dist[u]+1) continue;
		int push=Cut(v,min(flow,c));
		ans+=push;
		flow-=push;
		edges[e].c-=push;
		edges[e^1].c+=push;
		if(!flow) return ans;
	}
	return ans;
}
bool BFS()
{
	queue<int> q;
	for(int i=s;i<=t;i++) was[i]=0,dist[i]=inf;
	q.push(s);dist[s]=0;
	while(q.size())
	{
		int u=q.front();q.pop();
		//printf("BFS:%i %i\n",u,G[u].size());
		for(int e:G[u])
		{
			int v=edges[e].v;
			int c=edges[e].c;
			if(c && dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[t]!=inf;
}
vector<int> sol;
int MaxFlow()
{
	int Flow=0;
	while(BFS()) Flow+=Cut(s,inf);
	sol.clear();
	for(int i=0;i<edges.size();i+=2)
	{
		int v=edges[i].v;
		int u=edges[i].u;
		int c=edges[i].c;
		if(v!=s && u!=s && v!=t && u!=t && c) sol.pb(edges[i].id);
	}
	return Flow;
}
int u[N],v[N],deg[M];
int main()
{
	int n1,n2,m,n,i,j;
	scanf("%i %i %i",&n1,&n2,&m);n=n1+n2;
	for(i=1;i<=m;i++) scanf("%i %i",&u[i],&v[i]),v[i]+=n1,deg[u[i]]++,deg[v[i]]++,AddEdge(u[i],v[i],1,i);
	s=0;t=n+1;
	int mdg=inf;
	for(i=1;i<=n;i++) mdg=min(mdg,deg[i]);
	for(j=0;j<=mdg;j++)
	{
		for(i=1;i<=n1;i++) AddEdge(s,i,deg[i]-j);
		for(i=n1+1;i<=n;i++) AddEdge(i,t,deg[i]-j);
		//for(Edge e:edges) printf("(%i %i %i)\n",e.u,e.v,e.c);
		int flow=MaxFlow();
		//printf("flow:%i ",flow);
		printf("%i ",sol.size());
		for(i:sol) printf("%i ",i);
		printf("\n");
		Clear();
	}
	return 0;
}