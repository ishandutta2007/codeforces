#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;
const int MOD = 8 * 9 * 7 * 5;

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
	int n;
	std::cin >> n;
	std::vector<int> sum(n);
	for(int i = 0; i < n; i++) {
		std::cin >> sum[i];
		sum[i] = (sum[i] % MOD + MOD) % MOD;
	}
	SCC graph;
	graph.init(n * MOD);
	for(int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		std::vector<int> to(s);
		for(int j = 0; j < s; j++) {
			std::cin >> to[j];
			to[j]--;
		}
		for(int j = 0; j < MOD; j++) {
			int ha = (j+sum[i])%MOD;
			graph.addEdge(i * MOD + j, to[ha%s] * MOD + ha);
		}
	}
	graph.tarjan();
	int c = graph.x;
	//std::cout << "C is " << c << std::endl;
	std::vector<int> size(c, 0);
	std::vector<int> to(c, -1);
	{
		std::vector<int> step(c, -1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < MOD; j++) {
				int comp = graph.comp[i * MOD + j];
				if(step[comp] != i) {
					step[comp] = i;
					size[comp]++;
				}
				to[comp] = graph.comp[graph.edges[i * MOD + j].back()];
			}
		}
	}
	std::vector<int> ans(c, 0);
	for(int i = 0; i < c; i++) {
		//std::cout << i << ": " << to[i] << '\n';
		if(to[i] == i) {
			ans[i] = size[i];
		} else {
			ans[i] = ans[to[i]];
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int x, y;
		std::cin >> x >> y;
		x--;
		y = (y % MOD + MOD) % MOD;
		std::cout << ans[graph.comp[x * MOD + y]] << '\n';
	}

}