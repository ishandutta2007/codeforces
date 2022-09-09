#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=3050;
const int inf=1e9+7;
vector<int> E[N];
queue<int> q;
int n,dist[N][N];
void BFS(int u)
{
	int i;
	for(i=1;i<=n;i++) dist[u][i]=inf;
	q.push(u);
	dist[u][u]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<E[x].size();i++)
		{
			int y=E[x][i];
			if(dist[u][y]>dist[u][x]+1)
			{
				dist[u][y]=dist[u][x]+1;
				q.push(y);
			}
		}
	}
}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int m,i,j,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),E[u].push_back(v),E[v].push_back(u);
	int s1,t1,l1,s2,t2,l2;
	scanf("%i %i %i",&s1,&t1,&l1);
	scanf("%i %i %i",&s2,&t2,&l2);
	for(i=1;i<=n;i++) BFS(i);
	if(dist[s1][t1]>l1) return printf("-1\n"),0;
	if(dist[s2][t2]>l2) return printf("-1\n"),0;
	int sol=m-dist[s1][t1]-dist[s2][t2];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			int ans;
			if(dist[s1][i]+dist[t1][j]+dist[i][j]<=l1 && dist[s2][i]+dist[t2][j]+dist[i][j]<=l2)
			{
				ans=m-dist[s1][i]-dist[t1][j]-dist[s2][i]-dist[t2][j]-dist[i][j];
				sol=max(sol,ans);
			}
			if(dist[s1][j]+dist[t1][i]+dist[i][j]<=l1 && dist[s2][i]+dist[t2][j]+dist[i][j]<=l2)
			{
				ans=m-dist[s1][j]-dist[t1][i]-dist[s2][i]-dist[t2][j]-dist[i][j];
				sol=max(sol,ans);
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}