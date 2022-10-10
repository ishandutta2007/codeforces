#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const int ms = 3010;

template<class T>
class CoordinateCompression {
public:
	CoordinateCompression(const std::vector<T> &a) {
		arr = a;
		std::sort(arr.begin(), arr.end());
		arr.resize(std::unique(arr.begin(), arr.end()) - arr.begin());
	}

	int getL(T x) { return std::lower_bound(arr.begin(), arr.end(), x) - arr.begin(); }
	int getR(T x) { return std::upper_bound(arr.begin(), arr.end(), x) - arr.begin(); }
	int size() const { return (int) arr.size(); }
private:
	std::vector<T> arr;
};

struct LazyContext {
	LazyContext(bool v = false) {
		val = v;
	}
	
	void reset() {
		val = false;
	}
	
	void operator += (LazyContext o) {
		val = o.val;
	}
	
	// atributes
	bool val;
};

struct Node {
	Node(bool v = false) {
		// init
		ans = v;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = l.ans || r.ans;
	}
	
	void apply(LazyContext lazy) {
		ans = lazy.val;
	}
	
	// atributes
	bool ans;
};

template <class i_t, class e_t, class lazy_cont = int>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		h = 0;
		while((1 << h) < n) h++;
		tree.resize(2 * n);
		dirty.assign(n, false);
		lazy.resize(n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			lazy[i].reset();
		}
	}
	
	i_t qry(int l, int r) {
		if(l >= r) return i_t();
		l += n, r += n;
		push(l);
		push(r - 1);
		i_t lp, rp;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int l, int r, lazy_cont lc) {
		if(l >= r) return;
		l += n, r += n;
		push(l);
		push(r - 1);
		int l0 = l, r0 = r;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, lc);
			if(r & 1) apply(--r, lc);
		}
		build(l0);
		build(r0 - 1);
	}
	
private:
	int n, h;
	std::vector<bool> dirty;
	std::vector<i_t> tree;
	std::vector<lazy_cont> lazy;
	
	void apply(int p, lazy_cont &lc) {
		tree[p].apply(lc);
		if(p < n) {
			dirty[p] = true;
			lazy[p] += lc;
		}
	}
	
	void push(int p) {
		for(int s = h; s > 0; s--) {
			int i = p >> s;
			if(dirty[i]) {
				apply(i + i, lazy[i]);
				apply(i + i + 1, lazy[i]);
				lazy[i].reset();
				dirty[i] = false;
			}
		}
	}
	
	void build(int p) {
		for(p /= 2; p > 0; p /= 2) {
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
			if(dirty[p]) {
				tree[p].apply(lazy[p]);
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int L, n;
	std::cin >> L >> n;
	std::vector<int> wtf[2];
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		wtf[0].push_back(a[i].first);
		wtf[0].push_back(std::max(1, a[i].first-1));
		wtf[0].push_back(std::min(L, a[i].first+1));
		wtf[1].push_back(a[i].second);
		wtf[1].push_back(std::max(1, a[i].second-1));
		wtf[1].push_back(std::min(L, a[i].second+1));
	}
	wtf[0].push_back(L);
	wtf[0].push_back(1);
	wtf[1].push_back(L);
	wtf[1].push_back(1);
	CoordinateCompression<int> x(wtf[0]);
	CoordinateCompression<int> y(wtf[1]);
	for(auto &p : a) {
		p.first = x.getL(p.first);
		p.second = y.getL(p.second);
	}
	SegmentTree<Node, bool, LazyContext> tree;
	tree.init(std::vector<bool>(y.size(), false));
	tree.upd(0, 1, LazyContext(true));
	std::sort(a.begin(), a.end());
	auto go = [&](int l, int r) {
		int st = l;
		while(l != r) {
			int mid = (l + r) / 2;
			if(tree.qry(st, mid).ans) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	};
	for(int i = 0, j = 0; i < (int) x.size(); i++) {
		int last = -1;
		while(j < (int) a.size() && a[j].first == i) {
			int pos = go(last+1, a[j].second);
			last = a[j++].second;
			tree.upd(pos, last, LazyContext(true));
			tree.upd(last, last+1, LazyContext(false));
		}
		if(last+1 != (int) y.size()) {
			int pos = go(last+1, y.size());
			tree.upd(pos, y.size(), LazyContext(true));
		}
		//for(int haha = 0; haha < y.size(); haha++) {
		//	std::cout << (tree.qry(haha, haha+1).ans ? '1' : '0');
		//} std::cout << '\n';
	}
	std::cout << (tree.qry(y.size()-1, y.size()).ans ? 2 * L - 2 : -1) << '\n';
}