#include <iostream>

#define add(x, y) x + y >= MOD ? x + y - MOD : x + y

typedef long long ll;

int n, m, b, MOD;
int dp[2][505][505];
int a[505];

int main() {
	std::cin >> n >> m >> b >> MOD;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	dp[0][0][0] = 1;
	for(int i = 1; i <= m; i++) {
		int cur = i & 1;
		int lst = 1 - cur;
		for(int k = 0; k <= b; k++) {
			for(int j = 0; j < n; j++) {
				dp[cur][j][k] = 0;
				dp[lst][j + 1][k] = add(dp[lst][j][k], dp[lst][j + 1][k]);
			}
		}
		for(int j = 0; j < n; j++) {
			for(int k = 0; k + a[j] <= b; k++) {
				dp[cur][j][k + a[j]] = add(dp[cur][j][k + a[j]], dp[lst][j][k]);
			}
		}
		/*std::cout << "------------\n";
		for(int j = 0; j < n; j++) {
			for(int k = 0; k <= b; k++) {
				std::cout << dp[cur][j][k] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << "------------\n";*/
	}
	int ans = 0;
	for(int j = 0; j < n; j++) {
		for(int i = 0; i <= b; i++) {
			ans = add(ans, dp[m & 1][j][i]);
		}
	}
	std::cout << ans << '\n';
}