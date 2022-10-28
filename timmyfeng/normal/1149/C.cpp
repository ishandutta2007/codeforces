#include <bits/stdc++.h>
using namespace std;

struct segment_tree {

	struct node {
		int u, l, ul, lv, ulv;
		int bal;

		void apply(int _l, int _r, int val) {
			u = val;
			l = -2 * val;
			ul = -val;
			lv = -val;
			bal = val;
		}
	};

	node combine(const node& a, const node& b) {
		node c;
		c.bal = a.bal + b.bal;
		c.u = max(a.u, b.u + a.bal);
		c.l = max(a.l, b.l - 2 * a.bal);
		c.ul = max({a.ul, b.ul - a.bal, a.u + b.l - 2 * a.bal});
		c.lv = max({a.lv, b.lv - a.bal, a.l + b.u + a.bal});
		c.ulv = max({a.ulv, b.ulv, a.ul + b.u + a.bal, a.u + b.lv - a.bal});
		return c;
	}

	void push(int v, int l, int r) {
		int m = (l + r) / 2;
	}

	void pull(int v) {
		tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
	}

	vector<node> tree;
	int n;

	template <class T>
	void build(int v, int l, int r, const vector<T>& a) {
		if (l == r) {
			tree[v].apply(l, r, a[l]);
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

	template <class T>
	segment_tree(int _n, const vector<T>& a) : tree(4 * _n), n(_n) {
		build(1, 0, n - 1, a);
	}

	template <class... T>
	void upd(int a, const T&... val) {
		upd(1, 0, n - 1, a, a, val...);
	}

};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	string s;
	cin >> n >> q >> s;

	vector<int> delta(s.size() + 1u);
	for (int i = 0; i < int(s.size()); ++i) {
		delta[i + 1] = (s[i] == '(' ? 1 : -1);
	}

	segment_tree st(delta.size(), delta);
	cout << st.tree[1].ulv << "\n";

	while (q--) {
		int a, b;
		cin >> a >> b;

		swap(delta[a], delta[b]);
		st.upd(a, delta[a]);
		st.upd(b, delta[b]);

		cout << st.tree[1].ulv << "\n";
	}
}