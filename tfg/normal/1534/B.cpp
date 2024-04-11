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
		int n;
		std::cin >> n;
		n += 2;
		std::vector<int> a(n);
		long long ans = 0;
		for(int i = 1; i+1 < n; i++) {
			std::cin >> a[i];
		}
		for(int i = 1; i+1 < n; i++) {
			if(a[i] > a[i-1] && a[i] > a[i+1]) {
				int use = std::min(a[i] - a[i-1], a[i] - a[i+1]);
				a[i] -= use;
				ans += use;
			}
		}
		for(int i = 1; i+1 < n; i++) {
			assert(a[i] <= a[i-1] || a[i] <= a[i+1]);
		}
		for(int i = 0; i+1 < n; i++) {
			ans += std::abs(a[i] - a[i+1]);
		}
		std::cout << ans << '\n';
	}
}