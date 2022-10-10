#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

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
		ans.emplace_back(in[anc], in[u] + 1);
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

HLD tree;

struct Node {
	Node(int v = -1) {
		// init
		for(int i = 0; i < 4; i++) {
			if(v == -1 || i > 0) {
				mx[i] = -1;
				mn[i] = 1001000;
			} else {
				mx[i] = mn[i] = v;
			}
		}
		std::sort(mn, mn + 4);
		std::sort(mx, mx + 4, std::greater<int>());
	}
	
	Node(Node l, Node r) {
		// merge
		for(int i = 0; i < 2; i++) {
			mx[i] = l.mx[i];
			mx[i+2] = r.mx[i];
			mn[i] = l.mn[i];
			mn[i+2] = r.mn[i];
		}
		std::sort(mn, mn + 4);
		std::sort(mx, mx + 4, std::greater<int>());
	}

	// atributes
	int mx[4], mn[4];
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
		}
	}
	
	i_t qry(int l, int r) {
		i_t lp, rp;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
private:
	int n;
	std::vector<i_t> tree;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	tree.init(n);
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		p--;
		tree.addEdge(p, i);
	}
	tree.setRoot(0);
	std::vector<int> base(n);
	for(int i = 0; i < n; i++) {
		base[i] = tree.in[i];
	}
	SegmentTree<Node, int> seg;
	seg.init(base);
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		l--;
		auto node = seg.qry(l, r);
		int f = tree.h[tree.getLCA(tree.rin[node.mn[1]], tree.rin[node.mx[0]])];
		int s = tree.h[tree.getLCA(tree.rin[node.mn[0]], tree.rin[node.mx[1]])];
		if(f > s) {
			std::cout << tree.rin[node.mn[0]] + 1 << ' ' << f << '\n';
		} else {
			std::cout << tree.rin[node.mx[0]] + 1 << ' ' << s << '\n';
		}
	}
}