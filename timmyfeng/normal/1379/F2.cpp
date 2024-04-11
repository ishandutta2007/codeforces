#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

struct segment_tree {

	struct node {
		int mn_odd, mx_even;
		bool ok;

		node() : mn_odd(N * 2), mx_even(0), ok(true) {}

		void apply(int l, int r, int val) {
			if (l % 2 == 1) {
				mn_odd = val;
			} else {
				mx_even = val;
			}
		}
	};

	node combine(const node& a, const node& b) {
		node c;
		c.mn_odd = min(a.mn_odd, b.mn_odd);
		c.mx_even = max(a.mx_even, b.mx_even);
		c.ok = (a.ok && b.ok && a.mn_odd > b.mx_even);
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

	template <class... T>
	void update(int v, int l, int r, int a, int b, const T&... val) {
		if (b < l || r < a) {
			return;
		} else if (a <= l && r <= b) {
			tree[v].apply(l, r, val...);
		} else {
			push(v, l, r);
			int m = (l + r) / 2;
			update(v * 2, l, m, a, b, val...);
			update(v * 2 + 1, m + 1, r, a, b, val...);
			pull(v);
		}
	}

	segment_tree(int _n) : tree(4 * _n), n(_n) {}

	template <class... T>
	void update(int a, const T&... val) {
		update(1, 1, n, a, a, val...);
	}

};

set<int> rows[2 * N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	segment_tree st(2 * n);

	while (q--) {
		int r, c;
		cin >> r >> c;

		if (rows[r].count(c)) {
			rows[r].erase(c);
		} else {
			rows[r].insert(c);
		}

		if (r % 2) {
			st.update(r, rows[r].empty() ? 2 * N : *rows[r].begin());
		} else {
			st.update(r, rows[r].empty() ? 0 : *rows[r].rbegin());
		}

		cout << (st.tree[1].ok ? "YES" : "NO") << "\n";
	}
}