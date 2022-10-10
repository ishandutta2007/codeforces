#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q, x;
	std::cin >> q >> x;
	std::vector<int> f(x, 0);
	int ans = 0;
	while(q--) {
		int val;
		std::cin >> val;
		f[val % x]++;
		while(f[ans % x]) {
			f[ans % x]--;
			ans++;
		}
		std::cout << ans << '\n';
	}
}