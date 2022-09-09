#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int N=205;
const int s=201,t=202;
const int inf=1000000000;
const int S=20050;
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
			if(c && !vis[v])
			{
				par[v]=e;
				vis[v]=true;
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
			edges[par[i]].c--;
			edges[par[i]^1].c++;
		}
	}
	return Flow;
}
vector<int> Graph[N]; 
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i]) for(j=i*2;j<S;j+=i) sieve[j]=true;
	}
}
int a[N];
int odd,even;
bool used[N];
vector< vector<int> > ans;
vector<int> tmp;
void DFS(int cur)
{
	tmp.push_back(cur);
	used[cur]=true;
	int i;
	for(i=0;i<Graph[cur].size();i++)
	{
		int v=Graph[cur][i];
		if(!used[v]) DFS(v);
	}
}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]&1) odd++,AddEdge(i,t,2);
		else even++,AddEdge(s,i,2);
	}
	if(odd!=even) return printf("Impossible\n"),0;
	FindPrimes();
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==0)
		{
			for(j=1;j<=n;j++)
			{
				if(!sieve[a[i]+a[j]]) AddEdge(i,j,1);
			}
		}
	}
	if(odd+even!=MaxFlow()) return printf("Impossible\n"),0;
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==0)
		{
			for(j=0;j<Network[i].size();j++)
			{
				int e=Network[i][j];
				int v=edges[e].v;
				int c=edges[e].c;
				if(!c && v!=s && v!=t)
				{
					Graph[i].push_back(v);
					Graph[v].push_back(i);
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!used[i])
		{
			tmp.clear();
			DFS(i);
			ans.push_back(tmp);
		}
	}
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%i ",ans[i].size());
		for(j=0;j<ans[i].size();j++) printf("%i ",ans[i][j]);
		printf("\n");
	}
	return 0;
}