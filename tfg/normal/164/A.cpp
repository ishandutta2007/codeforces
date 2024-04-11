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
	std::vector<std::vector<int>> edges(n);
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
	}
	std::vector<int> cnt(n, 0);
	for(int rep = 0; rep < 2; rep++) {
		SCC graph;
		graph.init(n);
		for(int i = 0; i < n; i++) {
			if(a[i] == 0 || (a[i] == 2 && rep == 0) || (a[i] == 1 && rep == 1)) {
				graph.edges[i] = edges[i];
			}
		}
		graph.tarjan();
		std::vector<std::vector<int>> ed(n);
		std::vector<bool> good(n, false);
		for(int i = 0; i < n; i++) {
			if(a[i] == 0 || (a[i] == 2 && rep == 0) || (a[i] == 1 && rep == 1)) {
				for(auto j : edges[i]) {
					ed[graph.comp[i]].push_back(graph.comp[j]);
				}
			}
				if(a[i] == 2) good[graph.comp[i]] = true;
		}
		for(int i = 0; i < n; i++) {
			for(auto j : ed[i]) {
				good[i] = good[i] || good[j];
			}
		}
		for(int i = 0; i < n; i++) {
			bool hmm = good[graph.comp[i]];
			for(auto j : edges[i]) {
				hmm = hmm || good[graph.comp[j]];
			}
			if(a[i] != 2 && hmm) {
				cnt[i]++;
				//std::cout << "adding to " << i << '\n';
			}
			if(a[i] == 1) {
				a[i] = 2;
			} else if(a[i] == 2) {
				a[i] = 1;
			}
		}
		std::vector<std::vector<int>> haha(n);
		for(int i = 0; i < n; i++) {
			for(auto j : edges[i]) {
				haha[j].push_back(i);
			}
		}
		edges = haha;
	}
	for(int i = 0; i < n; i++) {
		int hmm = cnt[i] - (a[i] == 0 ? 1 : 0);
		std::cout << std::max(0, hmm) << '\n';
	}
}