#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN=2e5+5,mod=1e9+7;
ll N, val[MN], dp[MN][2], cnt[MN][2], i, x, y, ans;
vector<ll> adj[MN]; int c[5]={1,-1,1,-1,1};

void solve(ll n, ll p){
	dp[n][1] += val[n];
	cnt[n][1]++; ans+=val[n];
	for(auto v : adj[n]){
		if(v == p) continue;
		solve(v, n);
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				int w=(i+j+1)%2;
				ans=(ans+c[w]*cnt[v][i]*dp[n][j])%mod;
				ans=(ans+c[w]*cnt[n][i]*dp[v][j])%mod;
				ans=(ans+cnt[v][j]*dp[n][i])%mod;
				ans=(ans+cnt[n][j]*dp[v][i])%mod;
			}
		}
		cnt[n][0]+=cnt[v][1],cnt[n][1]+=cnt[v][0];
		dp[n][1]=(dp[n][1]+dp[v][0]+val[n]*cnt[v][0])%mod;
		dp[n][0]=(dp[n][0]+dp[v][1]-val[n]*cnt[v][1])%mod;
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
	if(ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;
}