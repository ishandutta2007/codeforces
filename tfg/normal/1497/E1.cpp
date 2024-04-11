#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 10001000;
	std::vector<int> group(ms, 1);
	std::vector<bool> prime(ms, true);
	for(int i = 2; i < ms; i++) {
		if(!prime[i]) continue;
		for(int j = i; j < ms; j += i) {
			prime[j] = false;
			int e = 0, x = j;
			while(x % i == 0) {
				x /= i, e++;
			}
			if(e % 2) {
				group[j] *= i;
			}
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<std::pair<int, int>> dp(k+1, std::pair<int, int>(0, 0));
		std::map<int, int> mp;
		for(int e = 0; e < n; e++) {
			int x;
			std::cin >> x;
			x = group[x];
			int last = -1;
			if(mp.count(x)) {
				last = mp[x];
			}
			mp[x] = e;
			std::vector<std::pair<int, int>> nxt(k+1, std::pair<int, int>(-1e9, 0));
			for(int i = 0; i <= k; i++) {
				// check if can get to get transition without change
				if(dp[i].second > last) {
					auto got = dp[i];
					got.first++;
					nxt[i] = std::max(nxt[i], got);
				} else {
					auto got = dp[i];
					got.second = e;
					nxt[i] = std::max(nxt[i], got);
				}
				// transition to i+1
				if(i < k) {
					auto got = dp[i];
					got.first++;
					nxt[i+1] = std::max(nxt[i+1], got);
				}
			}
			nxt.swap(dp);
		}
		std::cout << n - dp.back().first + 1 << '\n';
	}
}