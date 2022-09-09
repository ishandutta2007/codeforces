#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N];
int dist[N],ans;
int max(int a, int b){ return a>b?a:b;}
void DFS(int u, int p, int d)
{
	int best=d;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p)
		{
			DFS(v,u,d+1);
			ans=max(ans,best+dist[v]-2*d);
			best=max(best,dist[v]);
		}
	}
	dist[u]=best;
}
int main()
{
	int n,m,u,v,i;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0,0);
	printf("%i\n",ans);
	return 0;
}