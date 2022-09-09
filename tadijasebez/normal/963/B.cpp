#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=200050;
int was[N],par[N];
vector<int> E[N],sol;
void Take(int u)
{
	sol.pb(u);was[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!was[v]) Take(v);
	}
}
void DFS(int u)
{
	int deg=0;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);
		if(!was[v]) deg++;
	}
	if(par[u]) deg++;
	if(!(deg&1) && u) Take(u);
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&par[i]),E[par[i]].pb(i);
	DFS(0);
	if(sol.size()<n) printf("NO\n");
	else 
	{
		printf("YES\n");
		for(i=0;i<sol.size();i++) printf("%i\n",sol[i]);
	}
	return 0;
}