#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	long long ta, tb;
	std::cin >> ta >> tb;
	int k;
	std::cin >> k;
	if(k >= std::min(n, m)) {
		std::cout << "-1\n";
		return 0;
	}
	std::vector<long long> a(n), b(m);
	for(auto &v : a) {
		std::cin >> v;
	}
	for(auto &v : b) {
		std::cin >> v;
	}
	long long ans = 0;
	for(int i = 0, j = 0; i < n && i <= k; i++) {
		while(j < m && b[j] < a[i] + ta) j++;
		int rest = k - i;
		if(j + rest >= m) {
			std::cout << "-1\n";
			return 0;
		}
		ans = std::max(ans, b[j+rest] + tb);
	}
	std::cout << ans << '\n';
}