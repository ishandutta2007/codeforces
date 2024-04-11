#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

string c;

struct segment_tree {

	struct node {
		int matrix[2][2];

		void apply(int l, int r) {
			matrix[0][1] = 1;
			matrix[1][0] = (c[l - 1] == '1') ? '9' - c[l] : 0;
			matrix[1][1] = c[l - 1] - '0' + 1;
		}
	};

	node combine(const node& a, const node& b) {
		node c;
		c.matrix[0][0] = add(mul(a.matrix[0][0], b.matrix[0][0]), mul(a.matrix[0][1], b.matrix[1][0]));
		c.matrix[0][1] = add(mul(a.matrix[0][0], b.matrix[0][1]), mul(a.matrix[0][1], b.matrix[1][1]));
		c.matrix[1][0] = add(mul(a.matrix[1][0], b.matrix[0][0]), mul(a.matrix[1][1], b.matrix[1][0]));
		c.matrix[1][1] = add(mul(a.matrix[1][0], b.matrix[0][1]), mul(a.matrix[1][1], b.matrix[1][1]));
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

	void build(int v, int l, int r) {
		if (l == r) {
			tree[v].apply(l, r);
		} else {
			int m = (l + r) / 2;
			build(v * 2, l, m);
			build(v * 2 + 1, m + 1, r);
			pull(v);
		}
	}

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

	template <class T>
	segment_tree(int _n, const vector<T>& a) : tree(4 * _n), n(_n) {
		build(1, 1, n, a);
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

	int n, m;
	cin >> n >> m >> c;
	c += '9';

	segment_tree st(n);

	while (m--) {
		int x;
		char d;
		cin >> x >> d;

		c[x - 1] = d;
		st.upd(x);
		if (x > 1) {
			st.upd(x - 1);
		}

		cout << st.tree[1].matrix[1][1] << "\n";
	}
}