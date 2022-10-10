#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, x;
		std::cin >> n >> x;
		std::vector<int> a(n+1, 0);
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			a[i] = (a[i] + a[i-1]) % x;
		}
		int l = 0, r = n;
		while(l <= n && a[l] == a.back()) l++;
		if(l > n) {
			std::cout << "-1\n";
			continue;
		}
		while(a[r] == a[0]) r--;
		std::cout << n - std::min(l, n - r) << '\n';
	}
}