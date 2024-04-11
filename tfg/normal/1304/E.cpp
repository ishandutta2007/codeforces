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
		ans.emplace_back(in[anc], in[u] + 1);
		return ans;
	}

	int dist(int u, int v) {
		return h[u] + h[v] - 2 * h[getLCA(u, v)];
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
	int n;
	std::cin >> n;
	HLD hld;
	hld.init(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		hld.addEdge(u, v);
	}
	hld.setRoot(0);
	int q;
	std::cin >> q;
	while(q--) {
		int x, y, u, v, k;
		std::cin >> x >> y >> u >> v >> k;
		x--;y--;u--;v--;
		bool good = false;
		{
			int dist = hld.dist(u, v);
			if(dist % 2 == k % 2 && dist <= k) {
				good = true;
			}
		}
		{
			// passing through x to y
			int dist = hld.dist(u, x) + 1 + hld.dist(y, v);
			if(dist % 2 == k % 2 && dist <= k) {
				good = true;
			}
		}
		{
			// passing through y to x
			int dist = hld.dist(u, y) + 1 + hld.dist(x, v);
			if(dist % 2 == k % 2 && dist <= k) {
				good = true;
			}
		}
		if(good) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}