#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

using namespace std;

template<typename DataT>
struct Edge { int u, v; DataT data; };

template<>
struct Edge<void> { int u, v; };

template<class DataT>
struct Graph {
	using NodeEdges = vector<pair<int, int>>;
	using EdgeT = Edge<DataT>;

	explicit Graph(int n) : sz(n) { g.resize(n); edges.clear(); }
	Graph(const Graph &other) { sz = other.sz; edges = other.edges; g = other.g; }
	Graph(Graph &&other) { sz = other.sz; edges = move(other.edges); g = move(other.g); }

	template<typename U = DataT, typename std::enable_if_t<!std::is_same_v<U, void>, bool> = true>
	void add_edge(int u, int v, U data) {
		int edgeIndex = edges.size();
		edges.push_back({u, v, data});
		g[u].push_back({v, edgeIndex});
	}

	void add_edge(int u, int v) {
		int edgeIndex = edges.size();
		edges.push_back({u, v});
		g[u].push_back({v, edgeIndex});		
	}

	template<typename U = DataT, typename std::enable_if_t<!std::is_same_v<U, void>, bool> = true>
	void add_undirected_edge(int u, int v, U data) {
		int edgeIndex = edges.size();
		edges.push_back({u, v, data});
		g[u].push_back({v, edgeIndex});
		g[v].push_back({u, edgeIndex});		
	}

	void add_undirected_edge(int u, int v) {
		int edgeIndex = edges.size();
		edges.push_back({u, v});
		g[u].push_back({v, edgeIndex});
		g[v].push_back({u, edgeIndex});		
	}

	NodeEdges &operator[](int x) { return g[x]; }
	int size() const { return size; }
	EdgeT const &edge_by_index(int ind) const { return edges[ind]; }

	template<typename U = DataT, typename std::enable_if_t<!std::is_same_v<U, void>, bool> = true>
	U const &get_data(int edge_index) const { return edges[edge_index].data; }
private:
	int sz;
	vector<EdgeT> edges;
	vector<NodeEdges> g;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		Graph<int> gr(n);
		for (int i = 0; i < m; i++) {
			int tp, x, y;
			cin >> tp >> x >> y;
			--tp; --x; --y;
			gr.add_undirected_edge(x, y, tp);
		}

		vector<int> orient(n, -1);
		function<void(int, int, vector<int>&)> dfs = [&](int x, int cur_orient, vector<int> &v) {
			orient[x] = cur_orient;
			v.push_back(x);
			for (auto &[y, ind] : gr[x]) {
				if (orient[y] < 0) {
					dfs(y, cur_orient ^ 1, v);
				}
			}
		};

		vector<int> rev(n);
		bool bad = false;
		int cur_num = 0;
		vector<int> pos(n);
		for (int i = 0; i < n; i++) {
			if (orient[i] != -1) continue;
			vector<int> v;
			dfs(i, 0, v);
			for (int i = 0; i < v.size(); i++) rev[v[i]] = i;

			Graph<void> g_ineq(v.size());
			for (int u = 0; u < v.size(); u++) {
				int x = v[u];
				for (auto [y, ind] : gr[x]) {
					if (orient[x] == orient[y]) {
						bad = true;
						break;
					}
					int tp = gr.get_data(ind);
					int v = rev[y];
					if (((orient[x] == 0) && (tp == 1)) || ((orient[x] == 1) && (tp == 0))) {
						g_ineq.add_edge(v, u);
					} else {
						g_ineq.add_edge(u, v);
					}
				}
			}
			if (bad) break;
			vector<int> sorted;
			vector<int> used(v.size());
			function<void(int)> topsort = [&](int x) {
				used[x] = 1;
				for (auto [y, ind] : g_ineq[x]) {
					if (!used[y]) {
						topsort(y);
					}
				}
				sorted.push_back(x);
			};
			for (int x = 0; x < v.size(); x++) {
				if (!used[x]) {
					topsort(x);
				}
			}
			reverse(sorted.begin(), sorted.end());
			for (int i = 0; i < sorted.size(); i++) {
				pos[v[sorted[i]]] = cur_num++;
			}
			if (bad) break;
		}

		for (int x = 0; x < n; x++) {
			for (auto [y, ind] : gr[x]) {
				int tp = gr.get_data(ind);
				bool ok = false;
				if (tp == 0) {
					if ((orient[x] == 0) && (orient[y] == 1) && (pos[x] < pos[y])) {
						ok = true;
					} else if ((orient[x] == 1) && (orient[y] == 0) && (pos[y] < pos[x])) {
						ok = true;
					}
				} else {
					if ((orient[x] == 0) && (orient[y] == 1) && (pos[y] < pos[x])) {
						ok = true;
					} else if ((orient[x] == 1) && (orient[y] == 0) && (pos[x] < pos[y])) {
						ok = true;
					}
				}
				if (!ok) {
					bad = true;
					break;
				}
			}
			if (bad) break;
		}

		if (bad) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << (orient[i] == 0 ? "L" : "R") << " " << pos[i] << "\n";
		}
	}
	return 0;
}