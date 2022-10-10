#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Range update, range query segment tree

struct LazyContext {
	LazyContext(int v = 0) {
		sum = v;
	}
	
	void reset() {
		sum = 0;
	}
	
	void operator += (LazyContext o) {
		sum += o.sum;
	}
	
	// atributes
	int sum;
};

struct Node {
	Node(int v = 0) {
		// init
		mn = mx = v;
	}
	
	Node(Node &l, Node &r) {
		// merge
		mn = std::min(l.mn, r.mn);
		mx = std::max(l.mx, r.mx);
	}
	
	void apply(LazyContext lazy) {
		mn += lazy.sum;
		mx += lazy.sum;
	}
	
	// atributes
	int mn, mx;
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
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(std::vector<int>(1 << 20, 0));
	int pt = 0;
	int sum = 0;
	std::vector<int> a(1 << 20, 0);
	while(n--) {
		char c;
		std::cin >> c;
		if(c == 'L') {
			pt = std::max(pt - 1, 0);
		} else if(c == 'R') {
			pt++;
		} else {
			int v;
			if(c == '(') {
				v = 1;
			} else if(c == ')') {
				v = -1;
			} else {
				v = 0;
			}
			//std::cout << "changing " << pt << " to " << v << c << '\n';
			v = v - a[pt];
			a[pt] = v + a[pt];
			sum += v;
			tree.upd(pt, 1 << 20, v);
		}
		auto got = tree.qry(0, 1 << 20);
		//std::cout << '\n' << got.mx << ", " << got.mn << ' ';
		//std::cout << "sum is " << sum << ' ';
		if(sum == 0 && got.mn >= 0) {
			std::cout << got.mx << ' ';
		} else {
			std::cout << "-1 ";
		}
	}
	std::cout << '\n';
}