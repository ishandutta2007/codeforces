#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=100050;
vector<int> E[N];
int deg[N];
void AddEdge(int u, int v){ E[u].pb(v);E[v].pb(u);deg[u]++;deg[v]++;}
vector<int> leaf;
void DFS(int u, int p)
{
	int x=0;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),x++;
	}
	if(!x) leaf.pb(u);
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),AddEdge(u,v);
	int cnt=0,taj=1;;
	for(i=1;i<=n;i++) if(deg[i]>2) taj=i,cnt++;
	if(cnt>1) return printf("No\n"),0;
	DFS(taj,0);
	printf("Yes\n");
	printf("%i\n",leaf.size());
	for(i=0;i<leaf.size();i++) printf("%i %i\n",taj,leaf[i]);
	return 0;
}