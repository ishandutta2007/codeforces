#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;

int par[ms];
int getPar(int x) { return par[x] < 0 ? x : par[x] = getPar(par[x]); }
long long makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return 0LL;
	long long ans = (long long) par[a] * par[b];
	par[b] += par[a];
	par[a] = b;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), p(n);
	std::vector<std::vector<int>> edges(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	long long ans = 0;
	for(int rep = 0; rep < 2; rep++) {
		for(int i = 0; i < n; i++) {
			par[i] = -1;
		}
		std::vector<bool> present(n, false);
		for(auto on : p) {
			for(auto to : edges[on]) {
				if(present[to]) {
					ans += makeUnion(on, to) * (rep == 0 ? a[on] : -a[on]);
				}
			}
			present[on] = true;
		}
		std::reverse(p.begin(), p.end());
	}
	std::cout << ans << '\n';
}