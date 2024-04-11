#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N],sol[2];
int dist[N];
bool vis[N],ok=true;
void DFS(int u, int d)
{
	dist[u]=d;
	sol[d].push_back(u);
	vis[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v,d^1);
		else if(d==dist[v]) ok=false;
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=n;i++) if(!vis[i]) DFS(i,0);
	if(ok)
	{
		printf("%i\n",sol[0].size());
		for(i=0;i<sol[0].size();i++) printf("%i ",sol[0][i]);
		printf("\n");
		printf("%i\n",sol[1].size());
		for(i=0;i<sol[1].size();i++) printf("%i ",sol[1][i]);
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}