#include<bits/stdc++.h>
#define ll long long

const int N = 16;

ll dp[N][1 << N][N];

ll getdp(int u, int v, int w){
	if (~dp[u][v][w]){
		return dp[u][v][w];
	}
	if (!w){
		return dp[u][v][w] = v >> u & 1;
	}
	ll ret = 0;
	for (int i = 0; i < N; ++ i){
		ret += getdp(std::max(u, i), (v * N + i) % (1 << N), w - 1);
	}
	return dp[u][v][w] = ret;
}
	
ll getans(ll n){
	if (n <= 0){
		return 0;
	}
	ll ret = 0;
	int a[N], len = 0;
	while (n){
		a[len ++] = n % N;
		n /= N;
	}
	int u = 0, v = 0;
	for (int i = len - 1; i >= 0; -- i){
		for (int j = 0; j < a[i]; ++ j){
			ret += dp[std::max(u, j)][(v * N + j) % (1 << N)][i];
		}
		u = std::max(u, a[i]);
		v = (v * N + a[i]) % (1 << N);
	}
	ret += dp[u][v][0];
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	getdp(0, 0, N - 1);
	int q;
	scanf("%d", &q);
	while (q --){
		ll l, r;
		scanf("%I64x%I64x", &l, &r);
		printf("%I64d\n", getans(r) - getans(l - 1));
	}
	return 0;
}