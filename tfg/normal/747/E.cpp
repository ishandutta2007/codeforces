#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1e6 + 10;

std::vector<std::string> ans[ms];
int tot = 0;

std::string txt;
int pt = 0;

void solve(int h, int size) {
	tot = std::max(tot, h + 1);
	while(size-- && pt < (int) txt.size()) {
		std::string str;
		while(pt < (int) txt.size() && txt[pt] != ',') {
			str += txt[pt++];
		}
		ans[h].push_back(str);
		assert(txt[pt] == ',');
		pt++;
		int s = 0;
		while(pt < (int) txt.size() && txt[pt] != ',') {
			s = s * 10 + txt[pt++] - '0';
		}
		pt++;
		if(s) {
			solve(h+1, s);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> txt;
	solve(0, -1);
	std::cout << tot << '\n';
	for(int i = 0; i < tot; i++) {
		for(int j = 0; j < (int) ans[i].size(); j++) {
			std::cout << ans[i][j] << (j + 1 == (int) ans[i].size() ? '\n' : ' ');
		}
	}
}