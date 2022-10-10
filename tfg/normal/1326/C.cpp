#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::cout << (long long) k * (n + n - k + 1) / 2 << ' ';
	std::vector<int> a(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.rbegin(), p.rend(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	std::sort(p.begin(), p.begin() + k);
	const int MOD = 998244353;
	int ans = 1;
	for(int i = 1; i < k; i++) {
		ans = (int) ((long long) ans * abs(p[i] - p[i-1]) % MOD);
	}
	std::cout << ans << '\n';
}