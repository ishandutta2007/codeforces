#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=998244353;
const int N=500050;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int add(int x, int y, int z){ return add(add(x,y),z);}
int mul(int x, int y){ return (ll)x*y%mod;}
int mul(int x, int y, int z){ return mul(mul(x,y),z);}
int dp[N][2],sz[N],po[N];
vector<int> E[N];
void DFS(int u, int p)
{
	dp[u][0]=1;
	dp[u][1]=0;
	sz[u]=1;
	for(int v:E[u]) if(v!=p)
	{
		DFS(v,u);
		tie(dp[u][0],dp[u][1])=mp(mul(dp[u][0],add(dp[v][0],dp[v][1],dp[v][1])),add(mul(dp[u][0],dp[v][0]),mul(dp[u][1],2,add(dp[v][0],dp[v][1]))));
		sz[u]+=sz[v];
	}
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	po[0]=1;for(i=1;i<=n;i++) po[i]=mul(po[i-1],2);
	DFS(1,0);
	int ans=0;
	for(i=1;i<=n;i++) ans=add(ans,mul(po[n-sz[i]],dp[i][1]));
	ans=mul(ans,2);
	printf("%i\n",ans);
	return 0;
}