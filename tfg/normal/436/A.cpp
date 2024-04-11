#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, st;
	std::cin >> n >> st;
	std::vector<std::pair<int, int>> wtf[2];
	for(int i = 0; i < n; i++) {
		int t, h, m;
		std::cin >> t >> h >> m;
		wtf[t].emplace_back(h, m);
	}
	int ans = 0;
	for(int ha = 0; ha < 2; ha++) {
		int on = ha;
		std::vector<std::pair<int, int>> a[2];
		a[0] = wtf[0];
		a[1] = wtf[1];
		int can = st;
		int cur = 0;
		while(1) {
			int i = -1;
			for(int l = 0; l < (int) a[on].size(); l++) {
				if(a[on][l].first <= can && (i == -1 || a[on][l].second >= a[on][i].second)) {
					i = l;
				}
			}
			if(i == -1) {
				break;
			}
			//std::cout << "eating " << i << " of type " << on << '\n';
			cur++;
			can += a[on][i].second;
			a[on].erase(a[on].begin() + i);
			on = 1 - on;
		}
		ans = std::max(ans, cur);
	}
	std::cout << ans << '\n';
}