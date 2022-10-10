#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node() {
		// empty constructor
		min = 1e9 + 1;
		max = -1;
	}
	
	Node(int x) {
		// init
		min = max = x;
	}
	
	Node(Node l, Node r) {
		// merge
		min = std::min(l.min, r.min);
		max = std::max(l.max, r.max);
	}

	// atributes
	int min, max;
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

int ans[300200];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(3 * n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[n + i] = a[2*n + i] = a[i];
	}
	SegmentTree<Node, int> tree;
	tree.init(a);
	for(int i = 3 * n-1; i >= 0; i--) {
		Node all = tree.qry(i, 3 * n);
		if(all.max == a[i] && all.min * 2 >= all.max) {
			ans[i] = 3 * n - i - 1;
			//std::cout << "at " << i << " got infinity\n";
			continue;
		}
		int l = i + 1, r = 3 * n;
		// find min
		while(l != r) {
			int mid = (l + r) / 2;
			if(tree.qry(i, mid).min * 2 < a[i]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		Node first = tree.qry(i, l);
		if(first.max == a[i] && all.min * 2 < all.max) {
			ans[i] = l - i - 1;
			//std::cout << "at " << i << " got breaking point at " << l << '\n';
			continue;
		}
		l = i + 1, r = 3 * n;
		// find max
		while(l != r) {
			int mid = (l + r) / 2;
			if(tree.qry(i, mid).max != a[i]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		//std::cout << "from " << i << " to " << l-1 << '\n';
		ans[i] = ans[l-1] == -1 ? -1 : ans[l-1] + l - i - 1;
	}
	for(int i = 0; i < n; i++) {
		std::cout << (ans[i] >= 2 * n ? -1 : ans[i]) << (i + 1 == n ? '\n' : ' ');
	}
}