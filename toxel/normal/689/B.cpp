#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 200010
using namespace std;
queue<int>q;
typedef struct edge
{
	int next,to;
};
typedef struct point
{
	int first,dis,visited;
};
edge edg[3*N];
point poi[N];
int e;
void addedge(int u,int v)
{
	edg[++e].to=v;
	edg[e].next=poi[u].first;
	poi[u].first=e;
}
void dfs(int i)
{
	int j;
	poi[i].visited=true;
	for (j=poi[i].first;j;j=edg[j].next)
	{
		if (poi[edg[j].to].dis>poi[i].dis+1)
		{
			poi[edg[j].to].dis=poi[i].dis+1;
			q.push(edg[j].to);
		}
		if (!poi[edg[j].to].visited)
			dfs(edg[j].to);
	}
}
void bfs()
{
	int i,j;
	while (!q.empty())
	{
		for (i=q.front(),q.pop(),j=poi[i].first;j;j=edg[j].next)
			if (poi[edg[j].to].dis>poi[i].dis+1)
			{
				q.push(edg[j].to);
				poi[edg[j].to].dis=poi[i].dis+1;
			}
	}
}
int main()
{
	int n,i,a;
	scanf("%d",&n);
	for (i=1;i<=n-1;i++)
	{
		addedge(i,i+1);
		addedge(i+1,i);
	}
	for (i=1;i<=n;i++)
	{
		poi[i].dis=i-1;
		poi[i].visited=false;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if (i!=a)
			addedge(i,a);
	}
	dfs(1);
	bfs();
	for (i=1;i<=n;i++)
		printf("%d ",poi[i].dis);
	return 0;
}