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
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	SCC graph;
	graph.init(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		graph.addEdge(u, v);
	}
	graph.tarjan();
	std::vector<int> mn(n, 2e9);
	std::vector<int> freq(n, 0);
	for(int i = 0; i < n; i++) {
		if(a[i] < mn[graph.comp[i]]) {
			freq[graph.comp[i]] = 0;
			mn[graph.comp[i]] = a[i];
		}
		if(a[i] == mn[graph.comp[i]]) {
			freq[graph.comp[i]]++;
		}
	}
	int ans = 1;
	long long wut = 0;
	for(int i = 0; i < n; i++) {
		if(freq[i]) {
			//std::cout << "component " << i << " has " << mn[i] << ", " << freq[i] << std::endl;
			ans = (long long) ans * freq[i] % int(1e9 + 7);
			wut += mn[i];
		}
	}
	std::cout << wut << ' ' << ans << std::endl;
}