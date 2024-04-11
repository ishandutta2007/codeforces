#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] != a[0]) {
			ans = std::max(ans, i);
		}
	}
	for(int i = 0; i < n; i++) {
		if(a[i] != a[n-1]) {
			ans = std::max(ans, n-1-i);
		}
	}
	std::cout << ans << '\n';
}