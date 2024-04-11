#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<bool> used(n, false);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(used[x]) {
			ans++;
		} else {
			used[x] = true;
		}
	}
	std::cout << ans + 1 << '\n';
}