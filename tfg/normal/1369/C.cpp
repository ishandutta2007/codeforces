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
		std::vector<int> a(n), b(m);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for(int i = 0; i < m; i++) {
			std::cin >> b[i];
		}
		std::sort(a.rbegin(), a.rend());
		std::sort(b.begin(), b.end());
		int id = m;
		int wut = 0;
		long long ans = 0;
		for(auto x : b) {
			ans += a[wut++];
			if(x > 1) {
				id += x - 1;
				ans += a[id-1];
			} else {
				ans += a[wut-1];
			}
		}
		std::cout << ans << '\n';
	}
}