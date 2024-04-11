#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int INF = 1e9;
	int dp[4] = {0, INF, INF, INF};
	int n;
	std::cin >> n;
	while(n--) {
		int v;
		std::cin >> v;
		int to[4] = {INF, INF, INF, INF};
		if(v == 1) {
			for(int i = 0; i < 4; i++) {
				if(i == 2) continue;
				int x = (i + i + 1) % 4;
				to[x] = std::min(to[x], dp[i]);
			}
			for(int i = 0; i < 4; i++) {
				int x = (i + i) % 4;
				to[x] = std::min(to[x], dp[i] + 1);
			}
		} else {
			for(int i = 0; i < 4; i++) {
				int x = (i + i) % 4;
				to[x] = std::min(to[x], dp[i]);
			}
		}
		for(int i = 0; i < 4; i++) {
			dp[i] = to[i];
		}
	}
	int ans = INF;
	for(int i = 0; i < 4; i++) {
		ans = std::min(ans, dp[i]);
	}
	std::cout << ans << '\n';
}