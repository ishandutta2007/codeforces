#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k, m;
	std::cin >> n >> k >> m;
	double ans = 0;
	std::vector<long long> a(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.rbegin(), a.rend());
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		int rest = m - (n - i - 1);
		if(rest < 0) continue;
		rest = (int) std::min((long long) rest, (i + 1LL) * k);
		ans = std::max(ans, (double) (rest + sum) / (i + 1));
	}
	std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}