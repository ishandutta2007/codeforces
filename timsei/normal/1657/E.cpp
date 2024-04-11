#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;

int dp[255][255], n, k, ans = 0, C[1005][1005];

int add(int x) {return (x >= mod) ?x - mod : x;}

void prework(int n) {
	C[0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++ j)
		C[i][j] = add(C[i - 1][j - 1] + C[i - 1][j]);
	}
}

int Pow(int x, int y) {
	int res = 1;
	for(; y; y >>= 1, x = 1LL * x * x % mod) {
		if(y & 1)
		res = 1LL * res * x % mod;
	}
	return res;
}

int main() {
	int t;
	cin >> n >> k;
	prework(1000);
	dp[1][0] = 1;
	for(int i = 1; i <= k; ++ i) {
		for(int j = 0; j < n; ++ j) {
			if(!dp[i][j]) continue;
			for(int p = 0; p <= n - 1 - j; ++ p) {
				int kk = k - i, pp = n - 1 - j - p;
				int it = 0;
				if(kk - 1 < 0) {
					if(pp) it = 0;
					else it = 1;
				} else it = 1;
				dp[i + 1][j + p] = add(dp[i + 1][j + p] + 1LL * it * dp[i][j] % mod * 
				Pow(i, p * pp + p * (p - 1) / 2) % mod * C[n - 1 - j][p] % mod);
			}
		}
	}
	cout << dp[k + 1][n - 1] << endl;
}