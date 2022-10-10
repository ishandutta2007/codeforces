#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

std::vector<int> bfs(const std::vector<std::vector<int>> &edges, int st) {
	int n = (int) edges.size();
	std::vector<int> dist(n, INF);
	dist[st] = 0;
	std::queue<int> q;
	q.push(st);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(auto to : edges[on]) {
			if(dist[on] + 1 < dist[to]) {
				dist[to] = 1 + dist[on];
				q.push(to);
			}
		}
	}
	return dist;
}

int solve(std::vector<std::pair<int, int>> a) {
	// a.first + b.second >= x
	// b.second >= x - a.first
	// a.second + b.first >= x
	// b.first >= x - a.second
	std::sort(a.begin(), a.end());
	int n = (int) a.size();
	std::vector<std::vector<int>> suf(n+1);
	for(int i = n-1; i >= 0; i--) {
		suf[i] = suf[i+1];
		suf[i].push_back(a[i].second);
		std::sort(suf[i].rbegin(), suf[i].rend());
		while((int) suf[i].size() > 2) suf[i].pop_back();
	}
	auto check = [&](int x) {
		for(int i = 0, j = n; i < n; i++) {
			j = std::upper_bound(a.begin(), a.end(), std::pair<int, int>(x - a[i].second, -1)) - a.begin();
			bool got = j > i;
			for(auto y : suf[j]) {
				if(!got && y == a[i].second) {
					got = true;
					continue;
				}
				if(y + a[i].first >= x) {
					return true;
				}
			}
		}
		return false;
	};
	int l = 0, r = 1e6;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l + 1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> special(k);
	for(int i = 0; i < k; i++) {
		std::cin >> special[i];
		special[i]--;
	}
	std::vector<std::vector<int>> edges(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	auto d1 = bfs(edges, 0);
	auto dn = bfs(edges, n-1);
	std::vector<std::pair<int, int>> a(k);
	for(int i = 0; i < k; i++) {
		a[i] = std::pair<int, int>(d1[special[i]], dn[special[i]]);
	}
	std::cout << std::min(d1[n-1], solve(a)) << std::endl;
}