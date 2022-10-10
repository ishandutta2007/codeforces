#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const long long INF = 1e18;
struct Node {
	Node(int v = -1) {
		// init
		mx[0] = mn[0] = 0;
		mx[1] = mn[1] = v;
	}
	
	Node(Node l, Node r) {
		// merge
		if(l.mx[1] == -1) {
			*this = r;
		} else if(r.mx[1] == -1) {
			*this = l;
		} else {
			for(int i = 0; i < 2; i++) {
				mn[i] = INF;
				mx[i] = -INF;
			}
			for(int i = 0; i < 2; i++) {
				for(int j = 0; j < 2; j++) {
					mn[i^j] = std::min(mn[i^j], l.mn[i] + (i == 1 ? -r.mx[j] : r.mn[j]));
					mx[i^j] = std::max(mx[i^j], l.mx[i] + (i == 1 ? -r.mn[j] : r.mx[j]));
				}
			}
		}
	}

	int ans() { return std::max(mx[0], mx[1]); }

	// atributes
	int mn[2], mx[2];
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


int32_t main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, q;
		std::cin >> n >> q;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		SegmentTree<Node, int> tree;
		tree.init(a);
		std::cout << tree.qry(0, n).ans() << '\n';
		while(q--) {
			int l, r;
			std::cin >> l >> r;
			l--;r--;
			std::swap(a[l], a[r]);
			tree.upd(l, a[l]);
			tree.upd(r, a[r]);
			std::cout << tree.qry(0, n).ans() << '\n';
		}
	}
}