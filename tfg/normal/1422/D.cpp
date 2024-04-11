#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int s[2], f[2];
	std::cin >> s[0] >> s[1] >> f[0] >> f[1];
	std::map<int, int> row, col;
	std::vector<std::vector<std::pair<int, int>>> edges(m);
	std::vector<long long> dist(m);
	std::vector<std::pair<int, int>> haha;
	auto addEdge = [&](int u, int v, int c) {
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
	};
	for(int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		if(row.count(x)) {
			addEdge(i, row[x], 0);
		} else {
			row[x] = i;
		}
		if(col.count(y)) {
			addEdge(i, col[y], 0);
		} else {
			col[y] = i;
		}
		dist[i] = std::min(abs(x - s[0]), abs(y - s[1]));
		haha.emplace_back(x, y);
	}
	{
		int last[2] = {-1, -1};
		for(auto wtf : row) {
			if(last[0] != -1) {
				//std::cout << "row edge from " << last[0] << ", " << wtf.second << " or " << last[1] << ", " << wtf.first << "\n";
				addEdge(last[0], wtf.second, wtf.first - last[1]);
			}
			last[0] = wtf.second;
			last[1] = wtf.first;
		}
	}
	{
		int last[2] = {-1, -1};
		for(auto wtf : col) {
			if(last[0] != -1) {
				addEdge(last[0], wtf.second, wtf.first - last[1]);
			}
			last[0] = wtf.second;
			last[1] = wtf.first;
		}
	}
	long long ans = abs(s[0] - f[0]) + abs(s[1] - f[1]);
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> hp;
	for(int i = 0; i < m; i++) {
		hp.push({dist[i], i});
	}
	while(!hp.empty()) {
		int cur = hp.top().second;
		long long curDist = hp.top().first;
		hp.pop();
		if(curDist != dist[cur]) continue;
		//std::cout << "reaching " << cur << " with dist " << curDist << '\n';
		for(auto e : edges[cur]) {
			int to = e.first;
			long long toDist = e.second + curDist;
			if(toDist < dist[to]) {
				//std::cout << "from " << cur << " to " << to << " with dist " << toDist << '\n';
				dist[to] = toDist;
				hp.push({toDist, to});
			}
		}
		//std::cout << "dist to end is " << curDist + abs(f[0] - haha[cur].first) + abs(f[1] - haha[cur].second) << '\n';
		ans = std::min(ans, curDist + abs(f[0] - haha[cur].first) + abs(f[1] - haha[cur].second));
	}
	std::cout << ans << '\n';
}