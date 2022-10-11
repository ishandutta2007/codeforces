#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

long long ans = 0;
int par[ms];
int getPar(int x) { return par[x] < 0 ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	ans += (long long) par[a] * par[b];
	par[b] += par[a];
	par[a] = b;
}

std::vector<std::pair<int, int> > edges[ms];
long long ha[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i < n; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		edges[w].emplace_back(u-1, v-1);
	}
	for(int i = 0; i < n; i++) {
		par[i] = -1;
	}
	for(int i = 1; i < ms; i++) {
		for(auto e : edges[i]) {
			makeUnion(e.first, e.second);
		}
		ha[i] = ans;
	}
	while(m--) {
		int x;
		std::cin >> x;
		std::cout << ha[x] << '\n';
	}
}