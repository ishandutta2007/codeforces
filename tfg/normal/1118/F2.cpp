#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <cassert>

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

template <class Info = int>
class ColorUpdate {
public:
	struct Range {
		Range(int ll = 0) { this->l = ll; }
		Range(int ll, int rr, Info vv) {
			this->l = ll;
			this->r = rr;
			this->v = vv;
		}
		int l, r;
		Info v;

		bool operator < (const Range &b) const { return l < b.l; }
	};

	std::vector<Range> upd(int l, int r, Info v) {
		std::vector<Range> ans;
		if(l >= r) return ans;
		auto it = ranges.lower_bound(l);
		if(it != ranges.begin()) {
			it--;
			if(it->r > l) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, l, cur.v));
				ranges.insert(Range(l, cur.r, cur.v));
			}
		}
		it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->r > r) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, r, cur.v));
				ranges.insert(Range(r, cur.r, cur.v));
			}
		}
		for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
			ans.push_back(*it);
		}
		ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
		ranges.insert(Range(l, r, v));
		return ans;
	}
private:
	std::set<Range> ranges;
};

std::vector<int> a;

const int MOD = 998244353;

std::pair<long long, long long> dp(int on, int par, std::vector<std::vector<int>> &edges) {
	std::pair<long long, long long> ans(1, 0);
	if(a[on]) {
		std::swap(ans.first, ans.second);
	}
	for(auto to : edges[on]) {
		assert(to != par);
		auto t = dp(to, on, edges);
		std::pair<long long, long long> nxt(ans.first * (t.first + t.second) % MOD, 0);
		nxt.second = (t.second + t.first) * ans.second % MOD;
		nxt.second = (nxt.second + t.second * ans.first) % MOD;
		ans = nxt;
	}
	//std::cout << "on " << on << " returning (" << ans.first << ", " << ans.second << ")\n";
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	HLD hld;
	hld.init(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		hld.addEdge(u, v);
	}
	hld.setRoot(0);
	std::vector<int> b(k, -1);
	int root = -1;
	for(int i = 0; i < n; i++) {
		if(a[i]) {
			if(root == -1) {
				root = i;
			}
			root = hld.getLCA(root, i);
			if(b[a[i]-1] == -1) {
				b[a[i]-1] = i;
			}
			b[a[i]-1] = hld.getLCA(b[a[i]-1], i);
		}
	}
	ColorUpdate<int> col;
	col.upd(0, n, 0);
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) continue;
		auto path = hld.getPathtoAncestor(i, b[a[i]-1]);
		for(auto r : path) {
			auto v = col.upd(r.first, r.second, a[i]);
			bool run = true;
			for(auto e : v) {
				if(e.v != 0 && e.v != a[i]) {
					std::cout << "0\n";
					return 0;
				}
				if(e.v == a[i]) {
					run = false;
				}
			}
			if(!run) break;
		}
	}
	{
		auto v = col.upd(0, n, -1);
		for(auto r : v) {
			for(int i = r.l; i < r.r; i++) {
				a[hld.rin[i]] = r.v;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		//std::cout << "(" << i + 1 << ", " << a[i] << ")\n";
	}
	root = 0;
	std::cout << dp(root, root, hld.edges).second << '\n';
}