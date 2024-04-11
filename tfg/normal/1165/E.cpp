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
	std::vector<int> a(n), b(n);
	const long long MOD = 998244353;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<long long> cost(n);
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		cost[i] = (i + 1LL) * (n - i) * a[i];
	}
	//std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	//std::reverse(b.begin(), b.end());
	std::sort(cost.begin(), cost.end());
	std::reverse(cost.begin(), cost.end());
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		//std::cout << "(" << a[i] << ", " << b[i] << ", " << cost[i] << ")\n";
		ans = (ans + b[i] % MOD * (cost[i] % MOD) % MOD) % MOD;
	}
	std::cout << ans << '\n';
}