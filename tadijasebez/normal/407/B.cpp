#include <stdio.h>
const int N=1005;
const int mod=1e9+7;
int dp[N][N],p[N];
bool vis[N][N];
int DP(int u, int v)
{
	if(vis[u][v]) return dp[u][v];
	if(u==v) return 0;
	vis[u][v]=1;
	if(p[u]==u) return dp[u][v]=(2+DP(u+1,v))%mod;
	return dp[u][v]=(2+DP(p[u],u)+DP(u+1,v))%mod;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&p[i]);
	printf("%i\n",DP(1,n+1));
	return 0;
}