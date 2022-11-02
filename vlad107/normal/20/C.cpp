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
#include <array>
#include <limits>

using namespace std;

template<typename TEdgeCost, typename TRes>
struct Dijkstra {
	using Edge = pair<int, TEdgeCost>; // first is an endpoint, second is a cost
	using Graph = vector<vector<Edge>>;
 
	static const TRes MAX_VALUE;
 
	Graph g;
	vector<TRes> dist;
	vector<int> prev;
	int start = -1;
 
	Dijkstra(int n) {
		g = Graph(n);
	}
 
	void addEdge(int x, int y, TEdgeCost cost) {
		g[x].emplace_back(y, cost);
	}
 
	void run(
		function<TRes(TRes, TEdgeCost)> calcDist = [](TRes x, TEdgeCost y) { return x + y; }
	) { // calculates all distances based on initial dist & prev distribution
		using Q_ELEM = pair<TRes, int>;
		priority_queue<Q_ELEM, vector<Q_ELEM>, greater<Q_ELEM>> q;
 
 		for (int i = 0; i < dist.size(); i++) {
 			if (prev[i] != -1) q.push({dist[i], i});
 		}
		while (!q.empty()) {
			auto [curDist, x] = q.top();
			q.pop();
			if (curDist != dist[x]) continue;
			for (auto &[y, cost] : g[x]) {
				TRes newDist = calcDist(curDist, cost);
				if (newDist < dist[y]) {
					dist[y] = newDist;
					prev[y] = x;
					q.push({dist[y], y});
				}
			}
		}
	}

	void run(
		int start,
		TRes startDist = TRes{},
		function<TRes(TRes, TEdgeCost)> calcDist = [](TRes x, TEdgeCost y) { return x + y; }
	) {
		this->start = start;
		dist.assign(g.size(), MAX_VALUE);
		prev.assign(g.size(), -1);
		dist[start] = startDist;
		prev[start] = start;
		this->run(calcDist);
	}
 
	vector<int> getPath(int end) {
		if (dist[end] == MAX_VALUE) {
			return {};
		}
		vector<int> res;
		for (int x = end; x != start; x = prev[x]) {
			res.push_back(x);
		}
		res.push_back(start);
		reverse(res.begin(), res.end());
		return res;
	}
};
template<typename T, typename TRes>
const TRes Dijkstra<T, TRes>::MAX_VALUE = numeric_limits<TRes>::max();

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);

  	int n, m;
  	cin >> n >> m;
  	Dijkstra<int, long long> dijkstra(n);
  	for (int i = 0; i < m; i++) {
  		int x, y, cost;
  		cin >> x >> y >> cost;
  		--x; --y;
  		dijkstra.addEdge(x, y, cost);
  		dijkstra.addEdge(y, x, cost);
  	}
  	dijkstra.run(0);
  	if (dijkstra.prev[n - 1] == -1) {
  		cout << -1 << endl;
  	} else {
  		vector<int> res = dijkstra.getPath(n - 1);
  		for (const int &x : res) cout << x + 1 << " ";
  		cout << endl;
  	}
	return 0;
}