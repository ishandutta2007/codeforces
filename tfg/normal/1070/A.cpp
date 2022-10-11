#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstring>

const int INF = 1e9;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int dp[5050][505];
int pot[5050];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int d, s;
	std::cin >> d >> s;
	pot[0] = 1 % d;
	for(int i = 1; i < 5050; i++) {
		pot[i] = pot[i-1] * 10 % d;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= s; i++) {
		for(int rep = 0; rep < 10; rep++) {
		for(int j = 0; j <= d; j++) {
			if(dp[i][j] >= INF) continue;
			for(int k = 1; k < 10; k++) {
				if(i + k > s) continue;
				int toj = (j * 10 + k) % d;
				if(dp[i + k][toj] > dp[i][j] + 1) {
					dp[i + k][toj] = dp[i][j] + 1;
				}
			}
			int curj = j;
			while(dp[i][curj * 10 % d] > 1 + dp[i][curj]) {
				dp[i][curj * 10 % d] = 1 + dp[i][curj];
				curj = curj * 10 % d;
			}
			//std::cout << "cost for (" << i << ", " << j << ") is " << dp[i][j] << "\n";
		}
		}
	}
	if(dp[s][0] >= INF) {
		std::cout << "-1\n";
		return 0;
	}
	int k = 0;
	//return 0;
	while(s > 0) {
		int use = 1;
		int x = dp[s][k] - 1;
		//std::cout << "on " << s << ", " << k << ", expecting size " << dp[s][k] << "\n";
		while(dp[s - use][(k - pot[x] * use % d + d) % d] >= dp[s][k]) {
			use++;
		}
		s -= use;
		k = (k - pot[x] * use % d + d) % d;
		std::cout << use;
		while(x > dp[s][k]) {
			x--;
			std::cout << 0;
		}
	}
	std::cout << std::endl;
}