#include <iostream>
#include <vector>
#include <iomanip>

long long pair(long long x) { return (x + 1) * x / 2; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	long long ans = 0;

	for(int i = 0; i < m; i++) {
		int x, d;
		std::cin >> x >> d;
		ans += (long long) x * n + (d > 0 ? pair(n - 1) * d : (pair(n / 2) + pair((n - 1) / 2)) * d);
	}
	std::cout << std::fixed << std::setprecision(20) << (double) ans / n << std::endl;
}