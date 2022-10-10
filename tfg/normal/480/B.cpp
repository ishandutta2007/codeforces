#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int mask = 0;
	int n, len, x, y;
	std::cin >> n >> len >> x >> y;
	std::set<int> spots;
	for(int i = 0; i < n; i++) {
		int pos;
		std::cin >> pos;
		spots.insert(pos);
		if(spots.count(pos - x)) {
			mask |= 1;
		}
		if(spots.count(pos - y)) {
			mask |= 2;
		}
	}
	if(mask == 3) {
		std::cout << "0\n";
	} else if(mask) {
		std::cout << "1\n" << (mask == 1 ? y : x) << '\n';
	} else {
		std::set<int> want[2];
		for(auto pos : spots) {
			if(pos + x <= len) {
				want[0].insert(pos + x);
			}
			if(pos - x >= 0) {
				want[0].insert(pos - x);
			}
			if(pos + y <= len) {
				want[1].insert(pos + y);
			}
			if(pos - y >= 0) {
				want[1].insert(pos - y);
			}
		}
		for(auto pos : want[0]) {
			if(want[1].count(pos)) {
				std::cout << "1\n" << pos << '\n';
				return 0;
			}
		}
		std::cout << "2\n" << x << ' ' << y << '\n';
	}
}