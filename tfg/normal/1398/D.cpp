#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 202;
int a[3][ms];
int dp[ms][ms][ms];

inline void go(int &v, int got) { v = std::max(v, got); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n[3];
	for(int i = 0; i < 3; i++) {
		std::cin >> n[i];
	}
	for(int rep = 0; rep < 3; rep++) {
		for(int i = 0; i < n[rep]; i++) {
			std::cin >> a[rep][i];
		}
		std::sort(a[rep], a[rep] + n[rep]);
		std::reverse(a[rep], a[rep] + n[rep]);
	}
	int ans = 0;
	for(int i = 0; i <= n[0]; i++) {
		for(int j = 0; j <= n[1]; j++) {
			for(int k = 0; k <= n[2]; k++) {
				go(dp[i+1][j+1][k], dp[i][j][k] + a[0][i] * a[1][j]);
				go(dp[i+1][j][k+1], dp[i][j][k] + a[0][i] * a[2][k]);
				go(dp[i][j+1][k+1], dp[i][j][k] + a[2][k] * a[1][j]);
				ans = std::max(ans, dp[i][j][k]);
				//std::cout << "at " << i << ", " << j << ", " << k << " got " << dp[i][j][k] << '\n';
			}
		}
	}
	std::cout << ans << '\n';
}