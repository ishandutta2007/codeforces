#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1 << 20;
const int INF = 1e9;
const int me = 20;

// Range update, range query segment tree

struct Node {
	Node(int x = -INF) {
		// init
		mx = x;
	}
	
	Node(Node &l, Node &r) {
		// merge
		mx = std::max(l.mx, r.mx);
	}
	
	void apply(int lazy) {
		mx += lazy;
	}
	
	// atributes
	int mx;
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
			lazy[i] = 0;
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

	void upd(int x, e_t v) {
		x += n;
		push(x);
		tree[x] = i_t(v);
		build(x);
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
				lazy[i] = 0;
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

std::vector<int> edges[ms];
int to[ms];
int in[ms], out[ms], c = 0;

void dfs(int on) {
	in[on] = c++;
	for(auto too : edges[on]) {
		dfs(too);
	}
	out[on] = c;
}

int ans[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	a.push_back(n + 1);
	std::vector<int> st;
	st.push_back(n);
	for(int i = n-1; i >= 0; i--) {
		while(a[st.back()] <= a[i]) {
			st.pop_back();
		}
		to[i] = st.back();
		edges[st.back()].push_back(i);
		st.push_back(i);
	}
	SegmentTree<Node, int, int> tree, ok;
	tree.init(std::vector<int>(n + 1, 0));
	dfs(n);
	for(int i = n-1; i >= 0; i--) {
		// use position i
		{
			tree.upd(in[i], out[i], 1);
		}
		// remove position i + k
		if(i + k < n) {
			tree.upd(in[i+k], out[i+k], -1);
		}
		ans[i] = tree.qry(0, n + 1).mx;
	}
	for(int i = 0; i + k <= n; i++) {
		std::cout << ans[i] << '\n';
	}
}