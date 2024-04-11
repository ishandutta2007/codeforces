#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int getAns(int x) {
	int ans = 1;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			ans = std::max(ans, x / i);
		}
	}
	assert(ans < x);
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::map<int, int> memo;
	int q;
	std::cin >> q;
	while(q--) {
		int x;
		std::cin >> x;
		bool valid = false;
		for(int i = 0; (1 << i) <= x; i++) {
			if(x & (1 << i)) {

			} else {
				x |= 1 << i;
				valid = true;
			}
		}
		if(!valid && !memo.count(x)) {
			memo[x] = getAns(x);
		}
		if(!valid) {
			std::cout << memo[x] << '\n';
		} else {
			std::cout << x << '\n';
		}
	}
}