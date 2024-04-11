#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Event {
	int l, r;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	std::vector<Event> evs;
	auto getVal = [&](Event x) { return a[x.r] - a[x.l]; };
	auto cmp = [&](Event e1, Event e2) {
		int v1 = getVal(e1), v2 = getVal(e2);
		if(v1 != v2) return v1 < v2;
		else return e1.r < e2.r;
	};
	for(int l = 0; l < n; l++) {
		for(int r = l + 1; r <= n; r++) {
			Event e;
			e.l = l;
			e.r = r;
			evs.push_back(e);
		}
	}
	std::sort(evs.begin(), evs.end(), cmp);
	std::vector<Event> ans;
	for(int l = 0, r = 0; l < (int) evs.size(); l = r) {
		while(r < (int) evs.size() && getVal(evs[l]) == getVal(evs[r])) {
			r++;
		}
		std::vector<Event> cur;
		for(int i = l; i < r; i++) {
			if(cur.size() == 0 || cur.back().r <= evs[i].l) {
				cur.push_back(evs[i]);
			}
		}
		if(cur.size() > ans.size()) {
			ans = cur;
		}
	}
	std::cout << ans.size() << '\n';
	for(auto e : ans) {
		std::cout << e.l + 1 << ' ' << e.r << '\n';
	}
}