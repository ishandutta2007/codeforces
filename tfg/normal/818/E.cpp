#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Point update, range Query segment tree

int k;
struct Node {
	Node(int v = 1) {
		// init
		ans = v % k;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = (int) ((long long) l.ans * r.ans % k);
	}

	// atributes
	int ans;
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
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SegmentTree<Node, int> tree;
	tree.init(a);
	long long ans = 0;
	for(int l = 0, r = 0; l < n; l++) {
		r = std::max(r, l+1);
		while(r < n && tree.qry(l, r).ans != 0) {
			r++;
		}
		if(tree.qry(l, r).ans == 0) {
			ans += (n - r + 1);
		}
	}
	//ans = std::max(ans - 1, 0LL);
	std::cout << ans << '\n';
}