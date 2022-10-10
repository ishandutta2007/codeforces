#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

std::vector<int> ans;
std::vector<std::pair<int, int>> edges[ms];
int a[ms];
bool vis[ms];

void go(int on) {
	vis[on] = true;
	for(auto [to, id] : edges[on]) {
		if(!vis[to]) {
			go(to);
			if(a[to]) {
				a[to] ^= 1;
				a[on] ^= 1;
				ans.push_back(id);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int one = 0;
	int bad = -1;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] == 1) {
			one ^= 1;
		} else if(bad == -1 && a[i] == -1) {
			bad = i;
		} else if(a[i] == -1) {
			a[i] = 0;
		}
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].emplace_back(v, i);
		edges[v].emplace_back(u, i);
	}
	if(bad != -1) {
		a[bad] = one;
	} else if(one) {
		std::cout << "-1\n";
		return 0;
	}
	go(0);
	assert(a[0] == 0);
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}