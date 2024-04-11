#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node(long long v = 0) {
		ans = mn = mx = sum = v;
		ans = std::max(ans, 0LL);
	}
	
	Node(Node l, Node r) {
		// merge
		ans = std::max(std::max(l.ans, r.ans), r.mx + l.sum - l.mn);
		mx = std::max(l.mx, r.mx + l.sum);
		mn = std::min(l.mn, r.mn + l.sum);
		sum = l.sum + r.sum;
		ans = std::max(mx, ans);
	}

	// atributes
	long long mn, mx, sum, ans;
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
	std::cout << std::fixed << std::setprecision(4);
	int n, m, c;
	std::cin >> n >> m >> c;
	std::vector<long long> sum(n - 1, 0);
	std::vector<long long> x(n, 0);
	std::vector<long long> p(n - 1, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	for(int i = 0; i + 1 < n; i++) {
		std::cin >> p[i];
	}
	SegmentTree<Node, long long> tree;
	std::vector<long long> base(n - 1);
	for(int i = 0; i + 1 < n; i++) {
		base[i] = (x[i + 1] - x[i]) * 100 - (p[i] * 2 * c);
	}
	tree.init(base);
	long long ans = 0;
	for(int i = 0; i < m; i++) {
		int l, r;
		std::cin >> l >> r;
		l--;r--;
		ans += std::max(tree.qry(l, r).ans, 0LL);
	}
	std::cout << ans / 200 << '.' << (ans % 200 * 5 / 100 % 10) << (ans % 200 * 5 / 10 % 10) << (ans % 200 * 5 % 10) << '\n';
}