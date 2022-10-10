#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300100;

bool vis[ms], use[ms];
std::vector<int> edges[ms], ans;

void go(int on) {
	vis[on] = use[on] = true;
	for(auto to : edges[on]) {
		use[on] = use[on] && !use[to];
	}
	if(use[on]) {
		ans.push_back(on);
	}
	for(auto to : edges[on]) if(!vis[to]) go(to);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		for(int i = 0; i < n; i++) {
			vis[i] = use[i] = false;
			edges[i].clear();
		}
		ans.clear();
		while(m--) {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		go(0);
		bool good = true;
		for(int i = 0; i < n; i++) {
			good = good && vis[i];
		}
		if(!good) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n" << ans.size() << '\n';
			for(int i = 0; i < (int) ans.size(); i++) {
				std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
			}
		}
	}
}