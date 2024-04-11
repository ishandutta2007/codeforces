#include<bits/stdc++.h>
using namespace std;
const int N=300005,mod=998244353;
int n,f[N][3],g[3];
vector<int>e[N];
void dfs(int u,int fa)
{
	f[u][0]=1;
	for(auto v:e[u])
	{
		if(v==fa)
			continue;
		dfs(v,u);
		g[0]=1ll*f[u][0]*(f[v][0]+f[v][2])%mod;
		g[1]=(1ll*f[u][0]*f[v][2]%mod+1ll*f[u][1]*(2ll*f[v][2]+f[v][0])%mod)%mod;
		g[2]=(1ll*f[u][0]*(f[v][0]+f[v][1])%mod+1ll*f[u][1]*(f[v][0]+f[v][1])%mod+1ll*f[u][2]*(2ll*f[v][2]+f[v][0])%mod)%mod;
		swap(f[u],g);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",(f[1][0]+f[1][2])%mod);
	return 0;
}