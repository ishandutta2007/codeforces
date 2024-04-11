#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	std::map<int, int> ids;
	int l = 0, r = 1;
	while(q--) {
		char c;
		std::cin >> c;
		if(c == 'L') {
			int x;
			std::cin >> x;
			ids[x] = l--;
		} else if(c == 'R') {
			int x;
			std::cin >> x;
			ids[x] = r++;
		} else {
			int x;
			std::cin >> x;
			int curID = ids[x];
			std::cout << std::min(curID - l, r - curID) - 1 << std::endl;
		}
	}
}