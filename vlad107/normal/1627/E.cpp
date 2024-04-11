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

struct LvlEdge {
	int y;
	int px;
	int py;
	int h;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> cost(n);
		for (int &x : cost) cin >> x;

		vector<vector<int>> lvl(n);
		lvl[0].push_back(0);
		lvl[n - 1].push_back(m - 1);
		vector<vector<LvlEdge>> edges(n);
		vector<vector<long long>> dst(n);

 		for (int i = 0; i < k; i++) {
 			int a, b, c, d, h;
			cin >> a >> b >> c >> d >> h;
			--a; --b; --c; --d;

			lvl[a].push_back(b);
			lvl[c].push_back(d);
			edges[c].push_back(LvlEdge {d, a, b, h});
 		}

 		for (auto &curLvl : lvl) {
 			sort(curLvl.begin(), curLvl.end());
			curLvl.resize(unique(curLvl.begin(), curLvl.end()) - curLvl.begin());
 		}

 		for (int i = 0; i < n; i++) {
 			dst[i].assign(lvl[i].size(), numeric_limits<long long>::max());
 			if (i == 0) dst[i][0] = 0;
 			for (const auto &edge: edges[i]) {
 				int px = edge.px;
 				int py = lower_bound(lvl[px].begin(), lvl[px].end(), edge.py) - lvl[px].begin();
 				int y = lower_bound(lvl[i].begin(), lvl[i].end(), edge.y) - lvl[i].begin();

 				if (dst[px][py] != numeric_limits<long long>::max()) {
 					dst[i][y] = min(dst[i][y], dst[px][py] - edge.h);
 				}
 			}
 			Dijkstra<long long, long long> dijkstra(lvl[i].size());
 			for (int y = 0; y + 1 < lvl[i].size(); y++) {
 				long long edgeCost = cost[i] * 1LL * (lvl[i][y + 1] - lvl[i][y]);
 				dijkstra.addEdge(y, y + 1, edgeCost);
 				dijkstra.addEdge(y + 1, y, edgeCost);
 			}
 			dijkstra.dist = dst[i];
 			dijkstra.prev.assign(lvl[i].size(), -1);
 			for (int y = 0; y < lvl[i].size(); y++) {
 				if (dst[i][y] != numeric_limits<long long>::max()) {
 					dijkstra.prev[y] = y;
 				}
 			}
 			dijkstra.run();
 			dst[i] = dijkstra.dist;
 		}
 		if (dst[n - 1].back() == numeric_limits<long long>::max()) {
 			cout << "NO ESCAPE\n";
 		} else {
 			cout << dst[n - 1].back() << "\n";
 		}
	}
	return 0;
}