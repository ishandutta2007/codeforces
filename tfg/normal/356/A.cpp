#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>


std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::set<int> a;
	for(int i = 1; i <= n; i++) {
		a.insert(i);
	}
	std::vector<int> ans(n+1, 0);
	while(m--) {
		int l, r, x;
		std::cin >> l >> r >> x;
		auto itl = a.lower_bound(l), itr = a.upper_bound(r);
		for(auto it = itl; it != itr; it++) {
			ans[*it] = x;
		}
		a.erase(itl, itr);
		ans[x] = 0;
		a.insert(x);
	}
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << (i == n ? '\n' : ' ');
	}
}