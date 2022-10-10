#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;
const long long INF = 1e18;

struct LazyContext {
	LazyContext(int val = 0) {
		sum = val;
	}
	
	void reset() {
		sum = 0;
	}
	
	void operator += (LazyContext o) {
		sum += o.sum;
	}
	
	// atributes
	long long sum = 0;
};

struct Node {
	Node(long long val = INF) {
		// init
		ans = val;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = std::min(l.ans, r.ans);
	}
	
	void apply(LazyContext lazy) {
		ans += lazy.sum;
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

struct Query {
	int l, r, id;
	Query(int a, int b, int c) : l(a), r(b), id(c) {}
};

SegmentTree<Node, long long, LazyContext> tree;

int n;
std::vector<int> edges[ms];
std::vector<Query> qries[ms];
long long h[ms];
int in[ms], out[ms], par[ms], w[ms];
bool leaf[ms];
long long ans[ms];

void dfs(int on) {
	for(auto qry : qries[on]) {
		ans[qry.id] = tree.qry(qry.l, qry.r).ans;
	}
	for(auto to : edges[on]) {
		tree.upd(0, n, LazyContext(w[to]));
		tree.upd(in[to], out[to], LazyContext(-2*w[to]));
		dfs(to);
		tree.upd(0, n, LazyContext(-w[to]));
		tree.upd(in[to], out[to], LazyContext(2*w[to]));
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> n >> q;
	in[0] = 0;
	out[0] = 1;
	for(int i = 1; i < n; i++) {
		std::cin >> par[i] >> w[i];
		par[i]--;
		leaf[par[i]] = true;
		in[i] = i;
		out[i] = i+1;
		h[i] = h[par[i]] + w[i];
		edges[par[i]].push_back(i);
	}
	for(int i = n-1; i > 0; i--) {
		out[par[i]] += out[i] - in[i];
	}
	for(int i = 0; i < q; i++) {
		int x, l, r;
		std::cin >> x >> l >> r;
		x--;l--;
		qries[x].emplace_back(l, r, i);
	}
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = !leaf[i] ? h[i] : INF;
	}
	tree.init(a);
	dfs(0);
	for(int i = 0; i < q; i++) {
		std::cout << ans[i] << '\n';
	}
}