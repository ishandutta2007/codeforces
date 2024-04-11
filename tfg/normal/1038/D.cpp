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
	std::vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	long long ans = 0;
	if(n == 1) {
		ans = a[0];
	} else if(a[0] <= 0 && a.back() <= 0) {
		//std::cout << "second case\n";
		ans += a.back();
		for(int i = 0; i + 1 < n; i++) {
			ans -= a[i];
		}
	} else if(a[0] >= 0 && a.back() >= 0) {
		//std::cout << "third case\n";
		ans -= a[0];
		for(int i = 1; i < n; i++) {
			ans += a[i];
		}
	} else {
		//std::cout << "fourth case\n";
		for(int i = 0; i < n; i++) {
			ans += std::max(a[i], -a[i]);
		}
	}
	std::cout << ans << std::endl;
}