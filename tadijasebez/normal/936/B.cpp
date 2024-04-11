#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N],G[N];
bool Cycle;
int col[N];
void DFS(int u)
{
	col[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!col[v]) DFS(v);
		if(col[v]==1) Cycle=1;
	}
	col[u]=2;
}
int dist[N][2],go[N][2],in[N];
int main()
{
	int n,m,b,i,x;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&b);
		while(b--) scanf("%i",&x),E[x].push_back(i),in[i]++,G[i].push_back(x);
	}
	for(b=0;b<2;b++) for(i=1;i<=n;i++) dist[i][b]=N;
	queue< pair<int,int> > q;
	for(i=1;i<=n;i++) if(!in[i]) q.push(make_pair(i,1)),dist[i][1]=0;
	while(!q.empty())
	{
		int u=q.front().first;
		int t=q.front().second;
		q.pop();
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(dist[v][t^1]>=N)
			{
				dist[v][t^1]=dist[u][t]+1;
				go[v][t^1]=u;
				q.push(make_pair(v,t^1));
			}
		}
	}
	int s;
	scanf("%i",&s);
	if(dist[s][0]!=N)
	{
		printf("Win\n");
		int u=s,t=0;
		while(u)
		{
			printf("%i ",u);
			u=go[u][t];
			t^=1;
		}
	}
	else
	{
		DFS(s);
		if(Cycle) printf("Draw\n");
		else printf("Lose\n");
	}
	return 0;
}