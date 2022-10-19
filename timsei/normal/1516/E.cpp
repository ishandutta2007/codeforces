#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
const int mod = 1e9 + 7;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) { x = add(x + y); }
	void Sub(int &x, int y) { x = sub(x - y); }
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod)
		if(y & 1)
		res = 1LL * res * x % mod;
		return res;
	}
}

int dp[N * 2][N * 2], n, m, k, C[N * 2][N * 2], ans[N * 2];

int main() {
	cin >> m >> k;
	n = k * 2;
	C[0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++ j)
		C[i][j] = add(C[i - 1][j - 1] + C[i - 1][j]);
	}
	
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[2][0] = dp[2][1] = 1;
	for(int i = 3; i <= n; ++ i) {
		dp[i][0] = 1;
		for(int j = 1; j <= k; ++ j) {
			dp[i][j] = add(dp[i - 1][j] + 1LL * (i - 1) * dp[i - 1][j - 1] % mod);
		}
	}
	
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= n; ++ j) {
			Add(dp[i][j + 2], dp[i][j]);
		}
	}
/*	if(m <= n) {
		for(int i = 1; i <= k; ++ i) printf("%d ", dp[m][i]);
		puts("");
		return 0;
	}*/
	
	int cur = 1;
	
	for(int i = 0; i <= min(n, m); ++ i) {
		if(i)
		cur = 1LL * cur * (m - i + 1) % mod * Pow(i) % mod;
		for(int j = 0; j <= k; ++ j) {
			for(int kk = 0; kk < i; ++ kk) {
				Sub(dp[i][j], dp[kk][j] * 1ll * C[i][kk] % mod);
			}
		}
//		cerr << i <<' ' << cur <<' ' << dp[i][1] <<' ' << dp[i][2] << endl;
		for(int j = 1; j <= k; ++ j) Add(ans[j], 1LL * dp[i][j] * cur % mod);
	}
	for(int i = 1; i <= k; ++ i) printf("%d ", ans[i]);
	puts("");
}