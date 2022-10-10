#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300200;

long long w[ms];
long long a[ms];

std::vector<int> edges[ms];
std::vector<int> lul[ms];
int par[ms];

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }

void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	par[b] = a;
}

long long mx = -1e9;

void dfs(int on, int par) {
	w[on] = a[on];
	for(auto to : edges[on]) {
		if(to == par) continue;
		dfs(to, on);
		if(w[to] > 0) {
			w[on] += w[to];
		}
	}
	mx = std::max(mx, w[on]);
}

long long k = 0;

void dfs2(int on, int par) {
	w[on] = a[on];
	for(auto to : edges[on]) {
		if(to == par) continue;
		dfs2(to, on);
		if(w[to] > 0) {
			w[on] += w[to];
		}
	}
	if(w[on] == mx) {
		w[on] = 0;
		k++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		par[i] = i;
		std::cin >> w[i];
		a[i] = w[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, 0);
	dfs2(0, 0);
	std::cout << mx * k << ' ' << k << '\n';
}