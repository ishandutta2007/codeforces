#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	std::string pat;
	bool good = true;
	for(int rep = 1; rep <= 20; rep++) {
		pat += s;
		for(int i = 0; i < (int) s.size(); i++) {
			good = good && s[i] == t[((rep-1)*(int)s.size() + i)%(int)t.size()];
		}
		if(!good) {
			std::cout << "-1\n";
			return;
		}
		if(rep * s.size() % t.size() == 0) {
			std::cout << pat << '\n';
			return;
		}
	}
	assert(false);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}