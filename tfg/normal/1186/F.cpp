#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

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

	std::vector<int> solve(int on = 0) {
		std::vector<int> ans;
		dfs(on, ans);
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
		} while(!edges[on].empty() || on != st);
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
	std::set<std::pair<int, int>> wtf;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 1) {
			int j = i+1;
			while(j < n && !deg[j]) j++;
			assert(j < n);
			deg[i] = (deg[i] + 1) % 2;
			deg[j] = (deg[j] + 1) % 2;
			graph.addEdge(i, j);
			wtf.insert({std::min(i, j), std::max(i, j)});
		}
	}
	std::vector<bool> visit(n, false);
	std::vector<std::pair<int, int>> ans;
	for(int i = 0; i < n; i++) {
		if(visit[i]) continue;
		auto circuit = graph.solve(i);
		int st = 0;
		int lst = -1;
		std::pair<int, int> kek(-1, -1);
		for(auto nxt : circuit) {
			visit[nxt] = true;
			if(lst != -1) {
				std::pair<int, int> haha(std::min(lst, nxt), std::max(lst, nxt));
				if(wtf.count(haha)) {
					st = 0;
					wtf.erase(haha);
					if(kek.first != -1) {
						ans.push_back(kek);
					}
					kek = std::pair<int, int>(-1, -1);
				} else if(st == 0) {
					ans.emplace_back(lst + 1, nxt + 1);
					kek = std::pair<int, int>(-1, -1);
					st ^= 1;
				} else {
					kek = std::pair<int, int>(lst+1, nxt+1);
					st ^= 1;
				}
			}
			lst = nxt;
		}
		if(kek.first != -1) {
			ans.push_back(kek);
		}
	}
	std::cout << ans.size() << '\n';
	for(auto e : ans) {
		std::cout << e.first << ' ' << e.second << '\n';
	}
}