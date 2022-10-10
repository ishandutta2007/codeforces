#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int f = 0;
	int n;
	std::cin >> n;
	long long ans = 0;
	while(n--) {
		int x;
		std::cin >> x;
		if(x == 1) {
			f++;
		} else {
			ans += f;
		}
	}
	std::cout << ans << '\n';
}