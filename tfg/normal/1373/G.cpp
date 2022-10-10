#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node(int v = 0) {
		// init
		if(v >= 0) {
			rest = 0;
			ans = v;
		} else {
			rest = -v;
			ans = 0;
		}
	}
	
	Node(Node &l, Node &r) {
		// merge
		int use = std::min(l.rest, r.ans);
		rest = l.rest - use + r.rest;
		ans = l.ans + r.ans - use;
	}
	
	// atributes
	int rest, ans;
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
	int n, k, m;
	std::cin >> n >> k >> m;
	const int ms = 1 << 20;
	std::vector<int> a(ms, 1);
	SegmentTree<Node, int> tree;
	tree.init(a);
	std::set<std::pair<int, int>> st;
	std::multiset<int> wtf;
	wtf.insert(n);
	while(m--) {
		int x, y;
		std::cin >> x >> y;
		int dist = abs(k - x) + y  - 1;
		if(st.count(std::pair<int, int>(x, y))) {
			st.erase(std::pair<int, int>(x, y));
			a[dist]++;
			wtf.erase(wtf.lower_bound(dist+1));
		} else {
			st.insert(std::pair<int, int>(x, y));
			a[dist]--;
			wtf.insert(dist+1);
		}
		tree.upd(dist, a[dist]);
		int l = *wtf.rbegin(), r = ms;
		while(l != r) {
			int mid = (l + r) / 2;
			if(tree.qry(0, mid).rest == 0) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		std::cout << l - n << '\n';
	}
}