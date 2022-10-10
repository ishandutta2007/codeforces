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
		int people = 0, ans = 0;
		std::sort(a.begin(), a.end());
		for(auto x : a) {
			people++;
			if(people >= x) {
				people = 0;
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}