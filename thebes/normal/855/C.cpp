#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN=1e5+5,mod=1e9+7;
int n, m, k, x, y, i, dp[MN][3][11], tot[MN][3], tmp[3][11];
vector<int> adj[MN];

void solve(int n, int p){
	dp[n][0][0] = k-1;
	dp[n][1][1] = 1;
	dp[n][2][0] = m-k;
	for(auto v : adj[n]){
		if(v == p) continue;
		solve(v, n); memset(tmp,0,sizeof(tmp));
		for(int a=x;a>=0;a--){
			for(int b=a;b>=0;b--){
				tmp[0][a]=(tmp[0][a]+dp[n][0][a-b]*tot[v][b])%mod;
				tmp[1][a]=(tmp[1][a]+dp[n][1][a-b]*dp[v][0][b])%mod;
				tmp[2][a]=(tmp[2][a]+dp[n][2][a-b]*(dp[v][0][b]+dp[v][2][b]))%mod;
			}
		}
		for(int a=x;a>=0;a--){
			for(int wtf=0;wtf<3;wtf++)
				dp[n][wtf][a]=tmp[wtf][a];
		}
	}
	for(int i=0;i<=x;i++)
		tot[n][i]=(dp[n][0][i]+dp[n][1][i]+dp[n][2][i])%mod;
}

signed main(){
	for(scanf("%lld%lld",&n,&m),i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	scanf("%lld%lld",&k,&x);
	solve(1, 0);
	int ans = 0;
	for(int i=0;i<=x;i++)
		ans = (ans+tot[1][i])%mod;
	printf("%lld\n",ans);
	return 0;
}