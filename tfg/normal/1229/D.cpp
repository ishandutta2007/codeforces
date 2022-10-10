#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5 * 4 * 3 * 2 * 1;

int getID(int a[5]) {
	int ans = 0;
	int cur = ms;
	for(int i = 0; i < 5; i++) {
		cur /= 5 - i;
		ans += cur * a[i];
		for(int j = 0; j < i; j++) {
			if(a[j] < a[i]) {
				ans -= cur;
			}
		}
	}
	assert(0 <= ans && ans < ms);
	return ans;
}

int to[ms][ms];
int par[ms];

int getPar(int x) { return par[x] < 0 ? x : par[x] = getPar(par[x]); }

struct Edge {
	Edge(int _u, int _v, int _c) {
		u = _u;
		v = _v;
		c = _c;
	}
	int u, v, c;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	{
		int a[5], b[5];
		for(int i = 0; i < 5; i++) {
			a[i] = b[i] = i;
		}
		do {
			do {
				int c[5];
				for(int i = 0; i < 5; i++) {
					c[a[i]] = b[i];
				}
				to[getID(a)][getID(b)] = getID(c);
			} while(std::next_permutation(b, b + 5));
		} while(std::next_permutation(a, a + 5));
	}
	int n, k;
	std::cin >> n >> k;
	std::vector<Edge> edges, nxt;
	auto addEdge = [&](int u, int v, int c) {
		if(getPar(u) == getPar(v)) return 0;
		nxt.emplace_back(u, v, c);
		u = getPar(u), v = getPar(v);
		int ans = 0;
		if(u == getPar(0)) {
			ans = c * -par[v];
		} else if(v == getPar(0)) {
			ans = c * -par[u];
		}
		if(par[u] < par[v]) {
			std::swap(u, v);
		}
		par[v] += par[u];
		par[u] = v;
		return ans;
	};
	long long ans = 0;
	int cost = 0;
	while(n--) {
		cost++;
		for(int i = 0; i < ms; i++) {
			par[i] = -1;
		}
		{
			int a[5];
			for(int i = 0; i < 5; i++) {
				if(i < k) {
					std::cin >> a[i];
					a[i]--;
				} else {
					a[i] = i;
				}
			}
			int id = getID(a);
			for(int i = 0; i < ms; i++) {
				ans += addEdge(i, to[id][i], cost);
			}
		}
		for(auto e : edges) {
			ans += addEdge(e.u, e.v, e.c);
		}
		ans += cost;
		edges.swap(nxt);
		nxt.clear();
	}
	std::cout << ans << '\n';
}