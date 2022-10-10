#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <set>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

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

struct SegmentTree {
public:
	void init(std::vector<int> b) {
		n = (int) b.size();
		tree.assign(2 * n, 0);
		for(int i = 0; i < n; i++) {
			//std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
			tree[n + i] = b[i];
		}
		for(int i = n-1; i > 0; i--) {
			tree[i] = std::max(tree[i+i], tree[i+i+1]);
		}
	}

	int qry(int l, int r) {
		int ans = 0;
		//std::cout << "qry in [" << l << ", " << r << ")\n";
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) ans = std::max(ans, tree[l++]);
			if(r & 1) ans = std::max(ans, tree[--r]);
		}
		return ans;
	}
private:
	int n;
	std::vector<int> tree;
};


int par[ms];
int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return false;
	par[a] = b;
	return true;
}

struct Edge {
	int u, v, w, id;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<Edge> edges(m);
	for(int i = 0; i < m; i++) {
		auto &e = edges[i];
		std::cin >> e.u >> e.v >> e.w;
		e.u--;
		e.v--;
		e.id = i;
	}
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	std::sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) { return e1.w < e2.w; });
	std::vector<bool> mst(m, false);
	HLD hld;
	hld.init(n);
	for(int i = 0; i < m; i++) {
		mst[i] = makeUnion(edges[i].u, edges[i].v);
		if(mst[i]) {
			hld.addEdge(edges[i].u, edges[i].v);
		}
	}
	hld.setRoot(0);
	std::vector<int> p(n);
	for(int i = 0; i < m; i++) {
		if(mst[i]) {
			if(hld.h[edges[i].u] < hld.h[edges[i].v]) {
				std::swap(edges[i].u, edges[i].v);
			}
			p[hld.in[edges[i].u]] = edges[i].id;
		}
		//std::cout << "for edge " << edges[i].id << " is " << (mst[i] ? "in mst\n" : "not in mst\n");
	}
	std::vector<int> ans(m, 0);
	{
		// solving for not in mst
		std::vector<int> base_edges(n, 1e9);
		for(int i = 0; i < m; i++) {
			if(mst[i]) {
				base_edges[hld.in[edges[i].u]] = edges[i].w;
			}
		}
		SegmentTree tree;
		tree.init(base_edges);
		for(int i = 0; i < m; i++) {
			if(!mst[i]) {
				int lca = hld.getLCA(edges[i].u, edges[i].v);
				auto path = hld.getPathtoAncestor(edges[i].u, lca);
				for(auto chain : path) {
					ans[edges[i].id] = std::max(ans[edges[i].id], tree.qry(chain.first, chain.second));
				}
				path = hld.getPathtoAncestor(edges[i].v, lca);
				for(auto chain : path) {
					ans[edges[i].id] = std::max(ans[edges[i].id], tree.qry(chain.first, chain.second));
				}
			}
		}
	}
	{
		// solving for in mst
		std::set<int> wtf;
		for(int i = 1; i < n; i++) {
			wtf.insert(i);
		}
		for(int i = 0; i < m; i++) {
			if(!mst[i]) {
				int lca = hld.getLCA(edges[i].u, edges[i].v);
				auto path = hld.getPathtoAncestor(edges[i].u, lca);
				for(auto chain : path) {
					auto itl = wtf.lower_bound(chain.first);
					auto itr = wtf.lower_bound(chain.second);
					for(auto it = itl; it != itr; it++) {
						ans[p[*it]] = edges[i].w;
					}
					wtf.erase(itl, itr);
				}
				path = hld.getPathtoAncestor(edges[i].v, lca);
				for(auto chain : path) {
					auto itl = wtf.lower_bound(chain.first);
					auto itr = wtf.lower_bound(chain.second);
					for(auto it = itl; it != itr; it++) {
						ans[p[*it]] = edges[i].w;
					}
					wtf.erase(itl, itr);
				}
			}
		}
		for(auto rest : wtf) {
			ans[p[rest]] = 1e9;
		}
	}
	int task = 2;
	if(task == 1) {
		std::cout << ans[0] << '\n';
	} else if(task == 2) {
		for(int i = 0; i < m; i++) {
			if(mst[i]) {
				ans[edges[i].id] = -1;
			}
		}
		for(auto v : ans) {
			if(v != -1) {
				std::cout << v << '\n';
			}
		}
	} else {
		for(auto v : ans) {
			std::cout << v << '\n';
		}
	}
}