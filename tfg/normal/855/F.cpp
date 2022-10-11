#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

struct LazyContext {
	LazyContext(int val = 1e9 + 1) {
		this->val = val;
	}
	
	void reset() {
		val = 1e9 + 1;
	}
	
	void operator += (LazyContext o) {
		val = std::min(val, o.val);
	}
	
	// atributes
	int val;
};

struct Node {
	Node() {second = first = -1;sum = freq = 0;}
	Node(int val) {
		// init
		second = -1;
		first = val;
		sum = val;
		freq = 1;
	}
	
	Node(Node l, Node r) {
		// merge
		first = l.first;
		second = l.second;
		freq = l.freq;
		if(r.first > first) {
			second = first;
			first = r.first;
			freq = 0;
		}
		if(r.first == first) {
			freq += r.freq;
		} else if(r.first > second) {
			second = r.first;
		}
		if(r.second > second) {
			second = r.second;
		}
		sum = l.sum + r.sum;
	}

	bool canBreak(LazyContext lazy) {
		// return true if can break without applying lazy
		return first < lazy.val;
	}

	bool canApply(LazyContext lazy) {
		// returns true if can apply lazy
		return second < lazy.val;
	}
	
	void apply(LazyContext &lazy) {
		if(lazy.val < first) {
			sum -= (long long) first * freq;
			first = std::min(lazy.val, first);
			sum += (long long) first * freq;
		}
	}
	
	// atributes
	long long sum;
	int freq;
	int first, second;
};

struct Node2 {
	Node2(int val = 0) {
		// init
		this->val = val;
	}
	
	Node2(Node2 l, Node2 r) {
		// merge
		val = std::max(l.val, r.val);
	}

	bool canBreak(LazyContext lazy) {
		// return true if can break without applying lazy
		return false;
	}

	bool canApply(LazyContext lazy) {
		// returns true if can apply lazy
		return true;
	}
	
	void apply(LazyContext &lazy) {
		val = std::min(val, lazy.val);
	}
	
	// atributes
	int val;
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
	
	i_t qry(int l, int r) { return qry(1, 0, n - 1, l, r); }
	void upd(int l, int r, lazy_cont lc) { upd(1, 0, n - 1, l, r, lc); }
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
			build(p + p, mid + 1, r, base);
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

const int ms = 100100;

int main() {
	std::set<int> needs[2];
	for(int i = 0; i < ms; i++) {
		needs[0].insert(i);
	}
	needs[1] = needs[0];
	SegmentTree<Node, int, LazyContext> problem[2];
	SegmentTree<Node2, int, LazyContext> trans[2];
	trans[0].init(std::vector<int>(ms, 0));
	trans[1].init(std::vector<int>(ms, 0));
	problem[0].init(std::vector<int>(ms, 0));
	problem[1].init(std::vector<int>(ms, 0));
	int q;
	std::cin >> q;
	while(q--) {
		int t, l, r;
		//std::cin >> t >> l >> r;
		scanf("%i %i %i", &t, &l, &r);
		l--;r-=2;
		//std::cout << "qry (" << t << ", " << l << ", " << r << ")\n";
		//for(int i = 0; i < 2; i++)
		//	problem[i].print(0, 20), trans[i].print(0, 20);
		if(t == 1) {
			//update
			int k;
			scanf("%i", &k);
			//std::cin >> k;
			int on;
			if(k < 0) {
				on = 0;
				k = -k;
			} else {
				on = 1;
			}
			std::set<int>::iterator it1 = needs[on].lower_bound(l);
			std::set<int>::iterator it2 = needs[on].upper_bound(r);
			for(std::set<int>::iterator it = it1; it != it2; it++) {
				//std::cout << "on (" << on << ", " << *it << ")\n";
				if(needs[1 - on].count(*it) == 0) {
					problem[on].upd(*it, k);
					problem[1 - on].upd(*it, trans[1 - on].qry(*it, *it).val);
				} else {
					//std::cout << "inserting\n";
					trans[on].upd(*it, k);
				}
			}
			needs[on].erase(it1, it2);
			trans[on].upd(l, r, LazyContext(k));
			problem[on].upd(l, r, LazyContext(k));
		}
		else {
			printf("%lld\n", problem[0].qry(l, r).sum + problem[1].qry(l, r).sum);
		}
	}
}