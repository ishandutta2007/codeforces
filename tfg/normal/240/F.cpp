#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Range update, range query segment tree

struct LazyContext {
	LazyContext(int v = -1) {
		lazy = v;
	}
	
	void reset() {
		lazy = -1;
	}
	
	void operator += (LazyContext o) {
		if(o.lazy != -1) {
			lazy = o.lazy;
		}
	}
	
	// atributes
	int lazy;
};

struct Node {
	Node() {
		// neutral element or empty node
		for(int i = 0; i < 26; i++) {
			f[i] = 0;
		}
	}
	
	Node(char c) {
		// init
		for(int i = 0; i < 26; i++) {
			f[i] = 0;
		}
		f[c - 'a'] = 1;
	}
	
	Node(Node &l, Node &r) {
		// merge
		for(int i = 0; i < 26; i++) {
			f[i] = l.f[i] + r.f[i];
		}
	}
	
	void apply(LazyContext lazy) {
		if(lazy.lazy != -1) {
			int sum = 0;
			for(int i = 0; i < 26; i++) {
				sum += f[i];
				f[i] = 0;
			}
			f[lazy.lazy] = sum;
		}
	}
	
	// atributes
	int f[26];
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<char> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SegmentTree<Node, char, LazyContext> tree;
	tree.init(a);
	while(m--) {
		int l, r;
		std::cin >> l >> r;
		l--;
		auto node = tree.qry(l, r);
		int odd = -1;
		for(int i = 0; i < 26; i++) {
			if(node.f[i] % 2 == 1) {
				if(odd == -1) {
					odd = i;
				} else {
					odd = 26;
				}
			}
		}
		if(odd == 26) continue;
		for(int i = 0; i < 26; i++) {
			int f = node.f[i] / 2;
			if(f) {
				tree.upd(l, r, LazyContext(i));
				l += f;
				r -= f;
			}
		}
		if(odd != -1) {
			tree.upd(l, r, LazyContext(odd));
		}
	}
	for(int i = 0; i < n; i++) {
		auto node = tree.qry(i, i + 1);
		for(int j = 0; j < 26; j++) {
			if(node.f[j]) {
				std::cout << char(j + 'a');
			}
		}
	}
	std::cout << std::endl;
}