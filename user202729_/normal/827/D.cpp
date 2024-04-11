// http://codeforces.com/contest/827/problem/D

#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include <cassert>

#include <iostream>
#include <array>
#include <vector>
#include <climits>
#include <algorithm>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
4 4
1 2 2
2 3 2
3 4 2
4 1 3
)");}
#endif // Sublime


struct edge {
	int node, len, id;
	edge() : node(-1), len(-1), id(-1) {}
	edge(int n, int len, int id) : node(n), len(len), id(id) {}
};

std::vector<std::vector<edge>> adjlist;

std::vector<edge> parent;
std::vector<int> height;

struct lca_elem {
	int node, max_len, min_s;
	lca_elem(int n) : node(parent[n].node), max_len(parent[n].len), min_s(INT_MAX) {}

	/// join two paths in build_lca
	void join(lca_elem x) {
		max_len = std::max(max_len, x.max_len);
		node = x.node;
	}

	/// merge min_s
	void merge(lca_elem x) {
		min_s = std::min(min_s, x.min_s);
	}
};
std::array<std::vector<lca_elem>, 19> lca;
/// parent -> lca
void build_lca() {
	lca[0].clear();
	for (size_t node = 0; node < parent.size(); ++node)
		lca[0].emplace_back(node);

	for (size_t h = 1; h < lca.size(); ++h) {
		lca[h].clear();
		for (size_t node = 0; node < parent.size(); ++node) {
			lca[h].push_back(lca[h-1][node]);
			if (lca[h][node].node != -1)
				lca[h][node].join(lca[h-1][lca[h][node].node]);
		}
	}
}

void collapse_lca() {
	for (size_t h = lca.size(); h --> 1;) {
		for (size_t node = 0; node < parent.size(); ++node) {
			lca[h-1][node].merge(lca[h][node]);
			int a = lca[h-1][node].node;
			if (a != -1)
				lca[h-1][a].merge(lca[h][node]);
		}
	}
}

struct DSU {
	std::vector<int> parent;

	void join(int u, int v) {
		parent[root(u)] = parent[root(v)];
	}

	int root(int i) {
		if (i == parent[i]) return i;
		return parent[i] = root(parent[i]); // be careful of stack overflow
		// Path compression
	}

	DSU(int n_vertices) { // initialize DSU with n_vertices and each vertex is in one different set
		parent.resize(n_vertices);
		for (int i = 0; i < n_vertices; i++) {
			parent[i] = i;
		}
	}
};

void root_tree(int node) {
	for (edge e : adjlist[node]) {
		int child = e.node;
		parent[child].node = node;
		parent[child].len = e.len;
		parent[child].id  = e.id;
		adjlist[child].erase(
			std::remove_if(adjlist[child].begin(), adjlist[child].end(),
			[node](edge const & e)->bool {
				return e.node == node;
			}),
			adjlist[child].end()
		);
		height[child] = height[node]+1;
		root_tree(child);
	}
}

struct free_edge {
	int u, v, len, id;
	free_edge(int u, int v, int len, int id) : u(u), v(v), len(len), id(id) {}
	bool operator<(free_edge const & e) const {
		return len < e.len;
	}
};

template <typename Function>
void eval_lca(int u, int v, Function fn) {
	// fn : (lca_elem) -> void
	if (height[u] > height[v])
		std::swap(u, v);

	size_t height_delta = height[v] - height[u];
	for (size_t h = lca.size(); h --> 0;) {
		if (height_delta < (1u << h)) continue;
		height_delta -= 1 << h;
		fn(lca[h][v]);
		v = lca[h][v].node;
	}

	assert(height[u] == height[v]);
	assert(u != -1 && v != -1);
	if (u == v)
		return /* u */ ;

	for (size_t h = lca.size(); h --> 0;) {
		if (lca[h][u].node == lca[h][v].node)
			continue;
		fn(lca[h][u]);
		fn(lca[h][v]);
		u = lca[h][u].node;
		v = lca[h][v].node;
		assert(u != -1 && v != -1);
	}

	fn(lca[0][u]);
	fn(lca[0][v]);

	assert(lca[0][u].node == lca[0][v].node);
	// return lca[0][u].node;
}

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif

	int nNode, nEdge;
	std::cin >> nNode >> nEdge;
	adjlist.resize(nNode);

	std::vector<free_edge> edges, not_in_spanning_tree;
	for (int i = 0; i < nEdge; ++i) {
		int u, v, len;
		std::cin >> u >> v >> len;
		--u; --v;
		edges.emplace_back(u, v, len, i);
	}

	std::sort(edges.begin(), edges.end());
	DSU dsu (nNode);
	for (free_edge e : edges) {
		if (dsu.root(e.u) == dsu.root(e.v)) {
			not_in_spanning_tree.push_back(e);
			continue;
		}
		dsu.join(e.u, e.v);
		adjlist[e.u].emplace_back(e.v, e.len, e.id);
		adjlist[e.v].emplace_back(e.u, e.len, e.id);
	}
	edges.clear();

	parent.assign(nNode, {});
	height.assign(nNode, 0);
	root_tree(0);

	build_lca();
	std::vector<int> ans_1 (nEdge, INT_MAX);
	for (auto e : not_in_spanning_tree) {
		int ans_e = -1;
		eval_lca(e.u, e.v, [&](lca_elem& x)->void {
			ans_e = std::max(ans_e, x.max_len);
			x.min_s = std::min(e.len, x.min_s);
		});
		ans_1[e.id] = ans_e;
	}
	collapse_lca();
	
	for (size_t i = parent.size(); i --> 1;) {
		assert(parent[i].id != -1);
		assert((size_t) parent[i].id < ans_1.size());
		ans_1[parent[i].id] = lca[0][i].min_s;
	}

	for (int x : ans_1) {
		std::cout << (x == INT_MAX ? -1 : x-1) << ' ';
	}
	std::cout << '\n';
}