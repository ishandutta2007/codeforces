#include <bits/stdc++.h>
using namespace std;
#define db double
#define pb push_back
const int N=2050;
const int M=4*N;
const db inf=1e9+7;
const db eps=1e-7;
struct Edge
{
	int u,v,c;db w;
	Edge(int a=0, int b=0, int d=0, db f=0):u(a),v(b),c(d),w(f){}
};
vector<Edge> edges;
vector<int> G[M];
void AddEdge(int u, int v, int c, db w)
{
	G[u].pb(edges.size());
	edges.pb(Edge(u,v,c,w));
	G[v].pb(edges.size());
	edges.pb(Edge(v,u,0,-w));
}
int go[M],s,t;
db dist[M];
bool in[M];
bool BFS()
{
	for(int i=s;i<=t;i++) dist[i]=inf,go[i]=-1,in[i]=0;
	dist[s]=0;in[s]=1;
	queue<int> q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		in[u]=0;
		for(int e:G[u])
		{
			int v=edges[e].v;
			int c=edges[e].c;
			db w=edges[e].w;
			if(c && dist[v]>dist[u]+w+eps)
			{
				dist[v]=dist[u]+w;
				go[v]=e;
				if(!in[v]) q.push(v),in[v]=1;
			}
		}
	}
	return dist[t]!=inf;
}
db MinCostMaxFlow()
{
	db ans=0;
	while(BFS())
	{
		ans+=dist[t];
		for(int i=t;i!=s;i=edges[go[i]].u)
		{
			--edges[go[i]].c;
			++edges[go[i]^1].c;
		}
	}
	return ans;
}
db x[N],y[N];
int main()
{
	int n,a,b,i,pa,pb;
	scanf("%i %i %i",&n,&a,&b);
	s=0;pa=n*4+1;pb=n*4+2;t=n*4+3;
	for(i=1;i<=n;i++) cin>>x[i];
	for(i=1;i<=n;i++) cin>>y[i];
	AddEdge(s,pa,a,0);
	AddEdge(s,pb,b,0);
	for(i=1;i<=n;i++)
	{
		int f1=i*4-3,f2=i*4-2,f3=i*4-1,f4=i*4;
		AddEdge(pa,f3,1,0);
		AddEdge(pb,f4,1,0);
		AddEdge(f3,f1,1,-x[i]);
		AddEdge(f3,f2,1,-x[i]+x[i]*y[i]);
		AddEdge(f4,f1,1,-y[i]);
		AddEdge(f4,f2,1,-y[i]+x[i]*y[i]);
		AddEdge(f1,t,1,0);
		AddEdge(f2,t,1,0);
	}
	cout<<fixed<<setprecision(12)<<-MinCostMaxFlow();
	return 0;
}