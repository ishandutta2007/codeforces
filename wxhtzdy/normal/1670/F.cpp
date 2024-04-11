#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 2005;
const int MAXL = 61;

int fact[MAXN], ifact[MAXN];

int norm(int a){
	a %= mod;
	return a < 0 ? a + mod : a;
}

int add(int a, int b) {
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
	return mul(mul(fact[n], ifact[k]), ifact[n - k]);
}

void init(){
	fact[0] = 1;
	for(int i = 1; i < MAXN; i++) fact[i] = mul(fact[i - 1], i);
	for(int i = 0; i < MAXN; i++) ifact[i] = inv(fact[i]);
}

int n, dp[MAXL][MAXN];
lint l, r, z;

int solve(int bit, int cur, int S){
	if(cur < 0) return 0;
	if(bit < 0) return 1;
	if(dp[bit][cur] != -1) return dp[bit][cur];
	int res = 0, zb = ((z >> bit & 1) > 0 ? 1 : 0);
	for(int cc = zb; cc <= n; cc += 2){
		int sb = ((S >> bit & 1) > 0 ? 1 : 0);
		int ncur = 2 * (cur - cc + sb);
		res = add(res, mul(C(n, cc), solve(bit - 1, min(2 * n, ncur), S)));
	}
	return dp[bit][cur] = res;
}

int calc(int S){
	for(int i = 0; i < MAXL; i++){
		for(int j = 0; j < MAXN; j++){
			dp[i][j] = -1;
		}
	}
	return solve(MAXL - 1, 0, S);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin >> n >> l >> r >> z;
	cout << sub(calc(r), calc(l - 1)) << "\n";
}