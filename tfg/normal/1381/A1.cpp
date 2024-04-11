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
		std::string a, b;
		std::cin >> n >> a >> b;
		int l = 0, r = n-1;
		int got = 0;
		std::vector<int> ans;
		for(int i = 0; i < n; i++) {
			int pos;
			if(i % 2 == 0) pos = l++;
			else pos = r--;
			int ch = a[pos] - '0';
			if((ch + got) % 2 == b[n-i-1] - '0') {
				ans.push_back(1);
			}
			ans.push_back(n - i);
			got ^= 1;
		}
		assert((int) ans.size() <= 2 * n);
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
		continue;
		for(auto x : ans) {
			for(int i = 0; i < x; i++) {
				a[i] = a[i] == '0' ? '1' : '0';
			}
			std::reverse(a.begin(), a.begin() + x);
			//std::cout << a << '\n';
		}
		std::cout << a << " should be " << b << '\n';
	}
}