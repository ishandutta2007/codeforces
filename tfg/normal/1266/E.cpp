#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long ans = 0;

struct Resource {
	int tot;
	int cur = 0;
	void rem() {
		cur--;
		if(cur < tot) {
			ans++;
		}
	}
	void add() {
		cur++;
		if(cur <= tot) {
			ans--;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Resource> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].tot;
		a[i].cur = 0;
		ans += a[i].tot;
	}
	int q;
	std::cin >> q;
	std::map<std::pair<int, int>, int> good;
	while(q--) {
		int s, t, u;
		std::cin >> s >> t >> u;
		s--;
		t--;
		auto it = good.find(std::pair<int, int>(s, t));
		if(it != good.end()) {
			a[it->second].rem();
			good.erase(it);
		}
		if(u) {
			u--;
			good[std::pair<int, int>(s, t)] = u;
			a[u].add();
		}
		std::cout << ans << '\n';
	}
}