#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	int u, v, c;
};

int par[200200], size[200200];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) {
		if(size[a] == 0) {
			size[a] = 1;
			return true;
		}
	} else {
		if(size[a] + size[b] <= 1) {
			size[a] += size[b];
			par[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<Edge> edges(m);
	for(auto &edge : edges) {
		std::cin >> edge.u >> edge.v >> edge.c;
		edge.u--, edge.v--;
	}
	std::sort(edges.begin(), edges.end(), [](auto e1, auto e2) { return e1.c > e2.c; });
	for(int i = 0; i < n; i++) {
		par[i] = i;
		size[i] = 0;
	}
	long long ans = 0;
	for(auto edge : edges) {
		if(makeUnion(edge.u, edge.v)) {
			ans += edge.c;
		}
	}
	std::cout << ans << std::endl;
}