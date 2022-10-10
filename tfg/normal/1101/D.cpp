#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int large[ms];
int a[ms];
std::vector<std::pair<int, int>> ed[ms];
std::vector<int> edges[ms];
int dist[ms];

int dfs(int on, int par = -1, int h = 1) {
	dist[on] = h;
	int ans = on;
	for(auto to : edges[on]) {
		if(to == par) continue;
		int nxt = dfs(to, on, h + 1);
		if(dist[nxt] > dist[ans]) {
			ans = nxt;
		}
	}
	return ans;
}

int gcd(int aa, int b) { return b == 0 ? aa : gcd(b, aa % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(large[i]) continue;
		for(int j = i; j < ms; j += i) {
			large[j] = i;
		}
	}
	int n;
	std::cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] > 1) {
			ans = 1;
		}
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		int g = gcd(a[u], a[v]);
		while(g > 1) {
			int p = large[g];
			while(g % p == 0) {
				g /= p;
			}
			ed[p].emplace_back(u, v);
		}
	}
	for(int i = 2; i < ms; i++) {
		for(auto e : ed[i]) {
			edges[e.first].push_back(e.second);
			edges[e.second].push_back(e.first);
			dist[e.first] = dist[e.second] = 0;
		}
		for(auto e : ed[i]) {
			if(!dist[e.first]) {
				ans = std::max(ans, dist[dfs(dfs(dfs(e.first)))]);
			}
		}
		for(auto e : ed[i]) {
			edges[e.first].clear();
			edges[e.second].clear();
		}
	}
	std::cout << ans << '\n';
}