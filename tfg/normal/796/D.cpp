#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const int ms = 300100;

std::vector<int> edges[ms];
int dist[ms];
int a[ms], b[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(dist, -1, sizeof dist);
	int n, k, d;
	std::cin >> n >> k >> d;
	std::queue<int> q;
	for(int i = 0; i < k; i++) {
		int u;
		std::cin >> u;
		if(dist[u] == -1) {
			dist[u] = i;
			q.push(u);
		}
	}
	for(int i = 1; i < n; i++) {
		std::cin >> a[i] >> b[i];
		edges[a[i]].push_back(b[i]);
		edges[b[i]].push_back(a[i]);
	}
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(int i = 0; i < (int) edges[on].size(); i++) {
			int to = edges[on][i];
			if(dist[to] == -1) {
				dist[to] = dist[on];
				q.push(to);
			}
		}
	}
	std::vector<int> ans;
	for(int i = 1; i < n; i++) {
		if(dist[a[i]] != dist[b[i]]) {
			ans.push_back(i);
		}
	}
	std::cout << (int) ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}