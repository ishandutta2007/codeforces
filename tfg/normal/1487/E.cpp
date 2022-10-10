#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Point update, range Query segment tree

const int INF = 1e9 + 10;
struct Node {
	Node(int v = INF) {
		// init
		ans = v;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = std::min(l.ans, r.ans);
	}

	// atributes
	int ans;
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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n[4];
	for(int i = 0; i < 4; i++) {
		std::cin >> n[i];
	}
	std::vector<int> cost[4];
	for(int i = 0; i < 4; i++) {
		cost[i].resize(n[i]);
		for(int j = 0; j < n[i]; j++) {
			std::cin >> cost[i][j];
		}
	}
	for(int i = 1; i < 4; i++) {
		SegmentTree<Node, int> tree;
		tree.init(cost[i-1]);
		int edges;
		std::cin >> edges;
		std::vector<std::vector<int>> wtf(n[i]);
		while(edges--) {
			int x, y;
			std::cin >> x >> y;
			x--, y--;
			wtf[y].push_back(x);
		}
		for(int j = 0; j < n[i]; j++) {
			wtf[j].push_back(-1), wtf[j].push_back(n[i-1]);
			std::sort(wtf[j].begin(), wtf[j].end());
			int ans = INF;
			for(int k = 1; k < (int) wtf[j].size(); k++) {
				ans = std::min(ans, tree.qry(wtf[j][k-1]+1, wtf[j][k]).ans + cost[i][j]);
			}
			cost[i][j] = ans;
		}
	}
	int ans = INF;
	for(auto v : cost[3]) ans = std::min(ans, v);
	if(ans == INF) ans = -1;
	std::cout << ans << '\n';
}