#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500100;

int par[ms], adj[ms];
int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	adj[a] |= adj[b];
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m, a, b;
		std::cin >> n >> m >> a >> b;
		for(int i = 0; i < n; i++) {
			par[i] = i;
			adj[i] = 0;
		}
		a--;b--;
		std::set<int> bad;
		bad.insert(a);
		bad.insert(b);
		while(m--) {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			int cnt = bad.count(u) + bad.count(v);
			if(cnt == 2) {
				continue;
			} else if(cnt == 1) {
				if(bad.count(u)) {
					std::swap(u, v);
				}
				u = getPar(u);
				adj[u] |= 1 << (v == a ? 1 : 0);
			} else {
				makeUnion(u, v);
			}
		}
		long long ans = 0;
		long long f[2] = {0LL, 0LL};
		for(int i = 0; i < n; i++) {
			int j = getPar(i);
			if(adj[j] != 0 && adj[j] != 3) {
				// std::cout << i << ", adding to " << adj[j]-1 << '\n';
				f[adj[j]-1] += 1;
			}
		}
		ans += f[0] * f[1];
		std::cout << ans << '\n';	
	}
}