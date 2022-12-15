#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5;
struct pii{ll f, s;}dp[MN];
ll N, p[MN], i, x, y;
vector<ll> adj[MN];

void solve(ll n, ll par){
	for(auto v : adj[n]){
		if(v == par) continue;
		solve(v, n);
		dp[n].f = max(dp[n].f,dp[v].f);
		dp[n].s = max(dp[n].s,dp[v].s);
	}
	p[n] += dp[n].f-dp[n].s;
	if(p[n]>0) dp[n].s+=p[n];
	else dp[n].f+=-p[n];
}

int main(){
	for(scanf("%lld",&N),i=0;i<N-1;i++){
		scanf("%lld%lld",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++) scanf("%lld",&p[i]);
	solve(1,0);
	printf("%lld\n",abs(dp[1].f+dp[1].s));
	return 0;
}