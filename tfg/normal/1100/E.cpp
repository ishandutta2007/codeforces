#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int u[ms], v[ms], c[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		std::cin >> u[i] >> v[i] >> c[i];
		u[i]--;v[i]--;
	}
	auto getTopo = [&](int x) {
		std::vector<int> q, topo;
		std::vector<int> deg(n, 0);
		std::vector<std::vector<int>> edges(n);
		for(int i = 0; i < m; i++) {
			// use edge if it is higher
			if(c[i] > x) {
				edges[u[i]].push_back(v[i]);
				deg[v[i]]++;
			}
		}
		for(int i = 0; i < n; i++) {
			if(deg[i] == 0) {
				q.push_back(i);
			}
		}
		for(int i = 0; i < (int) q.size(); i++) {
			for(auto j : edges[q[i]]) {
				deg[j]--;
				if(deg[j] == 0) {
					q.push_back(j);
				}
			}
		}
		if((int) q.size() < n) return topo;
		topo.resize(n);
		for(int i = 0; i < n; i++) {
			topo[q[i]] = i;
		}
		return topo;
	};
	int l = 0, r = (int) 1e9 + 10;
	while(l != r) {
		int mid = (l + r) / 2;
		if(getTopo(mid).size() > 0) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	auto topo = getTopo(l);
	std::vector<int> ans;
	for(int i = 0; i < m; i++) {
		if(topo[u[i]] > topo[v[i]]) {
			ans.push_back(i + 1);
		}
	}
	std::cout << l << ' ' << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}