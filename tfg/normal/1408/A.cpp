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
		std::vector<int> a(n), b(n), c(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		for(int i = 0; i < n; i++) {
			std::cin >> c[i];
		}
		std::vector<int> ans(1, a[0]);
		for(int i = 1; i+1 < n; i++) {
			ans.push_back(a[i] != ans.back() ? a[i] : b[i]);
		}
		if(a.back() != ans.back() && a.back() != a[0]) {
			ans.push_back(a.back());
		} else if(b.back() != ans.back() && b.back() != a[0]) {
			ans.push_back(b.back());
		} else {
			ans.push_back(c.back());
		}
		for(int i = 0; i < n; i++) {
			std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
		}
	}
}