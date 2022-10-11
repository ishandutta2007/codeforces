#include <iostream>

#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)

typedef long long ll;

const int MOD = 1e9 + 7;

int dp[340][340];

int main() {
	int n, m, x;
	std::cin >> n >> m >> x;
	std::swap(n, m);
	if(n < m) {
		std::cout << "0\n";
		return 0;
	}
	x = n - x + 1;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = m; j >= 0; j--) {
			for(int k = m; k >= 0; k--) {
				if(i == x) {
					if(j) {
						dp[j][k] = add(dp[j - 1][k], dp[j - 1][k + 1]);
					} else {
						dp[j][k] = 0;
					}
				} else {
					if(j) {
						dp[j][k] = add(dp[j][k], dp[j - 1][k]);
						dp[j][k] = add(dp[j][k], dp[j - 1][k + 1]);
					}
					if(k) {
						dp[j][k] = add(dp[j][k], dp[j][k - 1]);
					}
				}
				//if(dp[j][k])
				//std::cout << "dp(" << i << ", " << j << ", " << k << ") = " << dp[j][k] << "\n";
			}
		}
	}
	ll ans = dp[m][0];
	for(int i = 1; i <= m; i++) {
		ans = ans * i % MOD;
	}
	std::cout << ans << '\n';
}