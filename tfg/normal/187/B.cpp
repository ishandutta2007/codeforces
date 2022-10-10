#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 66;

int dp[ms][ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, r;
	std::cin >> n >> m >> r;
	memset(dp, 0x3f, sizeof dp);
	while(m--) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				std::cin >> dp[0][i][j];
			}
		}
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					dp[0][i][j] = std::min(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dp[1][i][j] = std::min(dp[1][i][j], dp[0][i][j]);
			}
		}
	}
	for(int x = 2; x < ms; x++) {
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					dp[x][i][j] = std::min(dp[x][i][j], dp[x-1][i][k] + dp[1][k][j]);
				}
			}
		}
	}
	while(r--) {
		int s, t, k;
		std::cin >> s >> t >> k;
		s--;t--;k++;
		k = std::min(k, ms - 1);
		std::cout << dp[k][s][t] << '\n';
	}
}