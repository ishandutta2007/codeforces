#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;
	const int me = 30;
	std::vector<int> f(me, 0);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		for(int j = 0; j < me; j++) {
			if(x & (1 << j)) {
				f[j]++;
			}
		}
	}
	for(int i = me-1; i >= 0; i--) {
		if(f[i] % 2 == 0) continue;
		int ones = f[i];
		int zeroes = n - ones;
		//std::cout << "at " << i << " got (" << zeroes << ", " << ones << ")\n";
		if(zeroes % 2 == 0) {
			// same as zeroes being 0
			std::cout << (ones / 2 % 2 == 0 ? "WIN" : "LOSE") << '\n';
		} else {
			// same as having one skipping turn
			// (1, 1) first wins
			// (3, 1) first wins by skipping
			std::cout << "WIN\n";
		}
		return;
	}
	std::cout << "DRAW\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}