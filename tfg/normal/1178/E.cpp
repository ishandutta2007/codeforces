#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int l = 0, r = (int) str.size() - 1;
	int size = (int) str.size();
	std::string ans, ansr;
	while(size > 3) {
		bool valid = false;
		for(int i = 0; i < 4; i++) {
			int u = l + i % 2;
			int v = r - (i / 2);
			if(str[u] == str[v]) {
				ans += str[u];
				ansr += str[v];
				valid = true;
				break;
			}
		}
		assert(valid);
		size -= 4;
		l += 2;
		r -= 2;
	}
	std::reverse(ansr.begin(), ansr.end());
	if(size > 0) {
		ans += str[l];
	}
	std::cout << (ans + ansr) << '\n';
}