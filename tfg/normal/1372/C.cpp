#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		int l = n+1, r = -1, f = 0;
		for(int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			if(x != i) {
				f++;
				r = i;
				l = std::min(l, i);
			}
		}
		std::cout << (f == 0 ? 0 : (r - l + 1 == f ? 1 : 2)) << '\n';
	}
}