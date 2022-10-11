#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const int ms = 3030;

std::vector<int> edges[ms];
int dist[ms][ms];

void bfs(int s) {
	dist[s][s] = 0;
	std::queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(auto to : edges[cur]) {
			if(1 + dist[s][cur] < dist[s][to]) {
				dist[s][to] = 1 + dist[s][cur];
				q.push(to);
			}
		}
	}
}

int main() {
	memset(dist, 0x3f, sizeof dist);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		bfs(i);
	}
	int s[2], t[2], l[2];
	for(int i = 0; i < 2; i++) {
		std::cin >> s[i] >> t[i] >> l[i];
		if(dist[s[i]][t[i]] > l[i]) {
			std::cout << "-1\n";
			return 0;
		}
	}
	int ans = m - dist[s[0]][t[0]] - dist[s[1]][t[1]];
	ans = std::max(0, ans);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			bool can = true;
			int cur_ans = m - dist[i][j];
			for(int k = 0; k < 2; k++) {
				int cost = std::min(dist[s[k]][i] + dist[j][t[k]], dist[s[k]][j] + dist[i][t[k]]);
				if(cost + dist[i][j] > l[k]) {
					//std::cout << "on " << i << ", " << j << " couldn't on " << k << "\n";
					can = false;
				}
				cur_ans -= cost;
			}
			if(!can) {
				continue;
			}
			ans = std::max(ans, cur_ans);
			//std::cout << "could on " << i << ", " << j << ", got ans " << cur_ans << "\n";
		}
	}
	std::cout << ans << '\n';
}