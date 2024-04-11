#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

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
		for(int i = 0; i < edges.size(); i++) {
			// for 2sat, 2 * i is true if comp[2 * i] < comp[2 * i + 1]
			dfs(i);
		}
	}
};


std::vector<std::pair<int, int>> edges[2][ms];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	SCC graph;
	graph.init(n);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[c][u].emplace_back(v, i + 1);
		if(c == 0) {
			graph.addEdge(u, v);
		}
	}
	graph.tarjan();
	std::vector<int> q[2];
	q[0].push_back(0);
	std::vector<int> in(n, 0);
	for(int i = 0; i < n; i++) {
		for(auto e : edges[0][i]) {
			if(graph.comp[e.first] != graph.comp[i]) {
				in[graph.comp[e.first]]++;
			}
		}
	}
	std::vector<int> dist(n, 0);
	dist[0] = 1;
	std::vector<int> ans;
	while(!q[0].empty() || !q[1].empty()) {
		if(!q[0].empty()) {
			int on = q[0].back();
			//std::cout << "visiting " << on << "\n";
			q[0].pop_back();
			for(auto e : edges[0][on]) {
				if(dist[e.first] == 0) {
					dist[e.first] = 1;
					q[0].push_back(e.first);
				}
			}
			q[1].push_back(on);
			dist[on] = 2;
		} else {
			int on = q[1].back();
			//std::cout << "revisiting " << on << "\n";
			q[1].pop_back();
			while(!edges[1][on].empty()) {
				auto e = edges[1][on].back();
				edges[1][on].pop_back();
				if(in[graph.comp[e.first]] == 0 && dist[e.first] == 0) {
					dist[e.first] = 1;
					q[0].push_back(e.first);
					ans.push_back(e.second);
					q[1].push_back(on);
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(dist[i] == 0) {
			std::cout << "-1\n";
			return 0;
		}
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}