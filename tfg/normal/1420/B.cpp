#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		const int me = 30;
		std::vector<int> f(me, 0);
		long long ans = 0;
		while(n--) {
			int x;
			std::cin >> x;
			int id = me-1;
			while(!(x & (1 << id))) id--;
			ans += f[id]++;
		}
		std::cout << ans << '\n';
	}
}