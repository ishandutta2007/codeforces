#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n+1, 0), b(n+1, 0);
	for(int i = n-1; i >= 0; i--) {
		std::cin >> a[i];
	}
	for(int i = n-1; i >= 0; i--) {
		std::cin >> b[i];
	}
	std::set<int> can;
	for(int i = 1; i <= n; i++) {
		can.insert(i);
	}
	std::vector<int> prv(n+1, -1);
	prv[0] = 0;
	auto frm = prv;
	std::queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		auto itl = can.lower_bound(on), itr = can.upper_bound(on + a[on]);
		for(auto it = itl; it != itr; it++) {
			int to = *it - b[*it];
			if(prv[to] == -1) {
				prv[to] = on;
				frm[to] = *it;
				q.push(to);
			}
		}
		can.erase(itl, itr);
	}
	if(prv[n] == -1) {
		std::cout << "-1\n";
	} else {
		std::vector<int> ans;
		for(int on = n; on > 0; on = prv[on]) {
			ans.push_back(n - frm[on]);
		}
		std::cout << (int) ans.size() << '\n';
		for(int i = (int) ans.size() - 1; i >= 0; i--) {
			std::cout << ans[i] << (i == 0 ? '\n' : ' ');
		}
	}
}