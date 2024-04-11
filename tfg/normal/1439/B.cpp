#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<int>> edges(n);
	std::vector<int> deg(n, 0);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		deg[u]++;
		deg[v]++;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		//std::cout << deg[i] << (i + 1 == n ? '\n' : ' ');
		if(deg[i] < k) {
			q.push(i);
		}
		std::sort(edges[i].begin(), edges[i].end());
	}
	std::vector<bool> good(n, false), dirty(n, false);
	std::vector<std::vector<int>> haha(n);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		dirty[on] = true;
		//std::cout << "removing " << on << std::endl;
		for(auto to : edges[on]) {
			if(deg[to] >= k-1 && !dirty[to]) {
				haha[on].push_back(to);
			}
			deg[to]--;
			if(deg[to] == k-1) {
				q.push(to);
			}
		}
		good[on] = (int) haha[on].size() == k-1 && deg[on] == k-1;
	}
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		//std::cout << deg[i] << (i + 1 == n ? '\n' : ' ');
		if(deg[i] >= k) {
			ans.push_back(i);
		}
	}
	if(!ans.empty()) {
		std::cout << "1 " << ans.size() << "\n";
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
		return;
	}
	auto ask = [&](int u, int v) {
		auto it = std::lower_bound(edges[u].begin(), edges[u].end(), v);
		return it != edges[u].end() && *it == v;
	};
	for(int i = 0; i < n && (long long) k * (k - 1) / 2 <= m; i++) {
		for(int j = (int) haha[i].size()-2; j >= 0 && good[i]; j--) {
			for(int jj = j+1; jj < (int) haha[i].size() && good[i]; jj++) {
				good[i] = good[i] && ask(haha[i][j], haha[i][jj]);
			}
		}
		if(good[i]) {
			ans = haha[i];
			ans.push_back(i);
			break;
		}
	}
	if(!ans.empty()) {
		std::cout << "2\n";
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
		return;
	}
	std::cout << "-1\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}