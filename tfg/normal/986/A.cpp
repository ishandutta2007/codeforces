#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

typedef std::pair<int, int> ii;
const int ms = 100100;

std::vector<int> edges[ms];
int dist[101][ms];
int got[ms];
int cost[ms];

int l = 0, r = 0;
ii q[ms * 101];

int main() {
	int n, m, k, s;
	std::cin >> n >> m >> k >> s;
	memset(dist, 0x3f, sizeof dist);
	for(int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		t--;
		dist[t][i] = 0;
		q[r++] = ii(i, t);
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(; l < r; l++) {
		int on = q[l].first;
		int t = q[l].second;
		int cur_dist = dist[t][on];
		//std::cout << "on (" << on << ", " << t << ") got dist " << cur_dist << std::endl;
		for(auto to : edges[on]) {
			if(cur_dist + 1 < dist[t][to]) {
				dist[t][to] = cur_dist + 1;
				q[r++] = ii(to, t);
			}
		}
		if(got[on] < s) {
			cost[on] += cur_dist;
			got[on]++;
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d%c", cost[i], i + 1 == n ? '\n' : ' ');
	}
}