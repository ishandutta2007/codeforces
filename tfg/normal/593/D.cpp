#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 2e18;

struct Node {
	Node(long long d = 1) {
		// init
		ans = d;
	}
	
	Node(Node l, Node r) {
		// merge
		if(INF / l.ans / r.ans == 0) {
			ans = INF + 1;
		} else {
			ans = l.ans * r.ans;
		}
	}

	// atributes
	long long ans;
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
	
	void upd(int pos, e_t v) {
		pos += n;
		tree[pos] = i_t(v);
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};

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

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> u(n-1), v(n-1);
	std::vector<long long> ini(n-1);
	HLD hld;
	hld.init(n);
	for(int i = 0; i + 1 < n; i++) {
		std::cin >> u[i] >> v[i] >> ini[i];
		u[i]--;
		v[i]--;
		hld.addEdge(u[i], v[i]);
	}
	hld.setRoot(0);
	SegmentTree<Node, long long> tree;
	tree.init(std::vector<long long>(n, 1));
	for(int i = 0; i + 1 < n; i++) {
		if(hld.h[u[i]] < hld.h[v[i]]) {
			std::swap(u[i], v[i]);
		}
		//std::cout << "updating " << u[i] + 1 << " with " << ini[i] << std::endl;
		tree.upd(hld.in[u[i]], ini[i]);
	}
	while(m--) {
		int t;
		std::cin >> t;
		//std::cout << "got query type " << t << std::endl;
		if(t == 1) {
			int a, b;
			long long y;
			std::cin >> a >> b >> y;
			a--;b--;
			int l = hld.getLCA(a, b);
			auto path = hld.getPathtoAncestor(a, l);
			for(auto e : path) {
				//std::cout << "got query on [" << e.first]
				y /= tree.qry(e.first, e.second).ans;
			}
			path = hld.getPathtoAncestor(b, l);
			for(auto e : path) {
				y /= tree.qry(e.first, e.second).ans;
			}
			std::cout << y << '\n';
		} else {
			int p;
			long long c;
			std::cin >> p >> c;
			tree.upd(hld.in[u[p-1]], c);
		}
	}
}