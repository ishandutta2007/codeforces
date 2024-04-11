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



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), maxPref(n), rev(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
			rev[a[i]] = i;

			maxPref[i] = a[i];
			if (i != 0) maxPref[i] = max(maxPref[i - 1], maxPref[i]);
		}
		Graph<void*> graph(n);
		stack<int> st1;
		stack<int> st2;
		for (int i = n - 1; i >= 0; i--) {
			while ((!st1.empty()) && (a[st1.top()] > a[i])) st1.pop();
			if (!st1.empty()) {
				// cerr << st1.top() <<  " <=> " << i << endl;
				graph.addUndirectedEdge(st1.top(), i);
			}
			st1.push(i);

			if (i != 0) {
				while ((!st2.empty()) && (a[st2.top()] > maxPref[i - 1])) st2.pop();
				if (!st2.empty()) {
					graph.addUndirectedEdge(st2.top(), i);
				}
				st2.push(i);
			}
		}

		vector<int> used(n);
		function<void(int)> dfs = [&](int x) {
			used[x] = 1;
			for (auto &[y, ind] : graph.g[x]) {
				if (!used[y]) dfs(y);
			}
		};
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				++cnt;
				dfs(i);
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}