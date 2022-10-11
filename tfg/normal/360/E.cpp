#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <utility>

typedef long long ll;
typedef std::pair<ll, int> ii;

const int ms = 10010;

struct Edge {
	int to, l, r;

	void read(int t) {
		std::cin >> to;
		std::cin >> l;
		if(t == 0) {
			r = l;
		} else {
			std::cin >> r;
		}
	}
};

std::vector<Edge> edges[ms];

int ori[ms];
int vals[ms][2];

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	int s1, s2, f;
	std::cin >> s1 >> s2 >> f;
	for(int i = 0; i < m; i++) {
		int from;
		std::cin >> from;
		Edge e;
		e.read(0);
		edges[from].push_back(e);
	}
	for(int i = 0; i < k; i++) {
		int from;
		std::cin >> from;
		Edge e;
		e.read(1);
		edges[from].push_back(e);
		ori[i] = from;
		vals[i][0] = e.l;
		vals[i][1] = e.r;
	}
	std::priority_queue<ii, std::vector<ii>, std::greater<ii> > hp;
	std::vector<ll> dist(n + 1, 1e18);
	std::vector<int> mask(n + 1, 0);
	mask[s1] |= 1;
	mask[s2] |= 2;
	hp.push(ii(0, s1));
	hp.push(ii(0, s2));
	dist[s1] = dist[s2] = 0;
	while(!hp.empty()) {
		int on = hp.top().second;
		ll cur_dist = hp.top().first;
		hp.pop();
		if(cur_dist != dist[on]) continue;
		for(auto e : edges[on]) {
			int cur_cost = mask[on] == 1 ? e.l : e.r;
			if(dist[e.to] > cur_dist + cur_cost) {
				dist[e.to] = cur_dist + cur_cost;
				hp.push(ii(dist[e.to], e.to));
				mask[e.to] = 0;
			}
			if(dist[e.to] == cur_dist + cur_cost) {
				mask[e.to] |= mask[on];
			}
		}
	}
	if(mask[f] == 1) {
		if(mask[f] == 1) {
			std::cout << "WIN\n";
		} else {
			std::cout << "DRAW\n";
		}
		for(int i = 0; i < k; i++) {
			std::cout << (mask[ori[i]] == 1 ? vals[i][0] : vals[i][1]) << (i + 1 == k ? '\n' : ' ');
		}
		return 0;
	}
	dist.assign(n + 1, 1e18);
	mask.assign(n + 1, 0);
	mask[s1] |= 1;
	mask[s2] |= 2;
	hp.push(ii(0, s1));
	hp.push(ii(0, s2));
	dist[s1] = dist[s2] = 0;
	while(!hp.empty()) {
		int on = hp.top().second;
		ll cur_dist = hp.top().first;
		hp.pop();
		if(cur_dist != dist[on]) continue;
		for(auto e : edges[on]) {
			int cur_cost = mask[on] != 2 ? e.l : e.r;
			if(dist[e.to] > cur_dist + cur_cost) {
				dist[e.to] = cur_dist + cur_cost;
				hp.push(ii(dist[e.to], e.to));
				mask[e.to] = 0;
			}
			if(dist[e.to] == cur_dist + cur_cost) {
				mask[e.to] |= mask[on];
			}
		}
	}
	if(mask[f] == 3) {
		std::cout << "DRAW\n";
		for(int i = 0; i < k; i++) {
			std::cout << (mask[ori[i]] != 2 ? vals[i][0] : vals[i][1]) << (i + 1 == k ? '\n' : ' ');
		}
	} else {
		std::cout << "LOSE\n";
	}
}