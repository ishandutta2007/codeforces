#include <iostream>
#include <vector>

struct SCC {
	std::vector<std::vector<int>> edges;
	std::vector<int> comp, st, idx;
	int c;

	void init(int n) {
		edges.resize(n);
		comp.assign(n, -1);
		idx.assign(n, -2);
		st.clear();
	}

	void addEdge(int u, int v) {
		edges[u].push_back(v);
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
			while(1) {
				int v = st.back();
				st.pop_back();
				idx[v] = -1;
				comp[v] = comp[on];
				if(v == on) {
					break;
				}
			}
		}
		return comp[on];
	}

	void tarjan() {
		c = 0;
		for(int i = 0; i < edges.size(); i++) {
			dfs(i);
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, s;
	std::cin >> n >> m >> s;
	s--;
	SCC graph;
	graph.init(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		graph.addEdge(u - 1, v - 1);
	}
	graph.tarjan();
	std::vector<int> in(n, 0);
	for(int i = 0; i < n; i++) {
		for(auto to : graph.edges[i]) {
			if(graph.comp[i] != graph.comp[to]) in[graph.comp[to]]++;
		}
	}
	int ans = 0;
	if(in[graph.comp[s]] == 0) {
		ans--;
	}
	std::vector<bool> vis(n, false);
	for(int i = 0; i < n; i++) {
		if(!vis[graph.comp[i]] && in[graph.comp[i]] == 0) {
			ans++;
			vis[graph.comp[i]] = true;
		}
	}
	std::cout << ans << std::endl;
}