#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
std::vector<int> edges[ms];
int ans[ms];
long long tot = 0;

void go(int on, int par) {
	for(auto to : edges[on]) {
		if(to == par) continue;
		go(to, on);
		if(ans[on] == -1) {
			if(ans[to] == -1) {
				ans[on] = to;
				ans[to] = on;
				tot += 2;
			}
		} else {
			if(ans[to] == -1) {
				ans[to] = ans[on];
				ans[on] = to;
				tot += 2;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	memset(ans, -1, sizeof ans);
	go(0, -1);
	if(ans[0] == -1) {
		tot += 2;
		int u = edges[0][0];
		assert(ans[u] != -1);
		ans[0] = ans[u];
		ans[u] = 0;
	}
	std::cout << tot << '\n';
	for(int i = 0; i < n; i++) {
		assert(ans[i] != -1);
		std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}