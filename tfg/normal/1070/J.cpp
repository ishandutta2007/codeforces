#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m, k;
		std::cin >> n >> m >> k;
		std::vector<int> freq(26, 0);
		std::string str;
		std::cin >> str;
		for(auto c : str) {
			freq[c - 'A']++;
		}
		std::sort(freq.begin(), freq.end(), std::greater<int>());
		while(freq.back() == 0) {
			freq.pop_back();
		}
		int sum = k;
		k = (int) freq.size();
		//for(int i = 0; i < k; i++) std::cout << freq[i] << (i + 1 == k ? '\n' : ' ');
		if(n > m) {
			std::swap(n, m);
		}
		long long ans = (long long) 1e18;
		for(int s = 0; s < k; s++) {
			std::vector<bool> dp(n, false);
			int over = -1;
			dp[0] = true;
			for(int j = 0; j < k; j++) {
				if(j == s) continue;
				for(int i = n - 1; i >= 0; i--) {
					if(dp[i]) {
						if(i + freq[j] >= n) {
							if(over == -1) over = i + freq[j];
							over = std::min(over, i + freq[j]);
						} else {
							dp[i + freq[j]] = true;
						}
					}
				}
			}
			if(over != -1) {
				// solving for over
				int rest = sum - over;
				assert(rest > 0);
				if(rest >= m) {
					ans = 0;
				}
			}
			for(int pos = n - 1; pos >= 0; pos--) {
				if(!dp[pos]) continue;
				int nrest = n - pos;
				int mgot = sum - freq[s] - pos;
				assert(mgot >= 0);
				int mrest = std::max(0, m - mgot);
				if(freq[s] >= nrest + mrest) {
					ans = std::min(ans, (long long) mrest * nrest);
				}
			}
		}
		if(k == 1) {
			assert(ans == (long long) n * m);
		}
		assert(ans <= (long long) n * m);
		std::cout << ans << '\n';
	}
}