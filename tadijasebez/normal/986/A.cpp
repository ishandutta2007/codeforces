#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define pb push_back
const int N=100050;
const int inf=1e9+7;
int dist[N],col[N];
vector<int> E[N],cost[N];
queue<int> q;
void BFS(int k, int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(col[i]==k)
		{
			dist[i]=0;
			q.push(i);
		}
		else dist[i]=inf;
	}
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(dist[u]+1<dist[v])
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	for(i=1;i<=n;i++) cost[i].pb(dist[i]);
}
int main()
{
	int n,m,k,s,i,j,u,v;
	scanf("%i %i %i %i",&n,&m,&k,&s);
	for(i=1;i<=n;i++) scanf("%i",&col[i]);
	while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=k;i++) BFS(i,n);
	for(i=1;i<=n;i++)
	{
		sort(cost[i].begin(),cost[i].end());
		int sol=0;
		for(j=0;j<s;j++) sol+=cost[i][j];
		printf("%i ",sol);
	}
	printf("\n");
	return 0;
}