#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <utility>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	n += n;
	std::vector<std::pair<int, int>> a(n);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i < n / 2 ? 0 : 1;
	}
	std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());
	for(int i = 0; i < n; i++) {
		if(a[i].second == i % 2) {
			if(i % 2 == 0) {
				ans += a[i].first;
			} else {
				ans -= a[i].first;
			}
		}
	}
	std::cout << ans << std::endl;
}