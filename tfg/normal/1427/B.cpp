#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		std::string str;
		std::cin >> str;
		std::vector<int> wtf;
		int sum = 0;
		int ans = 0;
		for(int l = 0, r = 0; l < n; l = r) {
			while(r < n && str[l] == str[r]) r++;
			if(str[l] == 'L') {
				sum += r - l;
				if(l != 0 && r != n) wtf.push_back(r - l);
			} else {
				ans += 2 * (r - l) - 1;
			}
		}
		if(sum <= k) {
			std::cout << 2 * n - 1 << '\n';
			continue;
		}
		if(ans == 0) {
			std::cout << std::max(0, 2 * k - 1) << '\n';
			continue;
		}
		ans += 2*k;
		std::sort(wtf.begin(), wtf.end());
		for(auto x : wtf) {
			if(x <= k) {
				k -= x;
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}