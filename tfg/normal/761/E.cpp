#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 33;

struct PT {
	long long x, y;
	PT cw() {
		PT ans;
		ans.x = -y;
		ans.y = x;
		return ans;
	}
	
	PT ccw() {
		PT ans;
		ans.x = y;
		ans.y = -x;
		return ans;
	}
};

std::vector<int> edges[ms];
long long x[ms], y[ms];

void dfs(int on, int par, PT dir) {
	if(on != par) {
		dir.x /= 2;
		dir.y /= 2;
	}
	for(auto to : edges[on]) {
		if(to == par) {
			continue;
		}
		x[to] = x[on] + dir.x;
		y[to] = y[on] + dir.y;
		dfs(to, on, dir.cw());
		dir = dir.ccw();
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
	int root = 0;
	for(int i = 0; i < n; i++) {
		if(edges[i].size() > edges[root].size()) {
			root = i;
		}
	}
	for(int i = 0; i < n; i++) {
		if((int) edges[i].size() > 4) {
			std::cout << "NO\n";
			return 0;
		}
	}
	PT dir;
	dir.x = 1LL << 30;
	dir.y = 0;
	dfs(root, root, dir);
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << x[i] << ' ' << y[i] << '\n';
	}
}