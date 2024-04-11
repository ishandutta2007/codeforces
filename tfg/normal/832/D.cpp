#include <iostream>
#include <vector>
#include <chrono>
#include <random>
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
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
private:
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

std::vector<std::pair<int, int>> unite(const std::vector<std::pair<int, int>> &A, const std::vector<std::pair<int, int>> &B) {
	//for(auto p : b) a.push_back(p);
	//std::sort(a.begin(), a.end());
	std::vector<std::pair<int, int>> a(A.size() + B.size());
	std::merge(A.begin(), A.end(), B.begin(), B.end(), a.begin());
	std::vector<std::pair<int, int>> ans;
	std::pair<int, int> cur = a[0];
	for(auto p : a) {
		if(cur.second < p.first) {
			ans.push_back(cur);
			cur = p;
		} else {
			cur.second = std::max(cur.second, p.second);
		}
	}
	ans.push_back(cur);
	return ans;
}

int size(const std::vector<std::pair<int, int>> &a) {
	int ans = 0;
	for(auto p : a) {
		ans += p.second - p.first;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	HLD hld;
	hld.init(n);
	for(int i = 1; i < n; i++) {
		int u;
		std::cin >> u;
		u--;
		hld.addEdge(i, u);
	}
	hld.setRoot(0);
	auto solve = [&](int a, int b, int c) {
		int l1 = hld.getLCA(a, b);
		std::vector<std::pair<int, int>> path1 = unite(hld.getPathtoAncestor(a, l1), hld.getPathtoAncestor(b, l1));
		int l2 = hld.getLCA(a, c);
		std::vector<std::pair<int, int>> path2 = unite(hld.getPathtoAncestor(a, l2), hld.getPathtoAncestor(c, l2));
		//std::cout << "(" << size(path1) << ", " << size(path2) << ", " << size(unite(path1, path2)) << ")\n";
		return size(path1) + size(path2) - size(unite(path1, path2));
	};
	while(q--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;c--;
		std::cout << std::max({solve(a, b, c), solve(b, a, c), solve(a, c, b), solve(c, a, b), solve(b, c, a), solve(c, b, a)}) << '\n';
	}
}