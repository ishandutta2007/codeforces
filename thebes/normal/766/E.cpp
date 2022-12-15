#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5,LG=28;
typedef long long ll;
ll N, val[MN], dp[MN][LG], tot[MN], i, x, y, ans;
vector<int> adj[MN];

void solve(int n,int p){
	ans+=val[n]; tot[n]++;
	for(int i=LG-1;i>=0;i--)
		if((1<<i)&val[n]) dp[n][i]++;
	for(auto v : adj[n]){
		if(v == p) continue;
		solve(v, n);
		for(int i=LG-1;i>=0;i--){
			ans+=(1LL<<i)*dp[n][i]*(tot[v]-dp[v][i]);
			ans+=(1LL<<i)*(tot[n]-dp[n][i])*dp[v][i];
			if((1<<i)&val[n]) dp[n][i] += tot[v]-dp[v][i];
			else dp[n][i] += dp[v][i];
		}
		tot[n] += tot[v];
	}
}

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&val[i]);
	for(i=1;i<N;i++){
		scanf("%lld%lld",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	solve(1, 0);
	printf("%lld\n",ans);
	return 0;
}