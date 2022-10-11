#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const int ms = 1010;

inline void add(int &a, int b) {
	a = (a + b >= MOD ? a + b - MOD : a + b);
}

int dp[ms][2 * ms][4];

int cost[4][4];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, K;
	std::cin >> n >> K;
	dp[0][1][0] = dp[0][1][3] = 1;
	dp[0][2][1] = dp[0][2][2] = 1;
	cost[0][3] = 1;
	cost[0][1] = 1;
	cost[0][2] = 1;
	cost[3][0] = 1;
	cost[3][1] = 1;
	cost[3][2] = 1;
	cost[1][2] = 2;
	cost[2][1] = 2;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= K; j++) {
			for(int k = 0; k < 4; k++) {
				for(int kk = 0; kk < 4; kk++) {
					add(dp[i+1][j + cost[k][kk]][kk], dp[i][j][k]);
				}
			}
		}
	}
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j <= K; j++) {
			int cur = (dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3]);
			if(cur) {
				std::cout << "(" << i << ", " << j << ") has " << cur << std::endl;
			}
		}
	}*/
	std::cout << ((long long) dp[n-1][K][0] + (long long) dp[n-1][K][1] + (long long) dp[n-1][K][2] + (long long) dp[n-1][K][3]) % MOD;
}