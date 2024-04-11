#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, x, y;
	std::cin >> n >> x >> y;
	int ms = 1 << std::max(x, y);
	int badMask = (1 << (x-1)) | (1 << (y-1));
	std::vector<int> ans;
	{
	std::vector<int> dp(ms, 0), nxt(ms);
	while(ans.size() <= 1000) {
		ans.push_back(dp[0]);
		std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
		if(std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() >= 3.9) break;
		for(int mask = 0; mask < ms; mask++) {
			nxt[mask] = dp[(mask<<1) & (ms - 1)];
			bool good = (mask & badMask) == 0;
			if(good) {
				nxt[mask] = std::max(nxt[mask], 1 + dp[((mask<<1)+1) & (ms-1)]);
			}
		}
		nxt.swap(dp);
	}
	}
	//assert((int) ans.size() >= 300);
	int cycSize = x+y;
	if(n < (int) ans.size()) {
		std::cout << ans[n] << '\n';
	} else {
		for(int i = (int) ans.size() - 1; 1; i--) {
			if(i % cycSize == n % cycSize) {
				std::cout << ans[i] + (n - i) / cycSize * (ans[i] - ans[i-cycSize]) << '\n';
				return 0;
			}
		}
	}
}