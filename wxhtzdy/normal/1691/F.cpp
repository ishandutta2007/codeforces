#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 200050;

int fact[MAXN];

int norm(int a){
	a %= mod;
	return a < 0 ? a + mod : a;
}

int add(int a, int b) {
	a = norm(a); b = norm(b);
	return a + b >= mod ? a + b - mod : a + b;
}

int sub(int a, int b) {
	a = norm(a); b = norm(b);
	return a - b < 0 ? a - b + mod : a - b;
}

int mul(int a, int b) {
	return (lint) a * b % mod;
}

int ipow(int a, int p){
	int ans = 1;
	for(; p; p /= 2, a = mul(a, a)){
		if (p & 1) ans = mul(ans, a);
	}
	return ans;
}

int inv(int a){ return ipow(a, mod - 2); }

int C(int n, int k){
	if(n < k) return 0;
	return mul(mul(fact[n], inv(fact[k])), inv(fact[n - k]));
}

void init(){
	fact[0] = 1;
	for(int i = 1; i < MAXN; i++) fact[i] = mul(fact[i - 1], i);
}

int n, k, sz[MAXN], dp[MAXN];
vector<int> gph[MAXN];

void dfs(int x, int p){
	sz[x] = 1;
	int ways = 0;
	for(auto &y : gph[x]){
		if(y == p) continue;
		dfs(y, x);
		sz[x] += sz[y];
		ways = sub(ways, C(sz[y], k));
	}
	ways = add(ways, C(sz[x], k));
	dp[1] = add(dp[1], mul(ways, sz[x]));
}

void solve(int x, int p){
	int ways = C(sz[x], k);
	for(auto& y : gph[x]){
		if(y == p) continue;
		ways = sub(ways, C(sz[y], k));
	}
	if(x != p) ways = sub(ways, C(sz[p], k));
	for(auto &y : gph[x]){
		if(y == p) continue;
		dp[x] = sub(dp[x], mul(ways, sz[x]));
		ways = sub(ways, C(sz[x], k));
		ways = add(ways, C(sz[y], k));
		int wways = C(sz[y], k);
		for(auto &z : gph[y]){
			if(z == x) continue;
			wways = sub(wways, C(sz[z], k));
		}
		dp[x] = sub(dp[x], mul(wways, sz[y]));
		sz[x] -= sz[y];
		sz[y] += sz[x];
		ways = add(ways, C(sz[x], k));
		dp[x] = add(dp[x], mul(ways, sz[x]));
		wways = sub(C(sz[y], k), C(sz[x], k));
		for(auto &z : gph[y]){
			if(z == x) continue;
			wways = sub(wways, C(sz[z], k));
		}
		dp[y] = add(dp[x], mul(wways, sz[y]));
		solve(y, x);
		dp[x] = sub(dp[x], mul(ways, sz[x]));
		ways = sub(ways, C(sz[x], k));
		sz[y] -= sz[x];
		sz[x] += sz[y];
		wways = C(sz[y], k);
		for(auto &z : gph[y]){
			if(z == x) continue;
			wways = sub(wways, C(sz[z], k));
		}
		dp[x] = add(dp[x], mul(wways, sz[y]));
		ways = sub(ways, C(sz[y], k));
		ways = add(ways, C(sz[x], k));
		dp[x] = add(dp[x], mul(ways, sz[x]));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		gph[x].push_back(y);
		gph[y].push_back(x);
	}
	init();
	dfs(1, 1);
	solve(1, 1);
	int sum = 0;
	for(int i = 1; i <= n; i++) sum = add(sum, dp[i]);
	cout << sum << "\n";
}