#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 1010;

int dp[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		dp[0][i] = 1;
	}
	for(int i = 1; i < ms; i++) {
		for(int j = 2; j < ms; j++) {
			dp[i][j] = (int) ((2LL * dp[i][j-1] - dp[i][j-2] + dp[i-1][j-2]) % MOD + MOD) % MOD;
		}
	}
	int n, m, k;
	std::cin >> n >> m >> k;
	std::cout << (long long) dp[k][n] * dp[k][m] % MOD << '\n';
}