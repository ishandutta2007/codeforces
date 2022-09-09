#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
vector<int> E[N];
int c[N],ans,dep[N];
int max(int a, int b){ return a>b?a:b;}
void DFS(int u, int p, int d)
{
	int Best=d;
	dep[u]=d;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p)
		{
			DFS(v,u,d+(c[u]^c[v]));
			ans=max(ans,dep[v]+Best-2*dep[u]);
			Best=max(Best,dep[v]);
		}
	}
	dep[u]=Best;
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0,0);
	printf("%i\n",(ans+1)/2);
	return 0;
}