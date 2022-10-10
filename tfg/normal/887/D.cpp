#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node(int val = 0) {
		// init
		ans = sum = val;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = std::min(l.ans, l.sum + r.ans);
		sum = l.sum + r.sum;
	}

	// atributes
	long long ans, sum;
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
	int n, costs[2], newCosts[2], start, duration;
	std::cin >> n >> costs[0] >> costs[1] >> newCosts[0] >> newCosts[1];
	std::cin >> start >> duration;
	std::vector<int> times(1, -1);
	std::vector<int> A(1, start);
	auto B = A;
	for(int i = 0; i < n; i++) {
		int t, q;
		std::cin >> t >> q;
		times.push_back(t);
		A.push_back(q == 0 ? -costs[1] : costs[0]);
		B.push_back(q == 0 ? -newCosts[1] : newCosts[0]);
	}
	// interesting times:
	// 0
	// t-duration
	// t
	// t-duration+1
	// t+1
	SegmentTree<Node, int> treeA, treeB;
	treeA.init(A), treeB.init(B);
	assert(A.size() == B.size() && (int) A.size() == n+1);
	auto eval = [&](int x) {
		if(x < 0) return -1LL;
		int l = std::lower_bound(times.begin(), times.end(), x) - times.begin();
		int r = std::lower_bound(times.begin(), times.end(), x + duration) - times.begin();
		return Node(treeA.qry(0, l), treeB.qry(l, r)).ans;
	};
	std::vector<int> candidates(1, 0);
	for(auto x : times) {
		candidates.push_back(x);
		candidates.push_back(x+1);
		candidates.push_back(x-duration);
		candidates.push_back(x-duration+1);
	}
	for(auto x : candidates) if(eval(x) >= 0) {
		std::cout << x << std::endl;
		return 0;
	}
	std::cout << "-1\n";
}