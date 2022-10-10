#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
int n;
std::vector<int> edges[ms];
int size[ms];
long long tot = 0;
void pre(int on, int par) {
	size[on] = 1;
	for(auto to : edges[on]) {
		if(to == par) continue;
		pre(to, on);
		size[on] += size[to];
		tot += std::min(n - size[to], size[to]) * 2;
	}
}
int cen(int on, int par) {
	for(auto to : edges[on]) {
		if(to == par) continue;
		if(2 * size[to] > n) return cen(to, on);
	}
	return on;
}

void go(int on, int par, std::vector<int> &v) {
	v.push_back(on);
	for(auto to : edges[on]) {
		if(to == par) continue;
		go(to, on, v);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	pre(0, -1);
	int r = cen(0, -1);
	std::vector<std::vector<int>> a;
	for(auto to : edges[r]) {
		std::vector<int> cur;
		go(to, r, cur);
		a.push_back(cur);
	}
	std::sort(a.begin(), a.end(), [](const std::vector<int> &v1, const std::vector<int> &v2){ return v1.size() > v2.size(); });
	a.emplace_back(1, r);
	int on = 0;
	std::vector<int> rev(n, -1);
	for(auto v : a) {
		for(auto kek : v) {
			rev[on] = kek;
			on += 2;
			if(on >= n) on = 1;
		}
	}
	std::vector<int> ans(n, -1);
	for(int i = 0; i < n; i++) {
		ans[rev[i]] = rev[(i+1)%n];
	}
	std::cout << tot << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}