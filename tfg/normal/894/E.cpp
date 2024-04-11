#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>

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

struct Edge {
	int u, v;
	long long w;
};

const int ms = 1001000;

std::vector< std::pair<int, long long> > ed[ms];
long long memo[ms];
long long b[ms];

long long dp(int on) {
	long long &ans = memo[on];
	if(ans != -1) return ans;
	ans = b[on];
	for(auto e : ed[on]) {
		ans = std::max(ans, dp(e.first) + e.second + b[on]);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<long long> sum(ms, 0), sum2(ms, 0);
	for(int i = 1; i < ms; i++) {
		sum[i] = sum[i-1] + (long long) i * (i+1) / 2;
		sum2[i] = sum2[i-1] + i;
	}
	auto getValue = [&](long long x) {
		if(x == 0) return 0LL;
		int id = std::lower_bound(sum2.begin(), sum2.end(), x) - sum2.begin();
		//std::cout << "id is " << id << '\n';
		//std::cout << x << " * " << id << " - " << sum[id] << '\n';
		return x * id - sum[id-1];
	};
	int n, m;
	std::cin >> n >> m;
	SCC graph;
	graph.init(n);
	std::vector<Edge> edges(m);
	for(int i = 0; i < m; i++) {
		int u, v;
		long long w;
		std::cin >> u >> v >> w;
		u--;v--;
		//std::cout << "new value is " << w << "\n";
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
		graph.addEdge(u, v);
	}
	graph.tarjan();
	for(auto e : edges) {
		e.u = graph.comp[e.u];
		e.v = graph.comp[e.v];
		if(e.u == e.v) {
			b[e.u] += getValue(e.w);
		} else {
			ed[e.u].emplace_back(e.v, e.w);
		}
	}
	memset(memo, -1, sizeof memo);
	int s;
	std::cin >> s;
	std::cout << dp(graph.comp[s-1]) << '\n';
}