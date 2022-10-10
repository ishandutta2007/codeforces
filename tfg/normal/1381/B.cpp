#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		int mx = 0;
		std::bitset<2020> dp;
		dp[0] = true;
		int f = 0;
		for(int i = 0; i < 2 * n; i++) {
			int x;
			std::cin >> x;
			if(mx < x) {
				dp |= dp << f;
				//std::cout << "got group of size " << f << '\n';
				f = 0;
				mx = x;
			}
			f++;
		}
		if(f) {
			//std::cout << "got group of size " << f << '\n';
			dp |= dp << f;
		}
		std::cout << (dp[n] ? "YES\n" : "NO\n");
	}
}