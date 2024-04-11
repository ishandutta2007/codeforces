#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		// I think 3 is enough but just to be safe..
		const int MAGIC = 5;
		int n;
		std::cin >> n;
		long long dp[MAGIC];
		for(int i = 0; i < MAGIC; i++) {
			dp[i] = 0;
		}
		const long long INF = 1e18;
		int last = -30;
		while(n--) {
			int h, c;
			std::cin >> h >> c;
			long long nxt[MAGIC];
			for(int i = 0; i < MAGIC; i++) {
				nxt[i] = INF;
			}
			for(int i = 0; i < MAGIC; i++) {
				for(int j = 0; j < MAGIC; j++) {
					if(h + j == last + i) continue;
					nxt[j] = std::min(nxt[j], dp[i] + (long long) j * c);
				}
			}
			last = h;
			for(int i = 0; i < MAGIC; i++) {
				dp[i] = nxt[i];
			}
		}
		long long ans = INF;
		for(int i = 0; i < MAGIC; i++) {
			ans = std::min(ans, dp[i]);
		}
		std::cout << ans << '\n';
	}
}