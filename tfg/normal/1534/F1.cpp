#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

std::string mat[ms];

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
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	for(int i = 0; i < n; i++) {
		int trash;
		std::cin >> trash;
	}
	SCC graph;
	graph.init(n*m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		if(i > 0) {
			graph.addEdge((i-1)*m+j, i*m+j);
		}
		if(i > 0 && mat[i][j] == '#' && mat[i-1][j] == '#') {
			graph.addEdge(i*m+j, (i-1)*m+j);
		}
		if(j > 0 && mat[i][j-1] == '#') {
			graph.addEdge(i*m+j, i*m+j-1);
		}
		if(j+1 < m && mat[i][j+1] == '#') {
			graph.addEdge(i*m+j, i*m+j+1);
		}
	}
	graph.tarjan();
	int c = graph.x;
	std::vector<std::vector<int>> edges(c);
	std::vector<bool> dirty(c, false), reach(c, false);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mat[i][j] == '#') dirty[graph.comp[i*m+j]] = true;
	for(int i = 0; i < n*m; i++) for(auto j : graph.edges[i]) if(graph.comp[i] != graph.comp[j]) {
		edges[graph.comp[i]].push_back(graph.comp[j]);
	}
	int ans = 0;
	for(int i = c-1; i >= 0; i--) {
		if(!dirty[i] && !reach[i]) {
			continue;
		}
		if(!reach[i]) {
			ans++;
		}
		for(auto j : edges[i]) {
			reach[j] = true;
		}
	}
	std::cout << ans << '\n';
}