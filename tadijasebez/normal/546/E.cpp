#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
	vector<int> edges;
	int val;
} Graph[205];
int ReversedGraph[205][205];
const int inf=100000000;
void SetReversedGraph(int n, int s, int t)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		//printf("%i\n",i);
		ReversedGraph[s][i]=Graph[i].val;
		for(j=0;j<Graph[i].edges.size();j++)
		{
			ReversedGraph[i][Graph[i].edges[j]]=inf;
		}
	}
	for(i=n;i<n*2;i++)
	{
		//printf("%i\n",i);
		ReversedGraph[i][t]=Graph[i].val;
	}
	for(i=0;i<n;i++) ReversedGraph[i][n+i]=inf;
}
int parent[205];
bool visited[205];
queue<int> q;
bool BFS(int n, int s, int t)
{
	int i;
	for(i=0;i<n*2+2;i++)
	{
		visited[i]=false;
	}
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int x=q.front();
		//printf("%i\n",x);
		q.pop();
		for(i=0;i<n*2+2;i++)
		{
			if(!visited[i] && ReversedGraph[x][i]>0)
			{
				visited[i]=true;
				parent[i]=x;
				q.push(i);
			}
		}
	}
	return visited[t];
}
void Solve(int n)
{
	int s=n*2;
	int t=n*2+1;
	int i,j;
	SetReversedGraph(n,s,t);
	int MaxFlow=0;
	while(BFS(n,s,t))
	{
		int MinCut=inf;
		for(i=t;i!=s;i=parent[i])
		{
			if(MinCut>ReversedGraph[parent[i]][i])
				MinCut=ReversedGraph[parent[i]][i];
		}
		MaxFlow+=MinCut;
		//printf("%i %i\n",MinCut,MaxFlow);
		for(i=t;i!=s;i=parent[i])
		{
			ReversedGraph[parent[i]][i]-=MinCut;
			ReversedGraph[i][parent[i]]+=MinCut;
		}
	}
	int a=0,b=0;
	for(i=0;i<n;i++) a+=Graph[i].val;
	for(i=n;i<2*n;i++) b+=Graph[i].val;
	if(a!=b || MaxFlow!=a || MaxFlow!=b)
	{
		printf("NO\n");
		return;
	}
	else
	{
		printf("YES\n");
		for(i=0;i<n;i++)
		{
			for(j=n;j<n*2;j++)
			{
				printf("%i ",ReversedGraph[j][i]);
			}
			printf("\n");
		}
		return;
	}
}
int main()
{
	int n,m,i,j,u,v;
	scanf("%i%i",&n,&m);
	for(i=0;i<n;i++) scanf("%i",&Graph[i].val);
	for(i=n;i<n*2;i++) scanf("%i",&Graph[i].val);
	for(i=0;i<m;i++)
	{
		scanf("%i %i",&u,&v);
		u--;
		v--;
		Graph[u].edges.push_back(n+v);
		Graph[v].edges.push_back(n+u);
	}
	Solve(n);
	return 0;
}