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
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		ans += (long long) a[i] * (n - a[i] + 1);
		if(i) {
			int l = std::min(a[i-1], a[i]);
			int r = std::max(a[i-1], a[i]);
			ans -= (long long) (l) * (n - r + 1);
		}
	}
	std::cout << ans << '\n';
}