#include <iostream>

typedef long long ll;

const int MOD = 1e9 + 7;

int dp[101][101][101][3];
ll tot[101];
ll size[101];

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}
int main() {
	size[0] = size[1] = 2;
	for(int i = 2; i < 101; i++) {
		size[i] = size[i - 1] * size[i - 2] % MOD;
	}
	int n, k;
	std::string str;
	std::cin >> n >> k >> str;
	for(int i = 0; i < n; i++) {
		dp[str[i] - '0'][i][i + 1][0] = dp[str[i] - '0'][i][i + 1][1] = dp[str[i] - '0'][i][i + 1][2] = 1;
	}
	if(str == "0") {
		tot[0] = 1;
	} else if(str == "1") {
		tot[1] = 1;
	}
	for(int i = 2; i <= k; i++) {
		tot[i] = (tot[i - 1] * size[i - 2] + tot[i - 2] * size[i - 1]) % MOD;
		for(int l = 0; l <= n; l++) {
			for(int m = l; m <= n; m++) {
				dp[i][l][m][0] = ((ll)dp[i][l][m][0] + dp[i - 1][l][m][0] + size[i - 1] * dp[i - 2][l][m][0]) % MOD;
				dp[i][l][m][1] = ((ll)dp[i][l][m][1] + dp[i - 2][l][m][1] + size[i - 2] * dp[i - 1][l][m][1]) % MOD;
				dp[i][l][m][2] = ((ll)dp[i][l][m][2] + dp[i - 2][l][m][2] + dp[i - 1][l][m][2]) % MOD;
				for(int r = m; r <= n; r++) {
					dp[i][l][r][2] = (dp[i][l][r][2] + (ll)dp[i - 1][l][m][2] * dp[i - 2][m][r][2]) % MOD;
					dp[i][l][r][0] = (dp[i][l][r][0] + (ll)dp[i - 1][l][m][0] * dp[i - 2][m][r][2]) % MOD;
					dp[i][l][r][1] = (dp[i][l][r][1] + (ll)dp[i - 1][l][m][2] * dp[i - 2][m][r][1]) % MOD;
				}
			}
		}
		for(int m = 1; m < n; m++) {
			tot[i] = (tot[i] + (ll)dp[i - 1][0][m][0] * dp[i - 2][m][n][1]) % MOD;
		}
	}
	/*for(int i = 0; i <= k; i++) {
		for(int l = 0; l <= n; l++) {
			for(int r = l; r <= n; r++) {
				for(int k = 0; k < 3; k++) {
					if(dp[i][l][r][k]) {
						//std::cout << "(" << i << ", " << l << ", " << r << ", " << k << ") = " << dp[i][l][r][k] << "\n";
					}
				}
			}
		}
	}*/
	std::cout << tot[k] << '\n';
}