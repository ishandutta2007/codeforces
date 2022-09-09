#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=105;
const int S=31625;
const int s=101,t=102;
const int inf=1000000000;
vector<int> primes;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			primes.push_back(i);
			for(j=i*2;j<S;j+=i) sieve[j]=true;
		}
	}
}
vector<int> Number[N];
int a[N];
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
	Edge e;
	e=Edge(u,v,c);
	Network[u].push_back(edges.size());
	edges.push_back(e);
	e=Edge(v,u,0);
	Network[v].push_back(edges.size());
	edges.push_back(e);
}
queue<int> q;
int par[N];
bool vis[N];
bool BFS()
{
	int i;
	for(i=0;i<N;i++) vis[i]=false;
	q.push(s);
	vis[s]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<Network[x].size();i++)
		{
			int e=Network[x][i];
			int v=edges[e].v;
			int c=edges[e].c;
			if(c>0 && !vis[v])
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
			edges[par[i]].c-=MinCut;
			edges[par[i]^1].c+=MinCut;
		}
	}
	return Flow;
}
void DivideNumber(int i)
{
	int j,k;
	for(j=0;j<primes.size();j++)
	{
		k=0;
		while(a[i]%primes[j]==0) k++,a[i]/=primes[j];
		Number[i].push_back(k);
	}
	if(a[i]>1)
	{
		primes.push_back(a[i]);
		for(j=1;j<i;j++) Number[j].push_back(0);
		Number[i].push_back(1);
	}
}
vector< pair<int,int> > pairs;
int sol;
int main()
{
	int n,m,i,u,v,j;
	scanf("%i %i",&n,&m);
	FindPrimes();
	for(i=1;i<=n;i++) scanf("%i",&a[i]),DivideNumber(i);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		pairs.push_back(make_pair(u,v));
	}
	for(j=0;j<primes.size();j++)
	{
		Init();
		for(i=1;i<=n;i++)
		{
			if(i%2==0)
				AddEdge(s,i,Number[i][j]);
			else
				AddEdge(i,t,Number[i][j]);
		}
		for(i=0;i<m;i++)
		{
			if(pairs[i].first%2==0)
				AddEdge(pairs[i].first,pairs[i].second,inf);
			else AddEdge(pairs[i].second,pairs[i].first,inf);
		}
		sol+=MaxFlow();
	}
	printf("%i\n",sol);
	return 0;
}