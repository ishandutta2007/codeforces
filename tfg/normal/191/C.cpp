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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> edges(n-1);
	HLD hld;
	hld.init(n);
	for(int i = 0; i+1 < n; i++) {
		std::cin >> edges[i].first >> edges[i].second;
		edges[i].first--;
		edges[i].second--;
		hld.addEdge(edges[i].first, edges[i].second);
	}
	hld.setRoot(0);
	int q;
	std::cin >> q;
	std::vector<int> sum(n + 1, 0);
	while(q--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		int l = hld.getLCA(u, v);
		for(auto range : hld.getPathtoAncestor(u, l)) {
			sum[range.first]++;
			sum[range.second]--;
		}
		for(auto range : hld.getPathtoAncestor(v, l)) {
			sum[range.first]++;
			sum[range.second]--;
		}
	}
	for(int i = 1; i <= n; i++) {
		sum[i] += sum[i-1];
	}
	bool wtf = false;
	for(auto e : edges) {
		int u = hld.h[e.first] > hld.h[e.second] ? e.first : e.second;
		if(wtf) {
			std::cout << ' ';
		} else {
			wtf = true;
		}
		std::cout << sum[hld.in[u]];
	}
	std::cout << '\n';
}