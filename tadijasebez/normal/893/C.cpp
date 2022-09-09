#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int inf=1e9+69;
const int N=100050;
int min(int a, int b){ return a>b?b:a;}
vector<int> E[N];
int ans,c[N];
ll sol;
bool vis[N];
void DFS(int u)
{
	vis[u]=1;
	ans=min(ans,c[u]);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v);
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans=inf;
			DFS(i);
			sol+=ans;
		}
	}
	printf("%lld\n",sol);
	return 0;
}