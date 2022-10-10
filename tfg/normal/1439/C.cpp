#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Range update, range query segment tree

struct LazyContext {
	LazyContext(long long v = 0) {
		val = v;
	}
	
	void reset() {
		val = 0;
	}
	
	void operator += (LazyContext o) {
		val = o.val;
	}
	
	// atributes
	long long val;
};

struct Node {
	Node() {
		// neutral element or empty node
		size = 0;
		ans = 0;
		mn = 2e9;
	}
	
	Node(long long v) {
		// init
		size = 1;
		ans = v;
		mn = (int) v;
	}
	
	Node(const Node &l, const Node &r) {
		// merge
		ans = l.ans + r.ans;
		size = l.size + r.size;
		mn = std::min(l.mn, r.mn);
	}
	
	void apply(LazyContext lazy) {
		ans = lazy.val * size;
		mn = (int) lazy.val;
	}
	
	// atributes
	int size, mn;
	long long ans;
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
		push(l), push(r - 1);
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
		push(l), push(r - 1);
		int l0 = l, r0 = r;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, lc);
			if(r & 1) apply(--r, lc);
		}
		build(l0), build(r0 - 1);
	}
	
	// don't copy this for most segment tree problems!
	// search first x in [l, r] such that [l, x) triggers f([l, x))
	template<class F>
	std::pair<int, i_t> search(int l, int r, F f) {
		// assert(l < r);
		if(l >= r) return std::pair<int, i_t>(r, i_t()); // careful with this case
		int lst = r;
		l += n, r += n;
		push(l), push(r-1);
		static int pref[30], suf[30]; // depending on compiler might want to change pref and suf to vectors, resize(h+1) and push_back below
		int s[2] = {0, 0};
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) pref[s[0]++] = l++;
			if(r & 1) suf[s[1]++] = --r;
		}
		i_t cur;
		for(int rep = 0; rep < 2; rep++) {
			if(rep == 1) { std::reverse(suf, suf + s[1]); }
			for(int id = 0; id < s[rep]; id++) {
				int i = rep == 0 ? pref[id] : suf[id];
				if(f(i_t(cur, tree[i]))) {
					while(i < n) {
						pushNode(i);
						i += i;
						i_t other = i_t(cur, tree[i]);
						if(!f(other)) {
							cur = other;
							i++;
						}
					}
					return std::pair<int, i_t>(i - n, cur);
				}
				cur = i_t(cur, tree[i]);
			}
		}
		return std::pair<int, i_t>(lst, cur);
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
			pushNode(i);
		}
	}

	inline void pushNode(int i) {
		if(dirty[i]) {
			apply(i + i, lazy[i]);
			apply(i + i + 1, lazy[i]);
			lazy[i].reset();
			dirty[i] = false;
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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SegmentTree<Node, long long, LazyContext> tree;
	tree.init(a);
	while(q--) {
		int t;
		int x;
		long long y;
		std::cin >> t >> x >> y;
		if(t == 1) {
			// set to max y until x
			int pt = tree.search(0, x, [&](Node node) { return node.mn < y; }).first;
			tree.upd(pt, x, LazyContext(y));
		} else {
			// starting from x, do greedy
			int ans = 0;
			x--;
			while(x < n) {
				auto got = tree.search(x, n, [&](Node node) { return node.ans > y; });
				int pt2 = got.first;
				ans += pt2 - x;
				y -= got.second.ans;
				x = tree.search(pt2 + 1, n, [&](Node node) { return node.mn <= y; }).first;
			}
			std::cout << ans << '\n';
		}
	}
}