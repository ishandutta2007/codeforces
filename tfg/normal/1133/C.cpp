#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int ans = 0;
	for(int l = 0, r = 0; l < n; l++) {
		while(r < n && a[r] - a[l] <= 5) {
			r++;
		}
		ans = std::max(ans, r - l);
	}
	std::cout << ans << '\n';
}