#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=50050;
vector<int> E[N];
int par[N];
void DFS(int u, int p){ par[u]=p;for(int i=0;i<E[u].size();i++){ int v=E[u][i];if(v!=p) DFS(v,u);}}
int main()
{
	int n,u,i,r1,r2;
	scanf("%i %i %i",&n,&r1,&r2);
	for(i=1;i<=n;i++) if(i!=r1) scanf("%i",&u),E[u].pb(i),E[i].pb(u);
	DFS(r2,0);
	for(i=1;i<=n;i++) if(i!=r2) printf("%i ",par[i]);
	return 0;
}