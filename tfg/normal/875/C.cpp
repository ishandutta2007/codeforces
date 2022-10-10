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
		edges[v^1].push_back(u^1);
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
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n);
	for(int i = 0; i < n; i++) {
		int sz;
		std::cin >> sz;
		while(sz--) {
			int val;
			std::cin >> val;
			val--;
			a[i].push_back(val);
		}
	}
	SCC graph;
	graph.init(2*m);
	for(int i = 0; i+1 < n; i++) {
		int lcp = 0;
		while(lcp < (int) std::min(a[i].size(), a[i+1].size()) && a[i][lcp] == a[i+1][lcp]) lcp++;
		if(lcp == (int) a[i].size()) {
			continue;
		} else if(lcp == (int) a[i+1].size()) {
			std::cout << "No\n";
			return 0;
		} else if(a[i][lcp] < a[i+1][lcp]) {
			// if a[i][lcp] is not on, a[i+1][lcp] also isn't on
			//std::cout << a[i][lcp] << ", " << a[i+1][lcp] << " first case\n";
			graph.addEdge(2*a[i][lcp], 2*a[i+1][lcp]);
		} else {
			// a[i][lcp] should be on and a[i+1][lcp] shouldn't be on
			//std::cout << a[i][lcp] << ", " << a[i+1][lcp] << " second case\n";
			graph.addEdge(2*a[i][lcp], 2*a[i][lcp]+1);
			graph.addEdge(2*a[i+1][lcp]+1, 2*a[i+1][lcp]);
		}
	}
	graph.tarjan();
	std::vector<int> ans;
	for(int i = 0; i < 2*m; i += 2) {
		if(graph.comp[i] == graph.comp[i^1]) {
			std::cout << "No\n";
			return 0;
		}
		if(graph.comp[i] > graph.comp[i^1]) {
			ans.push_back(i/2);
		}
	}
	std::cout << "Yes\n";
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] + 1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}

}