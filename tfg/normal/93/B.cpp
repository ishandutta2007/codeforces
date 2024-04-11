#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, w, m;
	std::cin >> n >> w >> m;
	std::cout << std::setprecision(10) << std::fixed;
	std::vector<std::vector<std::pair<int, int>>> ans(m);
	w *= m;
	int cup = n * w / m;
	int rest = w;
	//std::cout << "w is " << w << ", cup is " << cup << '\n';
	for(int i = 0, j = 0; i < m; i++) {
		if(rest > 0 && rest != w && rest > cup) {
			std::cout << "NO\n";
			return 0;
		}
		int want = cup;
		while(want > 0) {
			int use = std::min(rest, want);
			assert(use != 0);
			ans[i].emplace_back(use, j+1);
			want -= use;
			rest -= use;
			if(rest == 0) {
				j++;
				rest = w;
			}
		}
	}
	std::cout << "YES\n";
	for(auto vec : ans) {
		for(int i = 0; i < (int) vec.size(); i++) {
			std::cout << vec[i].second << ' ' << (double) vec[i].first / m << (i + 1 == (int) vec.size() ? '\n' : ' ');
		}
	}
}