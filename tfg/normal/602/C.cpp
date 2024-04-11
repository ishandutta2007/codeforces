#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <cstdio>

typedef std::pair<int, int> ii;

const int ms = 404;

bool can[ms][ms], got[ms][ms];
int dist[ms][ms];

std::vector<int> edges[2][ms];

void bfs(int t) {
	memset(dist[t], 0x3f, sizeof dist[t]);
	std::queue<int> q;
	q.push(0);
	dist[t][0] = 0;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(auto to : edges[t][on]) {
			if(dist[t][on] + 1 < dist[t][to]) {
				dist[t][to] = 1 + dist[t][on];
				q.push(to);
			}
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		//std::cin >> u >> v;
		scanf("%i %i", &u, &v);
		u--;
		v--;
		//std::cout << "(" << u << ", " << v << ") type 2\n";
		edges[0][u].push_back(v);
		edges[0][v].push_back(u);
		can[u][v] = can[v][u] = true;
	}
	for(int i = 0; i < n; i++) {
		can[i][i] = true;
		for(int j = 0; j < n; j++) {
			if(!can[i][j]) {
				//std::cout << "(" << i << ", " << j << ") type 2\n";
				edges[1][i].push_back(j);
				edges[1][j].push_back(i);
			}
		}
	}
	edges[0][n - 1].clear();
	edges[1][n - 1].clear();
	edges[0][n - 1].push_back(n - 1);
	edges[1][n - 1].push_back(n - 1);
	bfs(0);
	bfs(1);
	if(dist[0][n - 1] + dist[1][n - 1] >= 0x3f3f3f3f) {
		std::cout << "-1\n";
		return 0;
	}
	if(n <= 350) {
		memset(dist, 0x3f, sizeof dist);
		dist[0][0] = 0;
		std::queue<ii> q;
		q.push(ii(0, 0));
		while(!q.empty()) {
			int u = q.front().first;
			int v = q.front().second;
			q.pop();
			//std::cout << "on " << u << ", " << v << " dist " << dist[u][v] << "\n";
			if(u == n - 1 && v == n - 1) {
				break;
			}
			if(u == v && u + v != 0) {
				continue;
			}
			
			if(got[0][u] || got[1][v]) {
				continue;
			}
			//std::cout << "going\n";
			if(u == n - 1) {
				got[1][v] = true;
			}
			if(v == n - 1) {
				got[0][u] = true;
			}
			int cur_dist = dist[u][v];
			for(auto uu : edges[0][u]) {
				for(auto vv : edges[1][v]) {
					//std::cout << "trying (" << uu << ", " << vv << ")\n";
					if(1 + cur_dist < dist[uu][vv]) {
						dist[uu][vv] = 1 + cur_dist;
						q.push(ii(uu, vv));
					}
				}
			}
		}
		std::cout << dist[n - 1][n - 1] << '\n';
	} else {
		int ans = std::max(dist[0][n - 1], dist[1][n - 1]);
		std::cout << ans << '\n';
	}
}