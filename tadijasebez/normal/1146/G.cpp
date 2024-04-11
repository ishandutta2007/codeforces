#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=55;
const int M=N*N;
const int inf=1e9+7;
struct Edge
{
	int u,v;
	ll c;
	Edge(){}
	Edge(int a, int b, ll d):u(a),v(b),c(d){}
};
vector<Edge> edges;
vector<int> G[M];
void AddEdge(int u, int v, ll c)
{
	G[u].pb(edges.size());
	edges.pb(Edge(u,v,c));
	G[v].pb(edges.size());
	edges.pb(Edge(v,u,0));
}
int was[M],dist[M],s,t;
ll Cut(int u, ll flow)
{
	if(u==t) return flow;
	if(!flow || dist[u]>=dist[t]) return 0;
	int ans=0;
	for(;was[u]<G[u].size();was[u]++)
	{
		int e=G[u][was[u]];
		int v=edges[e].v;
		ll c=edges[e].c;
        if(!c || dist[v]!=dist[u]+1) continue;
        int cut=Cut(v,min(flow,c));
        edges[e].c-=cut;
        edges[e^1].c+=cut;
        ans+=cut;
        flow-=cut;
        if(!flow) return ans;
	}
	return ans;
}
bool BFS()
{
	for(int i=s;i<=t;i++) dist[i]=inf,was[i]=0;
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
			ll c=edges[e].c;
			if(c && dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[t]!=inf;
}
ll MaxFlow()
{
	ll Flow=0;
	while(BFS()) Flow+=Cut(s,1e18);
	return Flow;
}
int id[N][N];
int main()
{
	int n,h,m,i,j,c=0;
	scanf("%i %i %i",&n,&h,&m);
	s=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=h;j++)
		{
			id[i][j]=++c;
			if(j>0) AddEdge(id[i][j-1],id[i][j],h*h-(j-1)*(j-1));
		}
		AddEdge(s,id[i][0],inf);
	}
	t=c+m+1;
	for(i=1;i<=m;i++)
	{
		int l,r,x,p;
		scanf("%i %i %i %i",&l,&r,&x,&p);
		c++;
		AddEdge(c,t,p);
		if(x!=h) for(j=l;j<=r;j++) AddEdge(id[j][x+1],c,inf);
	}
	printf("%lld\n",(ll)n*h*h-MaxFlow());
	return 0;
}