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
		int n, x;
		std::cin >> n >> x;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.rbegin(), a.rend());
		int ans = 0;
		for(int i = 0, j = 0; i < n; i++) {
			j++;
			if((long long) j * a[i] >= x) {
				j = 0;
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}