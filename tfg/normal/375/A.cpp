#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s, t, tt;
	std::vector<int> got(10, true);
	got[1] = got[6] = got[8] = got[9] = false;
	std::cin >> s;
	for(auto c : s) {
		if(!got[c - '0']) {
			got[c - '0'] = true;
			t += c;
		} else {
			tt += c;
		}
	}
	t += tt;
	std::sort(t.begin(), t.begin() + 4);
	do {
		int cur = 0;
		for(auto c : t) {
			cur = (cur * 10 + c - '0') % 7;
		}
		if(cur == 0) {
			std::cout << t << '\n';
			return 0;
		}
	} while(std::next_permutation(t.begin(), t.begin() + 4));
	std::cout << "0\n";
}