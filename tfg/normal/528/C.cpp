#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <const bool BIDIRECTIONAL>
class EulerCircuit {
public:
	void init(int size) {
		n = size;
		edges.resize(n);
		loops.resize(n, 0);
	}

	void addEdge(int u, int v) {
		if(u == v) {
			loops[u]++;
			return;
		}
		int cur = (int) used.size();
		used.push_back(false);
		edges[u].emplace_back(v, cur);
		if(BIDIRECTIONAL) {
			edges[v].emplace_back(u, cur);
		}
	}

	std::vector<int> solve() {
		std::vector<int> ans;
		dfs(0, ans);
		return ans;
	}
private:
	int n;
	std::vector<int> loops;
	std::vector<std::vector<std::pair<int, int>>> edges;
	std::vector<bool> used;

	void fix(int on) {
		while(!edges[on].empty() && used[edges[on].back().second]) {
			edges[on].pop_back();
		}
	}

	void dfs(int on, std::vector<int> &ans) {
		fix(on);
		int st = on;
		std::vector<int> path;
		if(!edges[on].empty()) do {
			path.push_back(on);
			used[edges[on].back().second] = true;
			on = edges[on].back().first;
			fix(on);
		} while(!edges[on].empty() && on != st);
		assert(on == st);
		for(auto x : path) {
			dfs(x, ans);
		}
		ans.push_back(on);
		while(loops[on] > 0) {
			loops[on]--;
			ans.push_back(on);
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> deg(n, 0);
	EulerCircuit<true> graph;
	graph.init(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		graph.addEdge(u, v);
		deg[u] = (deg[u] + 1) % 2;
		deg[v] = (deg[v] + 1) % 2;
	}
	for(int i = 0; i < n; i++) {
		if(deg[i] == 1) {
			int j = i+1;
			while(j < n && !deg[j]) j++;
			assert(j < n);
			deg[i] = (deg[i] + 1) % 2;
			deg[j] = (deg[j] + 1) % 2;
			graph.addEdge(i, j);
		}
	}
	auto circuit = graph.solve();
	if((int) circuit.size() % 2 == 0) circuit.push_back(0);
	std::cout << (int) circuit.size() - 1 << '\n';
	for(int i = 0; i + 1 < (int) circuit.size(); i++) {
		if(i % 2 == 0) std::cout << circuit[i] + 1 << ' ' << circuit[i+1] + 1 << '\n';
		else std::cout << circuit[i+1] + 1 << ' ' << circuit[i] + 1 << '\n';
	}
}