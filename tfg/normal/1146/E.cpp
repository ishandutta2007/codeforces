#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct LazyContext {
	LazyContext() {
		to[0] = 0, to[1] = 1;
	}
	
	void reset() {
		to[0] = 0, to[1] = 1;
	}
	
	void operator += (LazyContext o) {
		to[0] = o.to[to[0]];
		to[1] = o.to[to[1]];
	}
	
	// atributes
	int to[2];
};

struct Node {
	Node(int v = 0) {
		// init
		v += v;
		to[0] = 0;
		to[1] = 1;
	}
	
	Node(Node &l, Node &r) {
		// merge GARBAGE
		to[0] = l.to[0];
		to[1] = r.to[1];
	}
	
	void apply(LazyContext lazy) {
		to[0] = lazy.to[to[0]];
		to[1] = lazy.to[to[1]];
	}
	
	// atributes
	int to[2];
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
	
	i_t qry(int x) {
		x += n;
		push(x);
		//std::cout << "qry for " << x - n << " got (" << tree[x].to[0] << ", " << tree[x].to[1] << ")\n";
		return tree[x];
	}
	
	void upd(int l, int r, lazy_cont lc) {
		//std::cout << "updating [" << l << ", " << r << ") with (" << lc.to[0] << ", " << lc.to[1] << ")\n";
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
	const int ms = 1 << 17;
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(std::vector<int>(ms, 1));
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	while(q--) {
		char c;
		int x;
		std::cin >> c >> x;
		if(c == '>') {
			if(x >= 0) {
				//std::cout << "case1\n";
				LazyContext lazy;
				// all values > |x| are changed from 1 to 0
				lazy.to[1] = 0;
				tree.upd(abs(x) + 1, ms, lazy);
			} else {
				//std::cout << "case2\n";
				LazyContext lazy;
				// all values >= |x| are changed from 1 to 0
				lazy.to[1] = 0;
				tree.upd(abs(x), ms, lazy);
				// all values < |x| are swapped
				lazy.to[1] = 0;
				lazy.to[0] = 1;
				tree.upd(0, abs(x), lazy);
			}
		} else {
			if(x <= 0) {
				//std::cout << "case3\n";
				LazyContext lazy;
				// all values > |x| are changed from 0 to 1
				lazy.to[0] = 1;
				tree.upd(abs(x) + 1, ms, lazy);
			} else {
				//std::cout << "case4\n";
				LazyContext lazy;
				// all values >= |x| are changed from 0 to 1
				lazy.to[0] = 1;
				tree.upd(abs(x), ms, lazy);
				// all values < |x| are swapped
				lazy.to[0] = 1;
				lazy.to[1] = 0;
				tree.upd(0, abs(x), lazy);
			}
		}
	}
	for(auto &v : a) {
		if(v < 0) {
			if(tree.qry(-v).to[0] == 1) {
				v = -v;
			}
		} else {
			if(tree.qry(v).to[1] == 0) {
				v = -v;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}