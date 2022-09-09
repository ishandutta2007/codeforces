#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=100050;
int sol,sz[N];
vector<int> E[N];
void DFS(int u, int p)
{
	sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),sz[u]+=sz[v];
	}
	if(sz[u]%2==0) sol++;
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	if(n&1) printf("-1\n");
	else DFS(1,0),printf("%i\n",sol-1);
	return 0;
}