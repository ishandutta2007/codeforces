#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int dist[ms];
std::vector<int> edges[ms];
void go(int on, int par, int h) {
	dist[on] = std::max(dist[on], h);
	for(auto to : edges[on]) {
		if(to != par) go(to, on, h+1);
	}
}

int par[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	par[a] = b;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		makeUnion(u, v);
	}
	for(int i = 0; i < n; i++) {
		go(i, i, 0);
	}
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return dist[v1] < dist[v2]; });
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = std::max(ans, dist[i]);
	}
	std::vector<std::pair<int, int>> ed;
	std::vector<bool> marked(n, false);
	int root = -1;
	for(int i = 0; i < n; i++) {
		if(!marked[getPar(p[i])]) {
			marked[getPar(p[i])] = true;
			root = p[i];
		}
	}
	int lul = dist[root];
	for(int i = 0; i < n; i++) {
		if(getPar(p[i]) != getPar(root)) {
			makeUnion(p[i], root);
			ans = std::max(ans, lul + dist[p[i]] + 1);
			lul = std::max(lul, dist[p[i]] + 1);
			ed.emplace_back(p[i], root);
		}
	}
	std::cout << ans << '\n';
	for(auto e : ed) std::cout << e.first + 1 << ' ' << e.second + 1 << '\n';
}