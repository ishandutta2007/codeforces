#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>

const int MOD = 1e9 + 7;
const int ms = 500500;

std::vector<int> ed[ms];
int two[ms];

bool visit[ms];
int c[ms];
bool dfs(int on) {
	if(visit[on]) {
		return true;
	}
	visit[on] = true;
	for(auto to : ed[on]) {
		if(visit[to]) {
			if(c[on] == c[to]) {
				return false;
			}
		} else {
			c[to] = 1 - c[on];
			if(!dfs(to)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	two[0] = 1;
	for(int i = 1; i < ms; i++) {
		two[i] = 2 * two[i - 1] % MOD;
	}
	int n, m, k;
	std::cin >> n >> m >> k;
	std::map<long long, std::vector<std::pair<int, int>>> edges;
	std::vector<long long> key(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> key[i];
		scanf("%lld", &key[i]);
		//std::cout << "key for " << i << " is " << key[i] << std::endl;
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		long long x = key[u] ^ key[v];
		edges[x].emplace_back(u, v);
	}
	int ans = 0;
	for(auto x : edges) {
		/*std::cout << "for x " << x.first << " got edges:";
		for(auto e : x.second) {
			std::cout << " (" << e.first << ", " << e.second << ")";
		}
		std::cout << std::endl;*/
		std::vector<int> verts;
		for(auto e : x.second) {
			int u = e.first, v = e.second;
			verts.push_back(u);
			verts.push_back(v);
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		std::sort(verts.begin(), verts.end());
		verts.resize(std::unique(verts.begin(), verts.end()) - verts.begin());
		int cur = two[n - (int) verts.size()];
		for(auto v : verts) {
			if(visit[v]) {
				continue;
			}
			if(dfs(v)) {
				cur = cur * 2 % MOD;
			} else {
				cur = 0;
			}
		}
		ans = (ans + cur) % MOD;
		for(auto v : verts) {
			ed[v].clear();
			visit[v] = false;
		}
	}
	long long all = 1LL << k;
	all -= edges.size();
	all = all % MOD;
	all = all * two[n] % MOD;
	ans = (ans + (int) all) % MOD;
	std::cout << ans << std::endl;
}