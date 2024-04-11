#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct SCC {
	std::vector<std::vector<int>> edges;
	std::vector<int> comp, st, idx;
	int c, x;

	void init(int n) {
		edges.resize(n);
		comp.assign(n, -1);
		idx.assign(n, -2);
		st.clear();
	}

	void addEdge(int u, int v) {
		edges[u].push_back(v);
		// if using for 2sat, add v^1 -> u^1
	}

	int dfs(int on) {
		if(idx[on] != -2) {
			return idx[on] == -1 ? c : comp[on];
		}
		idx[on] = comp[on] = c++;
		st.push_back(on);
		for(auto to : edges[on]) {
			comp[on] = std::min(comp[on], dfs(to));
		}
		if(idx[on] == comp[on]) {
			int lo = comp[on];
			while(1) {
				int v = st.back();
				st.pop_back();
				idx[v] = -1;
				comp[v] = x;
				if(v == on) {
					break;
				}
			}
			x++;
			return lo;
		}
		return comp[on];
	}

	void tarjan() {
		c = x = 0;
		for(int i = 0; i < (int) edges.size(); i++) {
			// for 2sat, 2 * i is true if comp[2 * i] < comp[2 * i + 1]
			dfs(i);
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		SCC graph;
		graph.init(n);
		for(int i = 0; i < n; i++) {
			char ch;
			std::cin >> ch;
			int j = (i+1)%n;
			if(ch == '>') {
				graph.addEdge(i, j);
			} else if(ch == '<') {
				graph.addEdge(j, i);
			} else {
				graph.addEdge(i, j);
				graph.addEdge(j, i);
			}
		}
		graph.tarjan();
		std::vector<int> wtf(n, 0);
		for(auto c : graph.comp) {
			wtf[c]++;
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(wtf[i] >= 2) {
				ans += wtf[i];
			}
		}
		std::cout << ans << '\n';
	}
}