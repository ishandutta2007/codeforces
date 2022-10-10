#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int size[ms], par[ms];

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	size[a] += size[b];
	par[b] = a;
}

struct Edge {
	int u, v, c;

	void read() {
		std::cin >> u >> v >> c;
		u--;v--;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	for(int i = 0; i < k; i++) {
		int v;
		std::cin >> v;
		v--;
		size[v]++;
	}
	std::vector<Edge> edges(m);
	for(int i = 0; i < m; i++) {
		edges[i].read();
	}
	std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.c < b.c; });
	for(auto e : edges) {
		makeUnion(e.u, e.v);
		if(size[getPar(e.u)] == k) {
			for(int i = 0; i < k; i++) {
				std::cout << e.c << (i + 1 == k ? '\n' : ' ');
			}
			return 0;
		}
	}
}