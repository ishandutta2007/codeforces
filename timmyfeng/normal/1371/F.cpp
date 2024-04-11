#include <bits/stdc++.h>
using namespace std;

struct segment_tree {

	struct node {
		int pre_single[2] = {};
		int pre_double[2] = {};
		int suf_single[2] = {};
		int suf_double[2] = {};
		int res[2] = {};
		int len = 0;

		bool flip = false;

		void apply(int l, int r, char val) {
			for (int i = 0; i < 2; ++i) {
				pre_single[i] = (val == "><"[i]);
				suf_single[i] = (val == "><"[i]);
				pre_double[i] = 0;
				suf_double[i] = 0;
				res[i] = 0;
			}
			len = r - l + 1;
		}

		void apply(int l, int r) {
			swap(pre_single[0], pre_single[1]);
			swap(pre_double[0], pre_double[1]);
			swap(suf_single[0], suf_single[1]);
			swap(suf_double[0], suf_double[1]);
			swap(res[0], res[1]);
			flip ^= true;
		}
	};

	node combine(const node& a, const node& b) {
		node c;
		for (int i = 0; i < 2; ++i) {
			c.pre_single[i] = a.pre_single[i] == a.len ? a.len + b.pre_single[i] : a.pre_single[i];
			c.suf_single[i] = b.suf_single[i] == b.len ? b.len + a.suf_single[i] : b.suf_single[i];

			if (!a.len) {
				c.pre_double[i] = b.pre_double[i];
			} else if (a.pre_double[i] == a.len) {
				c.pre_double[i] = a.len + b.pre_single[!i];
			} else if (a.pre_double[i] > 0) {
				c.pre_double[i] = a.pre_double[i];
			} else if (b.pre_double[i] || b.pre_single[!i]) {
				c.pre_double[i] = a.pre_single[i] == a.len ? a.len + max(b.pre_double[i], b.pre_single[!i]) : 0;
			}

			if (!b.len) {
				c.suf_double[i] = a.suf_double[i];
			} else if (b.suf_double[i] == b.len) {
				c.suf_double[i] = b.len + a.suf_single[i];
			} else if (b.suf_double[i] > 0) {
				c.suf_double[i] = b.suf_double[i];
			} else if (a.suf_double[i] || a.suf_single[i]) {
				c.suf_double[i] = b.suf_single[!i] == b.len ? b.len + max(a.suf_double[i], a.suf_single[i]) : 0;
			}

			c.res[i] = max(a.res[i], b.res[i]);
			if (a.suf_double[i]) {
				c.res[i] = max(c.res[i], a.suf_double[i] + b.pre_single[!i]);
			}
			if (a.suf_single[i] && b.pre_single[!i]) {
				c.res[i] = max(c.res[i], a.suf_single[i] + b.pre_single[!i]);
			}
			if (b.pre_double[i]) {
				c.res[i] = max(c.res[i], a.suf_single[i] + b.pre_double[i]);
			}
		}
		c.len = a.len + b.len;
		return c;
	}

	void push(int v, int l, int r) {
		int m = (l + r) / 2;
		if (tree[v].flip) {
			tree[v * 2].apply(l, m);
			tree[v * 2 + 1].apply(m + 1, r);
			tree[v].flip = false;
		}
	}

	void pull(int v) {
		tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
	}

	vector<node> tree;
	int n;

	void build(int v, int l, int r) {
		if (l == r) {
			return;
		} else {
			int m = (l + r) / 2;
			build(v * 2, l, m);
			build(v * 2 + 1, m + 1, r);
			pull(v);
		}
	}

	void build(int v, int l, int r, const string& a) {
		if (l == r) {
			tree[v].apply(l, r, a[l - 1]);
		} else {
			int m = (l + r) / 2;
			build(v * 2, l, m, a);
			build(v * 2 + 1, m + 1, r, a);
			pull(v);
		}
	}

	template <class... T>
	void upd(int v, int l, int r, int a, int b, const T&... val) {
		if (b < l || r < a) {
			return;
		} else if (a <= l && r <= b) {
			tree[v].apply(l, r, val...);
		} else {
			push(v, l, r);
			int m = (l + r) / 2;
			upd(v * 2, l, m, a, b, val...);
			upd(v * 2 + 1, m + 1, r, a, b, val...);
			pull(v);
		}
	}

	node qry(int v, int l, int r, int a, int b) {
		if (b < l || r < a) {
			return node();
		} else if (a <= l && r <= b) {
			return tree[v];
		}

		push(v, l, r);
		int m = (l + r) / 2;
		return combine(qry(v * 2, l, m, a, b), qry(v * 2 + 1, m + 1, r, a, b));
	}

	segment_tree(int _n) : tree(4 * _n), n(_n) {
		build(1, 1, n);
	}

	segment_tree(int _n, const string& s) : tree(4 * _n), n(_n) {
		build(1, 1, n, s);
	}

	template <class... T>
	void upd(int a, int b, const T&... val) {
		upd(1, 1, n, a, b, val...);
	}

	template <class... T>
	void upd(int a, const T&... val) {
		upd(1, 1, n, a, a, val...);
	}

	node qry(int a, int b) {
		return qry(1, 1, n, a, b);
	}

};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	string s;
	cin >> n >> q >> s;

	segment_tree st(n, s);

	while (q--) {
		int l, r;
		cin >> l >> r;
		st.upd(l, r);
		auto ans = st.qry(l, r);
		cout << max({ans.pre_single[1], ans.res[0], ans.suf_single[0]}) << "\n";
	}
}