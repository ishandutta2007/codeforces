#include <bits/stdc++.h>
using namespace std;

const int L = 32;
const int N = 5e5;

struct segment_tree {

	struct node {
		long long sum = 0;
		vector<int> bal;

		void apply(int l, int r, int val) {
			sum = val;
			if (val > 0) {
				bal = {(val + 1) / 2};
			} else {
				bal.clear();
			}
		}
	};

	node combine(const node& a, const node& b) {
		node c;
		c.sum = a.sum + b.sum;
		c.bal = a.bal;
		for (auto i : b.bal) {
			if (i > a.sum) {
				c.bal.push_back(i - a.sum);
			}
		}
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
			return;
		} else {
			int m = (l + r) / 2;
			build(v * 2, l, m);
			build(v * 2 + 1, m + 1, r);
			pull(v);
		}
	}

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

	segment_tree(int _n) : tree(4 * _n), n(_n) {
		build(1, 1, n);
	}

	template <class... T>
	void update(int a, const T&... val) {
		update(1, 1, n, a, a, val...);
	}

};

char c[N];
int x[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	vector<int> vals;
	for (int i = 0; i < q; ++i) {
		cin >> c[i] >> x[i];
		if (c[i] == '+') {
			vals.push_back(x[i]);
		}
	}
	sort(vals.begin(), vals.end());

	map<int, int> left;
	map<int, int> right;
	for (int i = 0; i < int(vals.size()); ++i) {
		if (i == 0 || vals[i - 1] != vals[i]) {
			left[vals[i]] = i;
			right[vals[i]] = i;
		}
	}

	segment_tree st(vals.size());

	int n = 0;
	for (int i = 0; i < q; ++i) {
		if (c[i] == '+') {
			st.update(++left[x[i]], x[i]);
			++n;
		} else {
			st.update(++right[x[i]], 0);
			--n;
		}
		cout << n - int(st.tree[1].bal.size()) << "\n";
	}
}