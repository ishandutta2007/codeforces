#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int test;
	std::cin >> test;
	while(test--) {
		int n;
		std::cin >> n;
		int t = 0, pos = 0, to = 0;
		int good = 0;
		int check = (int) 2e9;
		while(n--) {
			int nxtT, nxtPos;
			std::cin >> nxtT >> nxtPos;
			int use = std::min(std::abs(pos - to), nxtT - t);
			int o = pos < to ? pos + use : pos - use;
			if(std::min(pos, o) <= check && check <= std::max(pos, o)) good++;
			pos = o;
			if(pos == to) {
				check = nxtPos;
				t = nxtT;
				to = nxtPos;
			} else {
				check = nxtPos;
				t = nxtT;
			}
		}
		std::cout << good + (std::min(pos, to) <= check && check <= std::max(pos, to)) << '\n';
	}
}