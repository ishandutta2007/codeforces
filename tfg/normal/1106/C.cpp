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
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long long ans = 0;
	std::sort(a.begin(), a.end());
	for(int i = 0; n - i - 1 > i; i++) {
		//std::cout << "(" << a[i] << ", " << a[n-i-1] << ")\n";
		ans += (a[i] + a[n-i-1]) * (a[i] + a[n-i-1]);
	}
	std::cout << ans << '\n';
}