#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=500050;
set<int> Free;
vector<int> E[N],sol[N];
void DFS(int u, int c)
{
	Free.erase(u);
	sol[c].pb(u);
	int nxt=N;
	for(int i=(signed)E[u].size()-1;~i;i--)
	{
		for(int v=*Free.upper_bound(E[u][i]);v<nxt;v=*Free.upper_bound(E[u][i])) DFS(v,c);
		nxt=E[u][i];
	}
}
int c;
int main()
{
	int n,m,u,v,i,j;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=n;i++) Free.insert(i),E[i].pb(0),sort(E[i].begin(),E[i].end());
	Free.insert(N+1000);
	for(i=1;i<=n;i++) if(Free.count(i)) c++,DFS(i,c);
	printf("%i\n",c);
	for(i=1;i<=c;i++)
	{
		printf("%i ",sol[i].size());
		for(j=0;j<sol[i].size();j++) printf("%i ",sol[i][j]);
		printf("\n");
	}
	return 0;
}