#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms], id[ms];
int col[ms];
bool mark[ms];

void dfs(int on, int par, int last) {
	if(mark[on]) {
		return;
	}
	//std::cout << "in " << on + 1 << '\n';
	mark[on] = true;
	int pt = 1;
	for(int i = 0; i < (int) edges[on].size(); i++) {
		int to = edges[on][i];
		if(to == par) continue;
		assert(col[id[on][i]] == 0);
		if(pt == last) pt++;
		//std::cout << "id " << id[on][i] << " got " << pt << '\n';
		col[id[on][i]] = pt++;
		dfs(to, on, pt - 1);
	}
	//std::cout << "out " << on + 1 << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> deg;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		id[u].push_back(i);
		id[v].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		deg.push_back(i);
	}
	std::sort(deg.begin(), deg.end(), [&](int a, int b) { return edges[a].size() > edges[b].size(); });
	for(int i = 0; i < k; i++) {
		mark[deg[i]] = true;
		//std::cout << "marking " << deg[i] + 1 << '\n';
	}
	for(int i = 0; i < n; i++) {
		dfs(i, -1, -1);
	}
	int mx = 0;
	for(int i = 1; i < n; i++) {
		if(col[i] == 0) col[i] = 1;
		mx = std::max(mx, col[i]);
	}
	std::cout << mx << '\n';
	for(int i = 1; i < n; i++) {
		std::cout << col[i] << (i + 1 == n ? '\n' : ' ');
	}
}