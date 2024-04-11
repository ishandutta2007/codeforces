#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Point update, range Query segment tree

struct Node {
	Node() {
		// empty constructor
		l = r = sum = 0;
	}
	
	Node(char ch) {
		// init
		if(ch == '-') {
			l = -1;
			r = 0;
			sum = -1;
		} else {
			l = 0, r = 1, sum = 1;
		}
	}
	
	Node(Node ln, Node rn) {
		// merge
		sum = ln.sum + rn.sum;
		l = std::min(ln.l, ln.sum + rn.l);
		r = std::max(ln.r, ln.sum + rn.r);
	}

	int ans() const { return r - l + 1; }
	// atributes
	int l, r, sum;
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
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<char> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		SegmentTree<Node, char> tree;
		tree.init(a);
		while(m--) {
			int l, r;
			std::cin >> l >> r;
			std::cout << Node(tree.qry(0, l-1), tree.qry(r, n)).ans() << '\n';
		}
	}
}