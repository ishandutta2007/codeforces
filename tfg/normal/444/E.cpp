#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	int u, v, c;
};

const int ms = 3000;
int par[ms], val[ms], size[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	assert(a != b);
	val[a] += val[b];
	size[a] += size[b];
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Edge> edges(n-1);
	for(int i = 0; i+1 < n; i++) {
		std::cin >> edges[i].u >> edges[i].v >> edges[i].c;
		edges[i].u--, edges[i].v--;
	}
	std::vector<int> x(n);
	int sumX = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> x[i];
		sumX += x[i];
	}
	auto check = [&](int c) {
		for(int i = 0; i < n; i++) {
			size[i] = 1;
			par[i] = i;
			val[i] = x[i];
		}
		for(auto e : edges) {
			if(e.c < c) {
				makeUnion(e.u, e.v);
			}
		}
		for(int i = 0; i < n; i++) {
			if(par[i] == i && n - size[i] + sumX - val[i] < n) {
				return false;
			}
		}
		return true;
	};
	int l = 0, r = 1e6;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << '\n';
}