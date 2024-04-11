#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> ans(2 * n);
	if(n % 2 == 0) {
		std::cout << "NO\n";
	} else {
		for(int i = 0; i < n; i++) {
			ans[i] = 2 * i + 1;
			ans[n+i] = 2 * i + 2;
			if(i % 2 == 1) {
				std::swap(ans[i], ans[n+i]);
			}
		}
		n += n;
		std::cout << "YES\n";
		for(int i = 0; i < n; i++) {
			std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
		}
	}
}