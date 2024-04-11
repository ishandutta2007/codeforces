#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
const int N=200050;
vector<int> E[N];
bool ok=0;
bool vis[N];
void DFS(int u)
{
	if(E[u].size()!=2) ok=0;
	vis[u]=1;
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
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	int sol=0;
	for(i=1;i<=n;i++) if(!vis[i]) ok=1,DFS(i),sol+=ok;
	printf("%i\n",sol);
	return 0;
}