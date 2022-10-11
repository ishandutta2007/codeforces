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
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		auto mex = [&]() {
			std::vector<int> f(n+1, 0);
			for(int i = 0; i < n; i++) f[a[i]]++;
			int ans = 0;
			while(f[ans]) ans++;
			return ans;
		};
		std::vector<int> ans;
		while(1) {
			bool good = true;
			for(int i = 0; i < n; i++) {
				good = good && a[i] == i;
			}
			if(good) break;
			int got = mex();
			if(got == n) {
				int i = 0;
				while(a[i] == i) i++;
				a[i] = n;
				ans.push_back(i);
				continue;
			}
			a[got] = got;
			ans.push_back(got);
		}
		assert(2 * n >= (int) ans.size());
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	}
}