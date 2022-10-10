#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e8;

struct LazyContext {
	LazyContext(int v = 0) {
		ans = v;
	}
	
	void reset() {
		ans = 0;
	}
	
	void operator += (LazyContext o) {
		ans += o.ans;
	}
	
	// atributes
	int ans;
};

struct Node {
	Node(int value = INF, int id = INF) {
		// init
		ans = std::pair<int, int>(value, id);
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = std::min(l.ans, r.ans);
	}
	
	void apply(LazyContext lazy) {
		ans.first += lazy.ans;
	}
	
	// atributes
	std::pair<int, int> ans;
};

template <class i_t, class e_t, class lazy_cont = int>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		h = 0;
		while((1 << h) < n) h++;
		tree.resize(2 * n);
		dirty.assign(n, false);
		lazy.resize(n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i], i);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			lazy[i].reset();
		}
	}
	
	i_t qry(int l, int r) {
		if(l >= r) return i_t();
		l += n, r += n;
		push(l);
		push(r - 1);
		i_t lp, rp;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int l, int r, lazy_cont lc) {
		if(l >= r) return;
		l += n, r += n;
		push(l);
		push(r - 1);
		int l0 = l, r0 = r;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, lc);
			if(r & 1) apply(--r, lc);
		}
		build(l0);
		build(r0 - 1);
	}
	
private:
	int n, h;
	std::vector<bool> dirty;
	std::vector<i_t> tree;
	std::vector<lazy_cont> lazy;
	
	void apply(int p, lazy_cont &lc) {
		tree[p].apply(lc);
		if(p < n) {
			dirty[p] = true;
			lazy[p] += lc;
		}
	}
	
	void push(int p) {
		for(int s = h; s > 0; s--) {
			int i = p >> s;
			if(dirty[i]) {
				apply(i + i, lazy[i]);
				apply(i + i + 1, lazy[i]);
				lazy[i].reset();
				dirty[i] = false;
			}
		}
	}
	
	void build(int p) {
		for(p /= 2; p > 0; p /= 2) {
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
			if(dirty[p]) {
				tree[p].apply(lazy[p]);
			}
		}
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> nxt(n);
	std::vector< std::vector< std::pair<int, int> > > edges(n);
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(std::vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		std::cin >> nxt[i];
		if(nxt[i] == -1) {

		} else {
			nxt[i]--;
			edges[i].emplace_back(i + 1, nxt[i]);
			if(nxt[i] < n) {
				edges[nxt[i]].emplace_back(i, i + 1);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(auto e : edges[i]) {
			tree.upd(e.first, e.second, LazyContext(1));
		}
	}
	int pt = n;
	std::vector<int> p(n, -1);
	while(pt != 0) {
		auto node = tree.qry(0, n);
		if(node.ans.first) {
			std::cout << "-1\n";
			return;
		}
		int id = node.ans.second;
		p[id] = pt--;
		tree.upd(id, id + 1, LazyContext(INF));
		for(auto e : edges[id]) {
			tree.upd(e.first, e.second, LazyContext(-1));
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << p[i] << (i + 1 == n ? '\n' : ' ');
	}
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}