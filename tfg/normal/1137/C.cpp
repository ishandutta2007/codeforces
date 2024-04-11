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
			dfs(i);
		}
	}
};

std::vector<int> last, freq, ed[5005000];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, d;
	std::cin >> n >> m >> d;
	SCC graph;
	graph.init(n * d);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		for(int j = 0; j < d; j++) {
			graph.addEdge(u * d + j, v * d + (j + 1) % d);
		}
	}
	graph.tarjan();
	last.assign(n * d, -1);
	freq.assign(n * d, 0);
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for(int j = 0; j < d; j++) {
			if(str[j] == '1' && last[graph.comp[i * d + j]] != i) {
				//std::cout << "for day " << j + 1 << ", city " << i + 1 << " got stuff in component " << graph.comp[i * d + j] << '\n';
				last[graph.comp[i * d + j]] = i;
				freq[graph.comp[i * d + j]]++;
			}
		}
	}
	for(int i = 0; i < n * d; i++) {
		for(auto j : graph.edges[i]) {
			ed[graph.comp[i]].push_back(graph.comp[j]);
		}
	}
	std::vector<int> dp(n * d, 0);
	for(int i = 0; i < n * d; i++) {
		dp[i] = freq[i];
		for(auto j : ed[i]) {
			if(i != j) dp[i] = std::max(dp[i], freq[i] + dp[j]);
		}
	}
	std::cout << dp[graph.comp[0]] << '\n';
}