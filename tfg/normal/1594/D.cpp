#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		struct Edge {
			int to, x;
		};
		std::vector<std::vector<Edge>> edges(n);
		while(m--) {
			int u, v;
			std::string str;
			std::cin >> u >> v >> str;
			int x = str == "imposter" ? 1 : 0;
			u--;v--;
			edges[u].push_back({v, x});
			edges[v].push_back({u, x});
		}
		int ans = 0;
		std::vector<int> col(n, -1);
		for(int st = 0; st < n && ans != -1; st++){
			if(col[st] != -1) {
				continue;
			}
			std::vector<int> verts(1, st);
			col[st] = 0;
			int f[2] = {0, 0};
			bool good = true;
			for(int i = 0; i < (int) verts.size(); i++) {
				int on = verts[i];
				f[col[on]]++;
				for(auto [to, x] : edges[on]) {
					if(col[to] == -1) {
						col[to] = col[on] ^ x;
						verts.push_back(to);
					} else {
						good = good && col[to] == (col[on] ^ x);
					}
				}
			}
			if(!good) {
				ans = -1;
			} else {
				ans += std::max(f[0], f[1]);
			}
		}
		std::cout << ans << '\n';
	}
}