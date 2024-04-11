#include <iostream>
#include <cstdio>
#include <vector>

typedef long long ll;

const int MOD = 1e9 + 9;
const int ms = 300300;

int fa[ms], fb[ms];
int suma[ms], sumb[ms];

struct LazyContext {
	LazyContext(int pos = -1, int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
		this->pos = pos;
	}
	
	void reset() {
		a = b = 0;
	}
	
	void operator += (LazyContext o) {
		o = o.shift(pos - o.pos);
		a = (a + o.a) % MOD;
		b = (b + o.b) % MOD;
	}
	
	LazyContext shift(int x) {
		return LazyContext(
				pos + x,
				((ll) fa[x + 1] * a + (ll) fb[x] * b) % MOD,
				((ll) fa[x + 2] * a + (ll) fb[x + 1] * b) % MOD
				);
	}
	
	int a, b;
	int pos;
};

struct Node {
	Node(int s = 0, int pos = -1) {
		sum = s;
		l = pos;
		r = pos + 1;
	}
	
	Node(Node l, Node r) {
		// merge
		sum = (l.sum + r.sum) % MOD;
		this->l = l.l;
		this->r = r.r;
	}
	
	void apply(LazyContext lazy) {
		lazy = lazy.shift(l - lazy.pos);
		sum = (sum + (ll) suma[r - l] * lazy.a + (ll) sumb[r - l - 1] * lazy.b) % MOD;
	}
	
	// atributes
	int sum;
	int l, r;
};

template <class i_t, class e_t, class lazy_cont>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(4 * n);
		dirty.assign(2 * n, false);
		lazy.resize(2 * n);
		build(1, 0, n - 1, base);
	}
	
	i_t qry(int l, int r) { return qry(1, 0, n - 1, l, r - 1); }
	void upd(int l, int r, lazy_cont lc) { upd(1, 0, n - 1, l, r - 1, lc); }

private:
	int n;
	std::vector<bool> dirty;
	std::vector<i_t> tree;
	std::vector<lazy_cont> lazy;

	void build(int p, int l, int r, std::vector<e_t> &base) {
		if(l == r) {
			tree[p] = i_t(base[l], l);
		} else {
			int mid = (l + r) / 2;
			build(p + p, l, mid, base);
			build(p + p + 1, mid + 1, r, base);
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
			lazy[p] = lazy_cont(l);
		}
	}

	void apply(int p, int l, int r, lazy_cont &lc) {
		tree[p].apply(lc);
		if(l != r) {
			dirty[p] = true;
			lazy[p] += lc;
		}
	}

	void push(int p, int l, int r) {
		if(dirty[p]) {
			int mid = (l + r) / 2;
			upd(p + p, l, mid, l, mid, lazy[p]);
			upd(p + p + 1, mid + 1, r, mid + 1, r, lazy[p]);
			lazy[p].reset();
			dirty[p] = false;
		}
	}

	void upd(int p, int l, int r, int i, int j, lazy_cont lc) {
		if(i > r || j < l) {
			return;
		} else if(i <= l && r <= j) {
			apply(p, l, r, lc);
		} else {
			push(p, l, r);
			int mid = (l + r) / 2;
			upd(p + p, l, mid, i, j, lc);
			upd(p + p + 1, mid + 1, r, i, j, lc);
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
		}
	}

	i_t qry(int p, int l, int r, int i, int j) {
		if(i > r || j < l) {
			return i_t();
		} else if(i <= l && r <= j) {
			return tree[p];
		} else {
			push(p, l, r);
			int mid = (l + r) / 2;
			return i_t(qry(p + p, l, mid, i, j), qry(p + p + 1, mid + 1, r, i, j));
		}
	}
};

int main() {
	fa[1] = 1;
	fb[1] = fb[2] = 1;
	for(int i = 3; i < ms; i++) {
		fa[i] = (fa[i - 1] + fa[i - 2]) % MOD;
		fb[i] = (fb[i - 1] + fb[i - 2]) % MOD;
	}
	for(int i = 1; i < ms; i++) {
		suma[i] = (suma[i - 1] + fa[i]) % MOD;
		sumb[i] = (sumb[i - 1] + fb[i]) % MOD;
	}
	int n, m;
	std::cin >> n >> m;
	std::vector<int> vals(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &vals[i]);
	}
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(vals);
	for(int i = 0; i < m; i++) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		l--;
		//std::cout << "-----------------------------------\nsolving qry (" << t << ", " << l << ", " << r << ")\n";
		if(t == 1) {
			tree.upd(l, r, LazyContext(l - 1, 0, 1));
		} else {
			printf("%d\n", tree.qry(l, r).sum);
		}
	}
}