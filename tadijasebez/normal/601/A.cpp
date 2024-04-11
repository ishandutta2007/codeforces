#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define pb push_back
const int N=405;
queue<int> q;
int dist[N];
bool vis[N];
vector<int> E[N];
int BFS(int n)
{
	int i;
	for(i=1;i<=n;i++) vis[i]=0,dist[i]=-1;
	dist[1]=0;
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<E[x].size();i++)
		{
			int v=E[x][i];
			if(!vis[v])
			{
				dist[v]=dist[x]+1;
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return dist[n];
}
bool Graph[N][N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,j,u,v;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u),Graph[u][v]=1,Graph[v][u]=1;
	int ans=BFS(n);
	if(ans==-1) return printf("-1\n"),0;
	for(i=1;i<=n;i++)
	{
		E[i].clear();
		for(j=1;j<=n;j++) if(!Graph[i][j]) E[i].pb(j);
	}
	int tmp=BFS(n);
	if(tmp==-1) return printf("-1\n"),0;
	ans=max(ans,tmp);
	printf("%i\n",ans);
	return 0;
}