#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

// Point update, range Query segment tree

struct Node {
	Node(long long v = 0) {
		// init
		ans = std::max(v, -v);
	}
	
	Node(Node l, Node r) {
		// merge
		ans = gcd(l.ans, r.ans);
	}

	// atributes
	long long ans;
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
		int n;
		std::cin >> n;
		std::vector<long long> a(n), b(n-1);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			if(i) b[i-1] = a[i] - a[i-1];
		}
		int ans = 1;
		SegmentTree<Node, long long> tree;
		tree.init(b);
		for(int l = 0, r = 0; l < n; l++) {
			r = std::max(l, r);
			while(r+1 < n && tree.qry(l, r+1).ans > 1) {
				r++;
			}
			ans = std::max(ans, r-l+1);
		}
		std::cout << ans << '\n';
	}
}