#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
vector<int> E[N];
int a[N];
ll dep[N],sz[N],sum[N];
void DFS(int u, int p)
{
	if(p) dep[u]=(dep[p]/a[p]+1)*a[u];
	else dep[u]=a[u];
	sz[u]=a[u];
	for(int v:E[u]) if(v!=p) DFS(v,u),sz[u]+=sz[v];
}
ll ans,dsum;
int n;
void Solve(int u, int p)
{
	if(p==0) sum[u]=dsum-sz[u]*2;
	else sum[u]=sum[p]-sz[u]*2;
	ans=max(ans,sum[u]+dep[u]/a[u]*sz[1]);
	for(int v:E[u]) if(v!=p) Solve(v,u);
}
int main()
{
	int i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[v].pb(u),E[u].pb(v);
	DFS(1,0);
	for(i=1;i<=n;i++) dsum+=dep[i];
	Solve(1,0);
	printf("%lld\n",ans);
	return 0;
}