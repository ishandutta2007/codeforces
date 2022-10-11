#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<int>> edges(n);
	std::vector<int> u(m);
	std::vector<int> v(m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &u[i], &v[i]);
		//std::cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
		edges[u[i]].push_back(v[i]);
		edges[v[i]].push_back(u[i]);
	}
	std::vector<int> dist(n, n + 10);
	dist[0] = 0;
	std::queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		int d = dist[on] + 1;
		//std::cout << "visiting " << on << " with dist " << dist[on] << std::endl;
		for(auto to : edges[on]) {
			if(d < dist[to]) {
				dist[to] = d;
				q.push(to);
			}
		}
	}
	std::vector<std::vector<int>> choices(n);
	for(int i = 0; i < m; i++) {
		if(dist[u[i]] + 1 == dist[v[i]]) {
			choices[v[i]].push_back(i);
		} else if(dist[v[i]] + 1 == dist[u[i]]) {
			choices[u[i]].push_back(i);
		}
	}
	int x = k;
	for(int i = 0; i < n; i++) {
		x /= std::max(1, (int) choices[i].size());
	}
	if(x != 0) {
		x = 1;
		for(int i = 0; i < n; i++) {
			x *= std::max(1, (int) choices[i].size());
		}
		k = x;
	}
	std::cout << k << std::endl;
	for(int mask = 0; mask < k; mask++) {
		int cur = mask;
		std::string ans(m, '0');
		for(int i = 0; i < n; i++) {
			int size = choices[i].size();
			if(size > 0) {
				ans[choices[i][cur % size]] = '1';
				cur /= size;
			}
		}
		//std::cout << ans << '\n';
		printf("%s\n", ans.c_str());
	}
}