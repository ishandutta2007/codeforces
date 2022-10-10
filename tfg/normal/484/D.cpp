#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;
const int invalid = 1.1e9;

// Range update, range query segment tree

struct LazyContext {
	LazyContext(long long v = 0) {
		val = v;
	}
	
	void reset() {
		val = 0;
	}
	
	void operator += (LazyContext o) {
		val += o.val;
	}
	
	// atributes
	long long val;
};

struct Node {
	Node(long long v = 0) {
		// init
		ans = v;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = std::max(l.ans, r.ans);
	}
	
	void apply(LazyContext lazy) {
		ans += lazy.val;
	}
	
	// atributes
	long long ans;
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
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<long long> dp(n + 1, 0);
	std::vector< std::pair<int, int> > mxst, mnst;
	SegmentTree<Node, long long, LazyContext> tree;
	tree.init(dp);
	for(int i = 0; i < n; i++) {
		// adding from i
		int r = i;
		while(!mxst.empty() && mxst.back().first < a[i]) {
			int l = r - mxst.back().second;
			//std::cout << "updating [" << l << ", " << r << ")" << std::endl;
			tree.upd(l, r, LazyContext(a[i] - mxst.back().first));
			mxst.pop_back();
			r = l;
		}
		mxst.emplace_back(a[i], i - r + 1);
		r = i;
		while(!mnst.empty() && mnst.back().first > a[i]) {
			int l = r - mnst.back().second;
			//std::cout << "updating [" << l << ", " << r << ")" << std::endl;
			tree.upd(l, r, LazyContext(-a[i] + mnst.back().first));
			mnst.pop_back();
			r = l;
		}
		mnst.emplace_back(a[i], i - r + 1);
		tree.upd(i + 1, i + 2, LazyContext(tree.qry(0, i + 1).ans));
	}
	std::cout << tree.qry(n, n + 1).ans << '\n';
}