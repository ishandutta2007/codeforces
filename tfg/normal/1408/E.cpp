#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	int u, v, c;
};
const int ms = 200200;
int par[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
bool makeUnion(int u, int v) {
	u = getPar(u), v = getPar(v);
	if(u == v) return false;
	par[u] = v;
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::vector<Edge> edges;
	for(int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		while(s--) {
			int u;
			std::cin >> u;
			u--;
			Edge cur;
			cur.u = i;
			cur.v = n + u;
			cur.c = a[i] + b[u];
			edges.push_back(cur);
		}
	}
	std::sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) { return e1.c > e2.c; });
	long long ans = 0;
	for(int i = 0; i < n+m; i++) {
		par[i] = i;
	}
	for(auto e : edges) {
		if(!makeUnion(e.u, e.v)) {
			ans += e.c;
		}
	}
	std::cout << ans << '\n';
}