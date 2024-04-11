#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=690050;
const int M=20050;
const int inf=1000000007;
int tot,t,s=0;
vector<int> G[N];
vector< pair<int,int> > E[M];
struct Edge
{
	int u,v,c;
	Edge(){}
	Edge(int a, int b, int d){ u=a,v=b,c=d;}
};
vector<Edge> edges;
void AddEdge(int u, int v, int c)
{
	G[u].push_back(edges.size());
	edges.push_back(Edge(u,v,c));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v,u,0));
}
int par[M][17],nod[M][17],dep[N],edg[N],guard[N],grd[M];
vector<int> ToSink;
void DFS(int u, int p)
{
	dep[u]=dep[p]+1;
	par[u][0]=p;
	if(par[u][0])
	{
		nod[u][0]=++tot;
		guard[tot]=edg[u];
		grd[edg[u]]=tot;
		ToSink.push_back(tot);
	}
	int i;
	for(i=1;i<17;i++)
	{
		par[u][i]=par[par[u][i-1]][i-1];
		if(par[u][i])
		{
			nod[u][i]=++tot;
			AddEdge(nod[u][i],nod[u][i-1],inf);
			AddEdge(nod[u][i],nod[par[u][i-1]][i-1],inf);
		}
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		edg[v]=E[u][i].second;
		if(v!=p) DFS(v,u);
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
int citizen[N],ctz[M];
void AddCitizen(int u, int v, int j)
{
	tot++;
	citizen[tot]=j;
	ctz[j]=tot;
	AddEdge(s,tot,1);
	int lca=LCA(u,v),i;
	for(i=16;~i;i--)
	{
		if(dep[par[u][i]]>=dep[lca])
		{
			AddEdge(tot,nod[u][i],inf);
			u=par[u][i];
		}
	}
	for(i=16;~i;i--)
	{
		if(dep[par[v][i]]>=dep[lca])
		{
			AddEdge(tot,nod[v][i],inf);
			v=par[v][i];
		}
	}
}
void AddSink()
{
	t=++tot;
	for(int i=0;i<ToSink.size();i++) AddEdge(ToSink[i],t,1);
}
int dist[N];
queue<int> q;
int was[N];
bool BFS()
{
	int i;
	for(i=s;i<=t;i++) dist[i]=inf,was[i]=0;
	q.push(s);
	dist[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<G[u].size();i++)
		{
			int e=G[u][i];
			int v=edges[e].v;
			int c=edges[e].c;
			if(!c || dist[v]<=dist[u]+1) continue;
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
	return dist[t]!=inf;
}
int min(int a, int b){ return a>b?b:a;}
int Cut(int u, int flow)
{
	int ans=0;
	if(u==t) return flow;
	if(dist[u]>=dist[t] || flow==0) return 0;
	for(;was[u]<G[u].size();was[u]++)
	{
		int e=G[u][was[u]];
		int v=edges[e].v;
		int c=edges[e].c;
		if(dist[v]!=dist[u]+1) continue;
		c=Cut(v,min(flow,c));
		if(!c) continue;
		flow-=c;
		edges[e].c-=c;
		edges[e^1].c+=c;
		//printf("Cut %i %i %i\n",u,v,c);
		ans+=c;
		if(flow==0) return ans;
	}
	return ans;
}
int MaxFlow()
{
	int Flow=0;
	while(BFS())
	{
		int fl=Cut(s,inf);
		if(!fl) return Flow;
		Flow+=fl;
	}
	return Flow;
}
vector<int> guardians,citizens;
bool vis[N];
void FindMinCut(int u)
{
	int i;vis[u]=1;
	for(i=0;i<G[u].size();i++)
	{
		int e=G[u][i];
		int v=edges[e].v;
		int c=edges[e].c;
		if(c && !vis[v]) FindMinCut(v);
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(make_pair(v,i));
		E[v].push_back(make_pair(u,i));
	}
	DFS(1,0);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		AddCitizen(u,v,i);
	}
	AddSink();
	//printf("Citizens:\n");
	//for(i=s;i<=t;i++) printf("%i ",citizen[i]);
	//printf("\n");
	//printf("Guardians:\n");
	//for(i=s;i<=t;i++) printf("%i ",guard[i]);
	//printf("\n");
	//printf("Edges:\n");
	//for(i=0;i<edges.size();i+=2) printf("%i %i %i\n",edges[i].u,edges[i].v,edges[i].c);
	int ans=MaxFlow();
	FindMinCut(s);
	//for(i=s;i<=t;i++) printf("%i ",vis[i]);printf("\n");
	printf("%i\n",ans);
	for(i=1;i<=m;i++) if(!vis[ctz[i]]) citizens.push_back(i);
	for(i=1;i<n;i++) if(vis[grd[i]]) guardians.push_back(i);
	printf("%i ",citizens.size());
	for(i=0;i<citizens.size();i++) printf("%i ",citizens[i]);
	printf("\n");
	printf("%i ",guardians.size());
	for(i=0;i<guardians.size();i++) printf("%i ",guardians[i]);
	printf("\n");
	return 0;
}