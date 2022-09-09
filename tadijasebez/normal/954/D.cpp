#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
const int N=1050;
const int inf=1e9;
int dist[N][N],n;
vector<int> E[N];
queue<int> q;
void BFS(int u)
{
	int i;
	for(i=1;i<=n;i++) dist[u][i]=inf;
	dist[u][u]=0;
	q.push(u);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<E[x].size();i++)
		{
			int v=E[x][i];
			if(dist[u][v]>dist[u][x]+1)
			{
				dist[u][v]=dist[u][x]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	int m,u,v,i,s,t,sol=0;
	scanf("%i %i %i %i",&n,&m,&s,&t);
	while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=n;i++) BFS(i);
	for(u=1;u<=n;u++)
	{
		for(v=u+1;v<=n;v++)
		{
			if(dist[u][v]>1 && dist[s][u]+1+dist[v][t]>=dist[s][t] && dist[s][v]+1+dist[u][t]>=dist[s][t]) sol++;
		}
	}
	printf("%i\n",sol);
	return 0;
}