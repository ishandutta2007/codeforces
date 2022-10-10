#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];
int size[ms];
int h[ms], a[ms];

void dfs(int on, int par) {
	size[on] = 1;
	for(auto to : edges[on]) {
		if(to == par) continue;
		h[to] = 1 + h[on];
		dfs(to, on);
		size[on] += size[to];
	}
	a[on] = h[on] - (size[on] - 1);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1);
	std::sort(a, a + n);
	long long ans = 0;
	for(int i = 0; i < k; i++) {
		ans += a[n-i-1];
	}
	std::cout << ans << '\n';
}