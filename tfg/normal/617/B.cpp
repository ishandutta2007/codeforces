#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 1;
	int f = -1;
	while(n--) {
		int x;
		std::cin >> x;
		if(x == 0) {
			if(f > -1) f++;
		} else {
			if(f > -1) ans *= f + 1;
			f = 0;
		}
	}
	if(f == -1) ans = 0;
	std::cout << ans << '\n';
}