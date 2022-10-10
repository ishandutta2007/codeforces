#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 0;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = n - 2; i >= 0; i--) {
		a[i] = std::min(a[i], a[i+1] - 1);
		a[i] = std::max(a[i], 0);
	}
	for(auto v : a) {
		ans += v;
	}
	std::cout << ans << '\n';
}