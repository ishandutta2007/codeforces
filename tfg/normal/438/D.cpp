#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

struct LazyContext {
	LazyContext(bool flag = false, int val = 1e9 + 1) {
		this->set = flag;
		this->val = val;
	}
	
	void reset() {
		set = false;
		val = 1e9 + 1;
	}
	
	void operator += (LazyContext o) {
		if(set && !o.set) {
			val %= o.val;
		} else {
			*this = o;
		}
	}
	
	// atributes
	bool set;
	int val;
};

struct Node {
	Node() {
		// empty constructor
		max = -1;
		min = 2e9;
		size = 0;
		sum = 0;
	}
	
	Node(int val) {
		// init
		max = val;
		min = val;
		size = 1;
		sum = val;
	}
	
	Node(Node l, Node r) {
		// merge
		sum = l.sum + r.sum;
		max = std::max(l.max, r.max);
		min = std::min(l.min, r.min);
		size = l.size + r.size;
	}

	bool canBreak(LazyContext lazy) {
		// return true if can break without applying lazy
		return !lazy.set && lazy.val > max;
	}

	bool canApply(LazyContext lazy) {
		// returns true if can apply lazy
		return lazy.set || max == min;
	}
	
	void apply(LazyContext &lazy) {
		if(lazy.set) {
			min = max = lazy.val;
		} else {
			if(lazy.val > max) return;
			assert(min == max);
			min = max = min % lazy.val;
		}
		sum = (long long) size * max;
		lazy = LazyContext(true, max);
	}
	
	// atributes
	long long sum;
	int max, min, size;
};

template <class i_t, class e_t, class lazy_cont>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(4 * n);
		dirty.assign(2 * n, false);
		lazy.resize(2 * n);
		build(1, 0, n - 1, base);
	}
	
	i_t qry(int l, int r) { return qry(1, 0, n - 1, l, r - 1); }
	void upd(int l, int r, lazy_cont lc) { upd(1, 0, n - 1, l, r - 1, lc); }
	void upd(int pos, e_t v) { upd(1, 0, n - 1, pos, v); }
private:
	int n;
	std::vector<bool> dirty;
	std::vector<i_t> tree;
	std::vector<lazy_cont> lazy;

	void build(int p, int l, int r, std::vector<e_t> &base) {
		if(l == r) {
			tree[p] = i_t(base[l]);
		} else {
			int mid = (l + r) / 2;
			build(p + p, l, mid, base);
			build(p + p + 1, mid + 1, r, base);
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
		}
	}

	void apply(int p, int l, int r, lazy_cont &lc) {
		tree[p].apply(lc);
		if(l != r) {
			dirty[p] = true;
			lazy[p] += lc;
		}
	}

	void push(int p, int l, int r) {
		if(dirty[p]) {
			int mid = (l + r) / 2;
			upd(p + p, l, mid, l, mid, lazy[p]);
			upd(p + p + 1, mid + 1, r, mid + 1, r, lazy[p]);
			lazy[p].reset();
			dirty[p] = false;
		}
	}

	void upd(int p, int l, int r, int pos, e_t &v) {
		if(l == r) {
			tree[p] = i_t(v);
		} else {
			push(p, l, r);
			int mid = (l + r) / 2;
			if(pos <= mid) {
				upd(p + p, l, mid, pos, v);
			} else {
				upd(p + p + 1, mid + 1, r, pos, v);
			}
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
		}
	}

	void upd(int p, int l, int r, int i, int j, lazy_cont lc) {
		if(i > r || j < l || tree[p].canBreak(lc)) {
			return;
		} else if(i <= l && r <= j && tree[p].canApply(lc)) {
			apply(p, l, r, lc);
		} else {
			push(p, l, r);
			int mid = (l + r) / 2;
			upd(p + p, l, mid, i, j, lc);
			upd(p + p + 1, mid + 1, r, i, j, lc);
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
		}
	}

	i_t qry(int p, int l, int r, int i, int j) {
		if(i > r || j < l) {
			return i_t();
		} else if(i <= l && r <= j) {
			return tree[p];
		} else {
			push(p, l, r);
			int mid = (l + r) / 2;
			return i_t(qry(p + p, l, mid, i, j), qry(p + p + 1, mid + 1, r, i, j));
		}
	}
};

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(a);
	for(int i = 1; i <= m; i++) {
		//std::cout << "on qry " << i << std::endl;
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", tree.qry(l - 1, r).sum);
		} else if(t == 2) {
			int l, r, mod;
			scanf("%d %d %d", &l, &r, &mod);
			tree.upd(l - 1, r, LazyContext(false, mod));
		} else {
			int pos, val;
			scanf("%d %d", &pos, &val);
			//tree.upd(pos - 1, val);
			tree.upd(pos - 1, pos, LazyContext(true, val));
		}
	}
}