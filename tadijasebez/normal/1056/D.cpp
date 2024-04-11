#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int par[N],sz[N];
vector<int> E[N];
void DFS(int u, int p)
{
	sz[u]=0;
	for(int v:E[u]) if(v!=p) DFS(v,u),sz[u]+=sz[v];
	sz[u]=max(sz[u],1);
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&par[i]),E[par[i]].pb(i);
	DFS(1,0);
	sort(sz+1,sz+1+n);
	for(int i=1;i<=n;i++) printf("%i ",sz[i]);
	return 0;
}