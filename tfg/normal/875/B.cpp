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
		f[0] = f[1] = ans = 0;
	}
	
	Node(int v) {
		// init
		*this = Node();
		f[v] = 1;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = std::max(l.ans, r.ans);
		f[0] = l.f[0] + r.f[0];
		f[1] = l.f[1] + r.f[1];
		if(r.f[0]) {
			ans = std::max(ans, l.f[1] + r.ans);
		}
	}

	// atributes
	int f[2];
	int ans = 0;
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
	int n;
	std::cin >> n;
	SegmentTree<Node, int> tree;
	tree.init(std::vector<int>(n, 0));
	std::cout << 1;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		x--;
		tree.upd(x, 1);
		std::cout << ' ' << tree.qry(0, n).ans + 1;
	}
	std::cout << '\n';
}