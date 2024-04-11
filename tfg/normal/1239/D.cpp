#include <iostream>
#include <vector>
#include <chrono>
#include <random>

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
		//edges[v^1].push_back(u^1);
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
		int n, m;
		std::cin >> n >> m;
		SCC graph;
		graph.init(n);
		while(m--) {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			graph.addEdge(u, v);
		}
		graph.tarjan();
		if(graph.x == 1) {
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
			// take from first scc
			std::vector<int> j, c;
			for(int i = 0; i < n; i++) {
				if(graph.comp[i] == 0) {
					j.push_back(i);
				} else {
					c.push_back(i);
				}
			}
			std::cout << j.size() << ' ' << c.size() << '\n';
			for(int i = 0; i < (int) j.size(); i++) {
				std::cout << j[i] + 1 << (i + 1 == (int) j.size() ? '\n' : ' ');
			}
			for(int i = 0; i < (int) c.size(); i++) {
				std::cout << c[i] + 1 << (i + 1 == (int) c.size() ? '\n' : ' ');
			}
		}
	}
}