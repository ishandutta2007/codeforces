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
#include <stack>
#include <limits>

using namespace std;

template<class DataT>
struct Graph {
	struct Edge {
		int u, v;
		DataT data;
	};

	int sz;
	vector<Edge> edges;
	vector<vector<pair<int, int>>> g; // <vertex, edge index>

	Graph(int n) : sz(n) {
		g.resize(n);
		edges.clear();
	}

	Graph(const Graph &other) {
		sz = other.sz;
		edges = other.edges;
		g = other.g;
	}

	Graph(Graph &&other) {
		sz = other.sz;
		edges = move(other.edges);
		g = move(other.g);
	}

	void addEdge(int u, int v, DataT data = DataT()) {
		int edgeIndex = edges.size();
		edges.push_back({u, v, data});

		g[u].push_back({v, edgeIndex});
	}

	void addUndirectedEdge(int u, int v, DataT data = DataT()) {
		int edgeIndex = edges.size();
		edges.push_back({u, v, data});

		g[u].push_back({v, edgeIndex});
		g[v].push_back({u, edgeIndex});		
	}
};

template<class DataT>
struct EulerPath : Graph<DataT> {
	using Gr = Graph<DataT>;
	using Gr::g;
	using Gr::edges;

	vector<int> path; // edge indexes

	EulerPath(const Gr &other) : Gr(other) {}
	EulerPath(Gr &&other) : Gr(forward(other)) {}

	bool run() {
		int totalEdges;
		for	(int i = 0; i < g.size(); i++) {
			totalEdges += (int)g[i].size();
			if (g[i].size() % 2 == 1) {
				return false;
			}
		}

		path.clear();
		path.reserve(totalEdges / 2);
		vector<int> firstNotUsed(g.size());
		vector<bool> used(edges.size());

		auto updateFirstNotUsed = [&used, &firstNotUsed, this](int v) -> bool {
			int &x = firstNotUsed[v];
			while ((x < g[v].size()) && (used[g[v][x].second])) ++x;
			return x != g[v].size();
		};

		for (int i = 0; i < g.size(); i++) {
			stack<pair<int, int>> st;
			st.push({i, -1});
			while (!st.empty()) {
				auto [v, edgeIndex] = st.top();
				if (updateFirstNotUsed(v)) {
					int &x = firstNotUsed[v];
					used[g[v][x].second] = true;
					st.push(g[v][x++]);
				} else {
					if (edgeIndex != -1) {
						path.push_back(edgeIndex);
					}
					st.pop();
				}
			}
		}
		reverse(path.begin(), path.end());
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	
	unordered_map<int, int> localIndex;
	auto getLocalIndex = [&localIndex](int x) {
		auto it = localIndex.find(x);
		if (it == localIndex.end()) {
			int newIndex = localIndex.size();
			localIndex.insert({x, newIndex});
			return newIndex;
		} else {
			return it->second;
		}
	};

	for (int i = 0; i < n; i++) {
		int sz;
		cin >> sz;
		a[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			cin >> a[i][j];
			a[i][j] = getLocalIndex(a[i][j]);
		}
	}
	Graph<pair<int, int>> graph(n + localIndex.size());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			// i <-> x
			graph.addUndirectedEdge(i, n + a[i][j], {i, j});
		}
	}
	EulerPath<pair<int, int>> eulerPath(graph);
	if (!eulerPath.run()) {
		puts("NO");
	} else {
		vector<vector<bool>> res(n);
		for (int i = 0; i < n; i++) res[i].resize(eulerPath.g[i].size());
		for (int i = 0; i < eulerPath.path.size(); i++) {
			auto [x, y] = eulerPath.edges[eulerPath.path[i]].data;
			res[x][y] = i%2;
		}
		puts("YES");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < eulerPath.g[i].size(); j++) {
				putchar(res[i][j] ? 'L' : 'R');
			}
			puts("");
		}
	}
	return 0;
}