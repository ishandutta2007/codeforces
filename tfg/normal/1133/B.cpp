#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(k, 0);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x % k]++;
	}
	int ans = a[0] / 2;
	for(int i = 1; k - i >= i && i < k; i++) {
		if(k - i == i) {
			ans += a[i] / 2;
		} else {
			ans += std::min(a[i], a[k - i]);
		}
	}
	std::cout << ans * 2 << '\n';
}