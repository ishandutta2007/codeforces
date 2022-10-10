#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int ans = 3;
bool qry(int val) {
	std::cout << val << std::endl;
	if(0) {
		ans ^= val;
		val = ans == 0;
		std::cout << "currently is " << ans << std::endl;
		std::cout << val << std::endl;
	} else {
		std::cin >> val;
	}
	return val == 1;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	int cur = 0;
	for(int i = 0; i < n; i++) {
		if(qry(cur ^ i)) {
			return;
		}
		cur ^= cur ^ i;
	}
	assert(0);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}