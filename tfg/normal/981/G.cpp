#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <set>

typedef std::pair<int, int> ii;

template <class Info = int>
class ColorUpdate {
public:
	struct Range {
		Range(int l = 0) { this->l = l; }
		Range(int l, int r, Info v) {
			this->l = l;
			this->r = r;
			this->v = v;
		}
		int l, r;
		Info v;

		bool operator < (const Range &b) const { return l < b.l; }
	};

	std::vector<Range> upd(int l, int r, Info v) {
		std::vector<Range> ans;
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

typedef long long ll;
const int MOD = 998244353;

struct LazyContext {
	LazyContext(int m = 1, int s = 0) {
		mult = m;
		sum = s;
	}
	
	void reset() {
		*this = LazyContext();
	}
	
	void operator += (LazyContext o) {
		mult = (ll) o.mult * mult % MOD;
		sum = (o.sum + (ll) o.mult * sum) % MOD;
	}
	
	// atributes
	int mult, sum;
};

struct Node {
	Node(int v = 0) {
		// init
		ans = v;
		size = 1;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = (l.ans + r.ans) % MOD;
		size = l.size + r.size;
	}
	
	void apply(LazyContext lazy) {
		ans = ((ll)ans * lazy.mult + (ll)lazy.sum * size) % MOD;
	}
	
	// atributes
	int ans, size;
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

int main() {
	int n, q;
	std::cin >> n >> q;
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(std::vector<int>(n, 0));
	std::vector< ColorUpdate<> > colors(n + 1);
	for(int i = 0; i <= n; i++) {
		colors[i].upd(0, n, 0);
	}
	while(q--) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		//std::cout << "got query " << l - 1 << ", " << r - 1 << " of type " << t << std::endl;
		l--;
		if(t == 1) {
			// update
			int x;
			scanf("%d", &x);
			//std::cout << "val is " << x << std::endl;
			auto v = colors[x].upd(l, r, 1);
			for(auto s : v) {
				LazyContext lazy;
				if(s.v == 0) {
					lazy.sum++;
				} else {
					lazy.mult++;
				}
				//std::cout << "got range " << s.l << ", " << s.r << " and color " << s.v << std::endl;
				//std::cout << "updating with " << lazy.mult << ", " << lazy.sum << std::endl;
				tree.upd(s.l, s.r, lazy);
			}
		} else {
			printf("%d\n", tree.qry(l, r).ans);
		}
	}
}