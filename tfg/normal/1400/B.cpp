#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long cap[2];
		std::cin >> cap[0] >> cap[1];
		long long cnt[2];
		std::cin >> cnt[0] >> cnt[1];
		int w[2];
		std::cin >> w[0] >> w[1];
		if(w[0] > w[1]) {
			std::swap(w[0], w[1]);
			std::swap(cnt[0], cnt[1]);
		}
		int ans = 0;
		for(int i = 0; i <= cnt[0] && (long long) i * w[0] <= cap[0]; i++) {
			int u1 = (int) std::min(cnt[1], (cap[0] - i * w[0]) / w[1]);
			int u2 = (int) std::min(cnt[0] - i, cap[1] / w[0]);
			int u3 = (int) std::min(cnt[1] - u1, (cap[1] - u2 * w[0]) / w[1]);
			ans = std::max(ans, i + u1 + u2 + u3);
		}
		std::cout << ans << '\n';
	}
}