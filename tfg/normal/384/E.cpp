#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int bit[ms];

int qry(int x) {
	int ans = 0;
	for(; x > 0; x -= x & -x) ans += bit[x];
	return ans;
}

void upd(int x, int v) {
	for(; x < ms; x += x & -x) bit[x] += v;
}

void upd(int l, int r, int v) { upd(l, v); upd(r, -v); }

std::vector<int> edges[ms];
int in[ms], out[ms], c = 1;
int h[ms], a[ms], b[ms];

void dfs(int on, int par) {
	in[on] = c++;
	for(auto to : edges[on]) {
		if(to == par) continue;
		h[to] = 1 + h[on];
		dfs(to, on);
	}
	out[on] = c;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, 0);
	for(int i = 0; i < n; i++) {
		if(h[i] % 2) {
			a[i] = -a[i];
		}
		upd(in[i], in[i]+1, a[i]);
	}
	while(m--) {
		int t, x;
		std::cin >> t >> x;
		x--;
		if(t == 1) {
			int val;
			std::cin >> val;
			if(h[x] % 2) val = -val;
			upd(in[x], out[x], val);
		} else {
			std::cout << (h[x] % 2 ? -qry(in[x]) : qry(in[x])) << '\n';
		}
	}
}