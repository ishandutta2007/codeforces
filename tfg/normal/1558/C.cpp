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
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::vector<int> ans;
		auto makeOP = [&](int x) {
			if(x == 0) return;
			ans.push_back(x);
			assert(x % 2 == 0);
			std::reverse(a.begin(), a.begin() + x + 1);
		};
		auto findX = [&](int x) {
			int ret = x % 2;
			while(a[ret] != x) ret += 2;
			return ret;
		};
		bool good = true;
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			a[i]--;
			good = good && a[i] % 2 == i % 2;
		}
		if(!good) {
			std::cout << "-1\n";
			continue;
		}
		for(int i = n-1; i > 0; i -= 2) {
			makeOP(findX(i));
			makeOP(findX(i-1)-1);
			makeOP(findX(i-1)+1);
			makeOP(2);
			makeOP(i);
		}
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	}
}