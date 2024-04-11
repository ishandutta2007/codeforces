#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	for(int i = n-2; i >= 0; i--) {
		a[i] = std::min(a[i], a[i+1]);
	}
	if(a[0] != b[0]) {
		std::cout << "0\n";
		return 0;
	}
	//std::reverse(a.begin(), a.end());
	int ans = 1;
	const int MOD = 998244353;
	for(int i = 1; i < m; i++) {
		int f = std::upper_bound(a.begin(), a.end(), b[i]) - std::lower_bound(a.begin(), a.end(), b[i]);
		ans = (int)((long long) ans * f % MOD);
	}
	std::cout << ans << '\n';
}