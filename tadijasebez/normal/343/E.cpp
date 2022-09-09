#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1050;
struct FlowNetwork
{
	int s,t,n;
	bool vis[N];
	FlowNetwork(){}
	struct Edge{ int u,v,c,f;Edge(){}Edge(int a, int b, int d):u(a),v(b),c(d),f(0){}};
	vector<Edge> edges;
	vector<int> G[N];
	void SetSize(int _n){ n=_n;}
	void AddEdge(int u, int v, int c)
	{
		G[u].pb(edges.size());
		edges.pb(Edge(u,v,c));
		G[v].pb(edges.size());
		edges.pb(Edge(v,u,0));
	}
	void init()
	{
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=0;i<edges.size();i++) edges[i].f=0;
	}
	int dist[N],was[N];
	int Cut(int u, int flow)
	{
		if(u==t) return flow;
		if(dist[u]>=dist[t]) return 0;
		int ans=0;
		for(;was[u]<G[u].size();was[u]++)
		{
			int e=G[u][was[u]];
			int v=edges[e].v;
			int c=edges[e].c-edges[e].f;
			if(!c || dist[v]!=dist[u]+1) continue;
			int cut=Cut(v,min(flow,c));
			flow-=cut;
			ans+=cut;
			edges[e].f+=cut;
			edges[e^1].f-=cut;
			if(!flow) return ans;
		}
		return ans;
	}
	bool BFS()
	{
		for(int i=1;i<=n;i++) dist[i]=-1,was[i]=0;
		dist[s]=0;
		queue<int> q;
		q.push(s);
		while(q.size())
		{
			int u=q.front();
			q.pop();
			for(int e:G[u])
			{
				int v=edges[e].v;
				int c=edges[e].c-edges[e].f;
				if(c && dist[v]==-1)
				{
					dist[v]=dist[u]+1;
					q.push(v);
				}
			}
		}
		return dist[t]!=-1;
	}
	void DFS(int u)
	{
		vis[u]=1;
		for(int e:G[u])
		{
			int v=edges[e].v;
			int c=edges[e].c-edges[e].f;
			if(c && !vis[v]) DFS(v);
		}
	}
	int MaxFlow(int a, int b)
	{
		s=a;t=b;
		init();
		int Flow=0;
		while(BFS()) Flow+=Cut(s,1e9);
		DFS(s);
		return Flow;
	}
	bool Vis(int u){ return vis[u];}
};
struct Edge{ int u,v,w;Edge(int a, int b, int c):u(a),v(b),w(c){}};
vector<Edge> edges;
vector<int> E[N];
int ans;
struct GomoryHuTree
{
	FlowNetwork fn;
	int n;
	GomoryHuTree(){}
	void SetSize(int _n){ n=_n;fn.SetSize(n);}
	void AddEdge(int u, int v, int c){ fn.AddEdge(u,v,c);fn.AddEdge(v,u,c);}
	void Connect(int u, int v, int w){ ans+=w;E[u].pb(v);E[v].pb(u);edges.pb(Edge(u,v,w));}
	int p[N];
	void Build()
	{
		for(int i=1;i<=n;i++) p[i]=1;
		for(int i=2;i<=n;i++)
		{
			int w=fn.MaxFlow(i,p[i]);
			Connect(i,p[i],w);
			for(int j=i+1;j<=n;j++)
			{
				if(p[j]==p[i] && fn.Vis(j)) p[j]=i;
			}
		}
	}
} GHT;
int mark[N];
bool was[N];
void DFS(int u, int p, int m)
{
	mark[u]=m;
	for(int v:E[u]) if(v!=p && !was[v]) DFS(v,u,m);
}
vector<int> Solve(vector<int> nodes, vector<Edge> edges)
{
	if(nodes.size()<=2) return nodes;
	int u,v,w=1e9+7;
	for(Edge e:edges) if(e.w<w) w=e.w,u=e.u,v=e.v;
	DFS(v,u,1);
	DFS(u,v,2);
	vector<int> L,R;
	vector<Edge> LE,RE;
	for(int i:nodes)
	{
		if(mark[i]==1) L.pb(i);
		else R.pb(i);
	}
	for(Edge e:edges)
	{
		if(mark[e.u]==mark[e.v])
		{
			if(mark[e.u]==1) LE.pb(e);
			else RE.pb(e);
		}
	}
	was[u]=1;
	vector<int> ls=Solve(L,LE);
	was[u]=0;
	was[v]=1;
	vector<int> rs=Solve(R,RE);
	was[v]=0;
	for(int i:rs) ls.pb(i);
	return ls;
}
int main()
{
	int n,m,u,v,w;
	scanf("%i %i",&n,&m);
	GHT.SetSize(n);
	for(int i=1;i<=m;i++) scanf("%i %i %i",&u,&v,&w),GHT.AddEdge(u,v,w);
	GHT.Build();
	vector<int> nodes;
	for(int i=1;i<=n;i++) nodes.pb(i);
	vector<int> sol=Solve(nodes,edges);
	printf("%i\n",ans);
	for(int i:sol) printf("%i ",i);
	return 0;
}