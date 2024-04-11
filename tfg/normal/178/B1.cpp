#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms = 2020;

std::vector<ii> edges[ms];
int step[ms];
int cur_step;
int par[ms];

int getPar(int x) {
	if(step[x] != cur_step) {
		step[x] = cur_step;
		par[x] = x;
	}
	if(par[x] == x) {
		return x;
	} else {
		return par[x] = getPar(par[x]);
	}
}

void makeUnion(int a, int b) {
	par[getPar(a)] = getPar(b);
}

int dfs(int on, int target, int par = -1) {
	if(on == target) {
		return 0;
	}
	for(auto e : edges[on]) {
		if(e.first == par) {
			continue;
		}
		int cost = dfs(e.first, target, on);
		if(cost != -1) {
			return cost + e.second;
		}
	}
	return -1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> u(m);
	std::vector<int> v(m);
	std::vector<int> c(m, 0);
	for(int i = 0; i < m; i++) {
		std::cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
	}
	for(int i = 0; i < m; i++) {
		cur_step++;
		for(int j = 0; j < m; j++) {
			if(j != i) {
				makeUnion(u[j], v[j]);
			}
		}
		bool same = true;
		for(int j = 0; j < n; j++) {
			same = same && getPar(j) == getPar(0);
		}
		if(same) {
			c[i] = 0;
		} else {
			c[i] = 1;
		}
	}
	cur_step++;
	for(int i = 0; i < m; i++) {
		if(getPar(u[i]) != getPar(v[i])) {
			makeUnion(u[i], v[i]);
			edges[u[i]].emplace_back(v[i], c[i]);
			edges[v[i]].emplace_back(u[i], c[i]);
		}
	}
	int k;
	std::cin >> k;
	while(k--) {
		int a, b;
		std::cin >> a >> b;
		std::cout << dfs(a - 1, b - 1) << std::endl;
	}
}