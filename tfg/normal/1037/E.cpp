#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

const int ms = 200200;

int n, m, k;

int ans[ms];
std::pair<int, int> edges[ms];
std::vector<int> use[ms];
int deg[ms];
bool del[ms];

int main() {
	// std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		use[u].push_back(i);
		use[v].push_back(i);
		deg[u]++;
		deg[v]++;
		edges[i] = std::pair<int, int>(u, v);
	}
	std::queue<int> q;
	for(int i = 1; i <= n; i++) {
		if(deg[i] < k) {
			q.push(i);
		}
	}
	del[m] = true;
	int cur_ans = n;
	for(int i = m; i >= 0; i--) {
		if(!del[i]) {
			int u = edges[i].first, v = edges[i].second;
			if(deg[u] == k) {
				q.push(u);
			}
			if(deg[v] == k) {
				q.push(v);
			}
			deg[u]--;
			deg[v]--;
			del[i] = true;
		}
		while(!q.empty()) {
			cur_ans--;
			int on = q.front();
			q.pop();
			for(auto e : use[on]) {
				if(!del[e]) {
					int u = edges[e].first, v = edges[e].second;
					if(deg[u] == k) {
						q.push(u);
					}
					if(deg[v] == k) {
						q.push(v);
					}
					deg[u]--;
					deg[v]--;
					del[e] = true;
				}
			}
		}
		ans[i] = cur_ans;
	}
	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i + 1]);
	}
}