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
		ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = -1;
	}
	
	Node(long long v) {
		// init
		ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = 0;
		if(v < 0) {
			ans[1][0] = -v;
		} else {
			ans[0][1] = v;
		}
	}
	
	Node(Node l, Node r) {
		// merge
		if(l.ans[0][0] == -1) {
			*this = r;
		} else if(r.ans[0][0] == -1) {
			*this = l;
		} else {
			ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = 0;
			for(int k = 0; k < 2; k++) for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
				auto use = std::min(l.ans[i][j], r.ans[j][k]);
				ans[i][k] += use;
				l.ans[i][j] -= use;
				r.ans[j][k] -= use;
			}
			for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
				ans[i][j] += l.ans[i][j] + r.ans[i][j];
			}
		}
	}

	long long query() {
		if(ans[0][1] || ans[1][0] || ans[1][1]) {
			return -1;
		} else {
			return ans[0][0];
		}
	}

	// atributes
	long long ans[2][2];
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
	int n, q;
	std::cin >> n >> q;
	std::vector<long long> a(n, 0);
	for(int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		a[i] -= x;
	}
	for(int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		a[i] += x;
	}
	SegmentTree<Node, long long> tree;
	tree.init(a);
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		l--;
		std::cout << tree.qry(l, r).query() << '\n';
	}
}