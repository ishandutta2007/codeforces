#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int par[ms];

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return false;
	par[a] = b;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int> > edges;
	std::vector<int> freq(n, 0);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		freq[u]++;
		freq[v]++;
		edges.emplace_back(u, v);
	}
	int root = 0;
	for(int i = 0; i < n; i++) {
		if(freq[i] > freq[root]) {
			root = i;
		}
		par[i] = i;
	}
	for(auto e : edges) {
		if(e.first == root || e.second == root) {
			if(makeUnion(e.first, e.second)) {
				std::cout << e.first + 1 << ' ' << e.second + 1 << '\n';
			}
		}
	}
	for(auto e : edges) {
		if(makeUnion(e.first, e.second)) {
			std::cout << e.first + 1 << ' ' << e.second + 1 << '\n';
		}
	}
}