#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> want(n, 0);
	std::vector< std::pair<int, int> > offer(m);
	for(int i = 0; i < n; i++) {
		std::cin >> want[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> offer[i].first >> offer[i].second;
		offer[i].second--;
	}
	std::sort(offer.begin(), offer.end());
	std::reverse(offer.begin(), offer.end());
	int l = 1, r = 1e6;
	auto check = [&](int x) {
		auto rest = want;
		int money = x;
		int wtf = 0;
		for(auto o : offer) {
			if(o.first <= x) {
				money = std::min(money, o.first);
				int use = std::min(money, rest[o.second]);
				wtf += use;
				rest[o.second] -= use;
				money -= use;
			}
		}
		for(auto v : rest) {
			wtf += 2 * v;
		}
		return wtf <= x;
	};
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}