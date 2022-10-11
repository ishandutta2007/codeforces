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
	long long ans = n;
	std::vector<int> a(n);
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	for(int i = 0; i < n; i++) {
		ans += std::max(a[i], b[i]);
	}
	std::cout << ans << std::endl;
}