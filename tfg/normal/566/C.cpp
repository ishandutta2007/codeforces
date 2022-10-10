#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

long double ans = 1e30;
int ans2;
int w[ms];
bool visit[ms];
std::vector<std::pair<int, long long> > edges[ms];
long double cur[2];
int size[ms];

void dfs(int on, int par, long long d) {
	long double sq = sqrtl(d);
	cur[0] += d * sq * w[on];
	cur[1] += sq * w[on];
	for(auto e : edges[on]) {
		if(e.first == par) continue;
		dfs(e.first, on, d + e.second);
	}
}

void pre(int on, int par) {
	size[on] = 1;
	for(auto e : edges[on]) {
		if(e.first == par || visit[e.first]) continue;
		pre(e.first, on);
		size[on] += size[e.first];
	}
}

int cen = -1;
int totSize, curSize;

void pre2(int on, int par) {
	int bst = totSize - size[on];
	for(auto e : edges[on]) {
		if(e.first == par || visit[e.first]) continue;
		pre2(e.first, on);
		bst = std::max(bst, size[e.first]);
	}
	if(cen == -1 || curSize > bst) {
		curSize = bst;
		cen = on;
	}
}

void solve() {
	int on = 0;
	while(on != -1 && !visit[on]) {
		pre(on, -1);
		totSize = size[on];
		cen = -1;
		pre2(on, -1);
		on = cen;
		int to = -1;
		cur[0] = cur[1] = 0;
		long double bst = 0;
		for(auto e : edges[on]) {
			cur[1] = 0;
			dfs(e.first, on, e.second);
			if(bst < cur[1]) {
				bst = cur[1];
				to = e.first;
			}
		}
		if(cur[0] < ans) {
			ans = cur[0];
			ans2 = on + 1;
		}
		visit[on] = true;
		on = to;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v, l;
		std::cin >> u >> v >> l;
		u--;v--;
		edges[u].emplace_back(v, l);
		edges[v].emplace_back(u, l);
	}
	solve();
	std::cout << std::fixed << std::setprecision(10) << ans2 << ' ' << ans << '\n';
}