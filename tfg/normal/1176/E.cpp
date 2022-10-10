#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> edges[200100];
bool visit[200100];

std::vector<int> A[2];

int h[200200];

void dfs(int on) {
	assert(!visit[on]);
	visit[on] = true;
	A[h[on]%2].push_back(on+1);
	for(auto to : edges[on]) {
		if(!visit[to]) {
			h[to] = 1 + h[on];
			dfs(to);
		}
	}
}

void solve() {
	int n, m;
	A[0].clear(); A[1].clear();
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		visit[i] = false;
		edges[i].clear();
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0);
	auto ans = A[0].size() < A[1].size() ? A[0] : A[1];
	std::sort(ans.begin(), ans.end());
	assert((int) ans.size() * 2 <= n);
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}