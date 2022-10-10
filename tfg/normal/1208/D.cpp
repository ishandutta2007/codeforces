#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

#define int long long

// Range update, range query segment tree

const int INF = 1e18;
struct LazyContext {
	LazyContext(int v = 0) {
		val = v;
	}
	
	void reset() {
		val = 0;
	}
	
	void operator += (LazyContext o) {
		val += o.val;
	}
	
	// atributes
	int val;
};

struct Node {
	Node() {
		// neutral element or empty node
		ans = std::pair<int, int>(INF, INF);
	}
	
	Node(int v) {
		// init
		ans = std::pair<int, int>(0, -v);
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = std::min(l.ans, r.ans);
	}
	
	void apply(LazyContext lazy) {
		ans.first += lazy.val;
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
			tree[i + n] = i_t(base[i]);
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


main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(p);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		tree.upd(i, i+1, LazyContext(x));
	}
	p.assign(n, -1);
	for(int i = 0; i < n; i++) {
		auto no = tree.qry(0, n);
		assert(no.ans.first == 0);
		int pos = -no.ans.second;
		p[pos] = i+1;
		tree.upd(pos+1, n, LazyContext(-(i+1)));
		tree.upd(pos, pos+1, LazyContext(INF));
	}
	for(int i = 0; i < n; i++) {
		std::cout << p[i] << (i+1==n?'\n':' ');
	}
}