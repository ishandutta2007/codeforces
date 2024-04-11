#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node() {
		// empty constructor
	}
	
	Node(Node l, Node r) {
		// merge
		*this = l;
		int use = std::min(up, r.dlow);
		dlow += r.dlow - use;
		dup += r.dup + use;
		up += r.up - use;
		low += r.low + use;
	}

	void del() {
		if(low) {
			low--;
			dlow++;
		} else {
			//assert(up);
			up--;
			dup++;
		}
	}

	void goUp() {
		if(low) {
			low--;
			up++;
		} else {
			//assert(dlow);
			dlow--;
			dup++;
		}
	}

	// atributes
	int low = 0, up = 0;
	int dlow = 0, dup = 0;
};

template <class i_t>
class SegmentTree {
public:
	void init(std::vector<i_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = base[i];
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
	
	void upd(int pos, i_t v) {
		pos += n;
		tree[pos] = v;
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
	std::vector<int> a(n), rev(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		rev[--a[i]] = i;
	}
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		b[i]--;
	}
	std::vector<std::pair<int, int>> ans(n, std::pair<int, int>(0, n));
	for(bool run = true; run;) {
		run = false;
		std::vector<Node> bas(n);
		for(int i = 0; i < n; i++) {
			bas[i].low++;
		}
		SegmentTree<Node> tree;
		tree.init(bas);
		int pt = n;
		for(int i = 0; i < n; i++) {
			if(i) {
				// delete on pos
				bas[b[i-1]].del();
				tree.upd(b[i-1], bas[b[i-1]]);
			}
			if(ans[i].first == ans[i].second) continue;
			run = true;
			int mid = (ans[i].first + ans[i].second) / 2;
			//std::cout << "at " << i << " got (" << ans[i].first << ", " << ans[i].second << ") with mid " << mid << std::endl;
			// fix pt
			//assert(pt >= mid);
			while(pt > mid) {
				pt--;
				// go up
				bas[rev[pt]].goUp();
				tree.upd(rev[pt], bas[rev[pt]]);
			}
			// check
			if(tree.qry(0, n).up) {
				ans[i].first = mid + 1;
			} else {
				ans[i].second = mid;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		assert(ans[i].first == ans[i].second);
		std::cout << ans[i].first << '\n';
	}
}