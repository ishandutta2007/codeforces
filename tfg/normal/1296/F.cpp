#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

class HLD {
public:
	void init(int n) {
		// this doesn't delete edges!
		sz.resize(n);
		in.resize(n);
		out.resize(n);
		rin.resize(n);
		p.resize(n);
		edges.resize(n);
		nxt.resize(n);
		h.resize(n);
	}

	void addEdge(int u, int v) {
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	void setRoot(int n) {
		t = 0;
		p[n] = n;
		h[n] = 0;
		prep(n, n);
		nxt[n] = n;
		hld(n);
	}

	int getLCA(int u, int v) {
		while(!inSubtree(nxt[u], v)) {
			u = p[nxt[u]];
		}
		while(!inSubtree(nxt[v], u)) {
			v = p[nxt[v]];
		}
		return in[u] < in[v] ? u : v;
	}

	bool inSubtree(int u, int v) {
		// is v in the subtree of u?
		return in[u] <= in[v] && in[v] < out[u];
	}

	std::vector<std::pair<int, int>> getPathtoAncestor(int u, int anc) {
		// returns ranges [l, r) that the path has
		std::vector<std::pair<int, int>> ans;
		//assert(inSubtree(anc, u));
		while(nxt[u] != nxt[anc]) {
			ans.emplace_back(in[nxt[u]], in[u] + 1);
			u = p[nxt[u]];
		}
		// this includes the ancestor!
		ans.emplace_back(in[anc] + 1, in[u] + 1);
		return ans;
	}
//private:
	std::vector<int> in, out, p, rin, sz, nxt, h;
	std::vector<std::vector<int>> edges;
	int t;

	void prep(int on, int par) {
		sz[on] = 1;
		p[on] = par;
		for(int i = 0; i < (int) edges[on].size(); i++) {
			int &u = edges[on][i];
			if(u == par) {
				std::swap(u, edges[on].back());
				edges[on].pop_back();
				i--;
			} else {
				h[u] = 1 + h[on];
				prep(u, on);
				sz[on] += sz[u];
				if(sz[u] > sz[edges[on][0]]) {
					std::swap(edges[on][0], u);
				}
			}
		}
	}

	void hld(int on) {
		in[on] = t++;
		rin[in[on]] = on;
		for(auto u : edges[on]) {
			nxt[u] = (u == edges[on][0] ? nxt[on] : u);
			hld(u);
		}
		out[on] = t;
	}
};

struct Query {
	int u, v, c;
};

struct SegTree {
	void init(int _n) {
		n = _n;
		tree.assign(2 * n, 1);
	}

	void upd(int l, int r, int v) {
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) {
				tree[l] = std::max(tree[l], v);
				l++;
			}
			if(r & 1) {
				--r;
				tree[r] = std::max(tree[r], v);
			}
		}
	}

	void propagate() {
		for(int i = 1; i < n; i++) {
			tree[i+i] = std::max(tree[i+i], tree[i]);
			tree[i+i+1] = std::max(tree[i+i+1], tree[i]);
		}
		for(int i = n-1; i > 0; i--) {
			tree[i] = std::min(tree[i+i], tree[i+i+1]);
		}
	}

	int qry(int l, int r) {
		int ans = 1e9;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) ans = std::min(ans, tree[l++]);
			if(r & 1) ans = std::min(ans, tree[--r]);
		}
		return ans;
	}

	int n;
	std::vector<int> tree;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	HLD hld;
	hld.init(n);
	std::vector<std::pair<int, int>> edges;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		hld.addEdge(u, v);
		edges.emplace_back(u, v);
	}
	int q;
	std::cin >> q;
	std::vector<Query> qries(q);
	for(auto &qry : qries) {
		std::cin >> qry.u >> qry.v >> qry.c;
		qry.u--; qry.v--;
	}
	SegTree tree;
	tree.init(n);
	hld.setRoot(0);
	for(auto &qry : qries) {
		int u = qry.u, v = qry.v;
		int l = hld.getLCA(u, v);
		for(auto range : hld.getPathtoAncestor(u, l)) {
			tree.upd(range.first, range.second, qry.c);
		}
		for(auto range : hld.getPathtoAncestor(v, l)) {
			tree.upd(range.first, range.second, qry.c);
		}
	}
	tree.propagate();
	for(auto &qry : qries) {
		int u = qry.u, v = qry.v;
		int l = hld.getLCA(u, v);
		int ans = 1e9;
		for(auto range : hld.getPathtoAncestor(u, l)) {
			ans = std::min(ans, tree.qry(range.first, range.second));
		}
		for(auto range : hld.getPathtoAncestor(v, l)) {
			ans = std::min(ans, tree.qry(range.first, range.second));
		}
		if(ans != qry.c) {
			std::cout << "-1\n";
			return 0;
		}
	}
	for(auto e : edges) {
		int u = e.first, v = e.second;
		if(hld.h[u] < hld.h[v]) {
			std::swap(u, v);
		}
		std::cout << tree.tree[hld.in[u] + n] << ' ';
	}
	std::cout << std::endl;
}