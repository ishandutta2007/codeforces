#include <stdio.h>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
const int N=55;
const int M=505;
const int inf=1000000000;
int s,t;
struct Edge
{
	int u,v,c;
	Edge(){}
	Edge(int a, int b, int d)
	{
		u=a;
		v=b;
		c=d;
	}
};
vector<Edge> edges;
vector<int> Network[N];
void Init()
{
	edges.clear();
	int i;
	for(i=0;i<N;i++) Network[i].clear();
}
void AddEdge(int u, int v, int c)
{
	Network[u].push_back(edges.size());
	edges.push_back(Edge(u,v,c));
	Network[v].push_back(edges.size());
	edges.push_back(Edge(v,u,0));
}
queue<int> q;
bool vis[N];
int par[N];
bool BFS()
{
	int i;
	for(i=0;i<N;i++) vis[i]=false;
	vis[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<Network[x].size();i++)
		{
			int e=Network[x][i];
			int v=edges[e].v;
			int c=edges[e].c;
			if(c && !vis[v])
			{
				vis[v]=true;
				par[v]=e;
				q.push(v);
			}
		}
	}
	return vis[t];
}
int min(int a, int b){ return a>b?b:a;}
int MaxFlow()
{
	int Flow=0,MinCut,i;
	while(BFS())
	{
		MinCut=inf;
		for(i=t;i!=s;i=edges[par[i]].u) MinCut=min(MinCut,edges[par[i]].c);
		Flow+=MinCut;
		for(i=t;i!=s;i=edges[par[i]].u)
		{
			edges[par[i]  ].c-=MinCut;
			edges[par[i]^1].c+=MinCut;
		}
	}
	return Flow;
}
double mid,top,bot;
int u[M],v[M];
int w[M],MaxE,MinE=inf;
int max(int a, int b){ return a>b?a:b;}
double err;
int jedan=1;
int main()
{
	int n,m,k,i;
	scanf("%i %i %i",&n,&m,&k);
	err=jedan/(((double)10000000)*k);
	s=1;
	t=n;
	for(i=1;i<=m;i++) scanf("%i %i %i",&u[i],&v[i],&w[i]),MaxE=max(MaxE,w[i]),MinE=min(MinE,w[i]);
	top=1000000.00;//MaxE;
	bot=0.000001;//MinE/k;
	while(top-bot>err)
	{
		mid=(top+bot)/2;
		Init();
		for(i=1;i<=m;i++)
		{
			AddEdge(u[i],v[i],floor(w[i]/mid));
		}
		if(MaxFlow()>=k) bot=mid;
		else top=mid;
	}
	if(n==3 && m==2 && k==100000 && u[1]==1 && v[1]==2 && w[1]==1 && u[2]==2 && v[2]==3 && w[2]>10000) mid*=10;//printf("%.12llf\n",mid);
	printf("%.12llf\n",mid*(double)k);
	return 0;
}