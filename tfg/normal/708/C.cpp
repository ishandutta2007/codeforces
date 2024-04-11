#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class Cost>
class CentroidDecomposition {
public:
	struct Edge {
		Edge(){}
		Edge(int v, Cost cost) : to(v), c(cost) {}
		int to;
		Cost c;
	};
	CentroidDecomposition(int _n) : n(_n), edges(_n), tree(_n), col(_n, -1), size(_n), pt(_n, 0) {}

	void addEdge(int u, int v, Cost c) {
		edges[u].emplace_back(v, c);
		edges[v].emplace_back(u, c);
		pt[u]++, pt[v]++;
	}

	int init() {
		int ans = init(0, 0);
		for(int i = 0; i < n; i++) {
			std::sort(edges[i].begin(), edges[i].end(), [&](Edge e1, Edge e2) { return col[e1.to] > col[e2.to]; });
		}
		return ans;
	}

	int getCentroid() {
		preDFS(0, -1);
		return getCen(0);
	}

	template<class Solver, class Info>
	long long solveEdges(Solver sol, Info base) {
		long long ans = 0;
		std::vector<Info> a, b;
		for(int i = 0; i < n; i++) {
			b.clear();
			b.push_back(base);
			for(int j = 0; j < pt[i]; j++) {
				a.clear();
				dfs(a, edges[i][j].to, i, col[i], Info(base, edges[i][j].c));
				ans -= sol(a);
				for(auto v : a) b.push_back(v);
			}
			ans += sol(b);
		}
		return ans;
	}

	template<class Info>
	void dfs(std::vector<Info> &vec, int on, int par, int lim, Info h) {
		vec.push_back(h);
		for(auto e : edges[on]) {
			if(e.to == par) continue;
			if(col[e.to] <= lim) break;
			dfs(vec, e.to, on, lim, Info(h, e.c));
		}
	}

private:
	void preDFS(int on, int par) {
		size[on] = 1;
		for(int i = 0; i < pt[on]; i++) {
			int to = edges[on][i].to;
			if(col[to] != -1 || to == par) {
				std::swap(edges[on][i], edges[on][pt[on]-1]);
				if(col[to] != -1) {
					pt[on]--;
					i--;
				} else if(i+1 < pt[on]) {
					i--;
				}
				continue;
			}
			preDFS(to, on);
			size[on] += size[to];
			if(size[to] > size[edges[on][0].to]) {
				std::swap(edges[on][0], edges[on][i]);
			}
		}
	}

	int getCen(int on) {
		int sz = size[on];
		while(size[on] > 1 && 2 * size[edges[on][0].to] >= sz) on = edges[on][0].to;
		return on;
	}

	int init(int on, int c) {
		preDFS(on, -1);
		on = getCen(on);
		col[on] = c;
		for(auto e : edges[on]) {
			if(col[e.to] == -1) {
				tree[on].push_back(init(e.to, c+1));
			}
		}
		return on;
	}

	int n;
	std::vector<std::vector<Edge>> edges;
	std::vector<std::vector<int>> tree; // centroid tree edges
	std::vector<int> col, size, pt;
};


const int ms = 400400;
int n;
std::vector<int> edges[ms];
int size[ms];
int ans[ms];
void pre(int on, int par) {
	size[on] = 1;
	for(auto to : edges[on]) {
		if(to == par) continue;
		pre(to, on);
		size[on] += size[to];
	}
}
void dfs(int on, int par, int bst) {
	ans[on] = (n - size[on] - bst) * 2 <= n ? 1 : 0;
	for(auto to : edges[on]) {
		if(to == par) continue;
		dfs(to, on, bst);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	CentroidDecomposition<int> tree(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		tree.addEdge(u, v, -1);
	}
	int r = tree.getCentroid();
	pre(r, r);
	std::vector<std::pair<int, int>> wtf;
	wtf.emplace_back(0, -1);
	for(auto to : edges[r]) {
		wtf.emplace_back(size[to], to);
	}
	std::sort(wtf.rbegin(), wtf.rend());
	if(wtf[0].first * 2 == n) {
		for(int i = 0; i < n; i++) {
			std::cout << 1 << (i + 1 == n ? '\n' : ' ');
		}
		return 0;
	}
	ans[r] = 1;
	for(auto to : edges[r]) {
		dfs(to, r, wtf[wtf[0].second == to ? 1 : 0].first);
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}