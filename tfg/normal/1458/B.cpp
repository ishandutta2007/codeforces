#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;

// dp[number of cups][sum of current] = max sum of max
int dp[ms][ms*ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int tot = 0;
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for(int x = 0; x < n; x++) {
		int a, b;
		std::cin >> a >> b;
		tot += b;
		for(int i = x; i >= 0; i--) {
			for(int j = 0; j <= 100 * i; j++) {
				if(dp[i][j] != -1) dp[i+1][j+b] = std::max(dp[i+1][j+b], dp[i][j] + a);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		int ans = 0;
		for(int j = 0; j <= 100 * i; j++) {
			if(dp[i][j] != -1) ans = std::max(ans, std::min(tot + j, dp[i][j] * 2));
		}
		std::cout << ans / 2 << '.' << ans % 2 * 5 << (i == n ? '\n' : ' ');
	}
}