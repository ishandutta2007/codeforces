#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	long long x;
	std::cin >> n >> k >> x;
	long long p = 1;
	while(k--) {
		p *= x;
	}
	std::vector<long long> a(n + 1), pref(n + 1, 0), suf(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pref[i] = pref[i-1] | a[i];
	}
	for(int i = n; i > 0; i--) {
		suf[i-1] = suf[i] | a[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = std::max(ans, (a[i] * p) | pref[i-1] | suf[i]);
	}
	std::cout << ans << '\n';
}