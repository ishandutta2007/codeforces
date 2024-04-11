#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> poly(m, 0);
	int rest = n % m;
	for(int i = 1; i <= m; i++) {
		if(i <= rest) {
			poly[i * i % m]++;
		}
		poly[i * i % m] += n / m;
	}
	long long ans = 0;
	for(int i = 0; i < m; i++) {
		int o = (m - i) % m;
		ans += poly[i] * poly[o];
	}
	std::cout << ans << '\n';
}