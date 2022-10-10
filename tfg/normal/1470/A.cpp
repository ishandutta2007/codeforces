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
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n), c(m);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for(int i = 0; i < m; i++) {
			std::cin >> c[i];
		}
		std::sort(a.rbegin(), a.rend());
		int on = 0;
		long long ans = 0;
		for(auto x : a) {
			x--;
			if(on < x) {
				ans += c[on++];
			} else {
				ans += c[x];
			}
		}
		std::cout << ans << '\n';
	}
}