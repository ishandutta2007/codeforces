#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll n, i, x, y, dp[MN][2], p[MN], ans;
vector<int> adj[MN];

void solve(int n, int p){
	dp[n][0] = 1;
	for(auto v : adj[n]){
		if(v == p) continue;
		solve(v, n);
		ans += dp[v][0]*dp[n][0]+dp[v][1]*dp[n][1];
		dp[n][0] += dp[v][1]; dp[n][1] += dp[v][0];
	}
}

int main(){
	for(scanf("%lld",&n);i<n-1;i++){
		scanf("%lld%lld",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	solve(1, 0);
	printf("%lld\n",ans-n+1);
	return 0;
}