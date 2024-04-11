#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const bool REPEAT = false>
struct SimpleEulerTourTree {
	void init(const std::vector<std::vector<int>> &edges, int root = 0) {
		a.clear();
		in = out = std::vector<int>(edges.size(), 0);
		dfs(root, root, edges, 0);
	}

	void dfs(int on, int par, const std::vector<std::vector<int>> &edges, int h) {
		in[on] = (int) a.size();
		a.emplace_back(h, on);
		for(auto to : edges[on]) {
			if(to == par) continue;
			dfs(to, on, edges, h+1);
			if(REPEAT) a.emplace_back(h, on);
		}
		out[on] = (int) a.size();
	}

	std::vector<int> in, out;
	std::vector<std::pair<int, int>> a;
};

class SegmentTree {
public:
	void init(int _n) {
		n = _n;
		tree.resize(2 * n, 0);
		tree2.resize(2 * n, 0);
	}
	
	int qry(int l, int r) {
		int ans = 0;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) ans = std::max(ans, tree[l++]);
			if(r & 1) ans = std::max(tree[--r], ans);
		}
		return ans;
	}
	
	void upd(int pos, int v) {
		pos += n;
		tree[pos] = v;
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = std::max(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
	int qry(int x) {
		int ans = 0;
		for(x += n; x > 0; x /= 2) {
			ans = std::max(ans, tree2[x]);
		}
		return ans;
	}

	void upd(int l, int r, int v) {
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) tree2[l++] = v;
			if(r & 1) tree2[--r] = v;
		}
	}
private:
	int n;
	std::vector<int> tree, tree2;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> edges(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	SimpleEulerTourTree tree;
	tree.init(edges);
	SegmentTree st;
	st.init(n);
	int q;
	std::cin >> q;
	for(int query = 1; query <= q; query++) {
		int t, u;
		std::cin >> t >> u;
		u--;
		if(t == 1) {
			// flood
			st.upd(tree.in[u], tree.out[u], query);
		} else if(t == 2) {
			// empty
			st.upd(tree.in[u], query);
		} else {
			//std::cout << "(" << st.qry(tree.in[u]) << ", " << st.qry(tree.in[u], tree.out[u]) << "), [" << tree.in[u] << ", " << tree.out[u] << ")\n";
			std::cout << (st.qry(tree.in[u]) > st.qry(tree.in[u], tree.out[u]) ? "1\n" : "0\n");
		}
	}
}