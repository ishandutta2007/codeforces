#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=400050;
vector<int> E[N];
bool was[N];
void DFS(int u)
{
	was[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!was[v]) DFS(v);
	}
}
int main()
{
	int n,m,q,i,x,y;
	scanf("%i %i %i",&n,&m,&q);
	while(q--) scanf("%i %i",&x,&y),E[x].pb(y+n),E[y+n].pb(x);
	int sol=0;
	for(i=1;i<=n+m;i++) if(!was[i]) DFS(i),sol++;
	printf("%i\n",sol-1);
	return 0;
}