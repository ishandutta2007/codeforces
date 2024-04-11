#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
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
	int size = 1;
	long long ans = 0;
	while(size <= n) {
		for(int i = 0; i < size; i++) {
            ans += a[n-i-1];
        }
        size = size * 4;
	}
	std::cout << ans << '\n';
}