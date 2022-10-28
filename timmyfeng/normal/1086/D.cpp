#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick_tree {

	vector<T> tree;
	int n;

	fenwick_tree(int _n) : tree(_n + 1), n(_n) {}

	void update(int a, T val) {
		for ( ; a <= n; a += a & -a) {
			tree[a] += val;
		}
	}

	T query(int a) {
		int res = 0;
		for ( ; a > 0; a -= a & -a) {
			res += tree[a];
		}
		return res;
	}

	T query(int a, int b) {
		return query(min(n, b)) - query(a - 1);
	}

	int kth(T k) {
		if (k == 0)
			return 0;

		int res = 0;
		T cur = 0;
		for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
			if (res + (1 << i) <= n && cur + tree[res + (1 << i)] < k) {
				res += 1 << i;
				cur += tree[res];
			}
		}
		return res + 1;
	}

};

int to_ndx(char c) {
	if (c == 'R') {
		return 0;
	} else if (c == 'P') {
		return 1;
	} else {
		return 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	string s;
	cin >> n >> q >> s;

	vector<fenwick_tree<int>> ft(3, n);
	for (int i = 0; i < n; ++i) {
		ft[to_ndx(s[i])].update(i + 1, 1);
	}

	auto calc = [&ft, &n]() {
		vector<int> first(3);
		vector<int> last(3);

		for (int i = 0; i < 3; ++i) {
			first[i] = ft[i].kth(1);
			last[i] = ft[i].kth(ft[i].query(n));
		}

		int ans = 0;
		for (int i = 0; i < 3; ++i) {
			int l1 = first[(i + 1) % 3];
			int r1 = max(l1, first[(i + 2) % 3]);
			int r2 = last[(i + 1) % 3];
			int l2 = min(r2, last[(i + 2) % 3]);

			ans += ft[i].query(n);
			if ((l2 <= r1 && r2 >= r1) || (l2 <= l1 && r2 >= l1)) {
				ans -= ft[i].query(min(l1, l2), max(r1, r2));
			} else {
				ans -= ft[i].query(l1, r1);
				ans -= ft[i].query(l2, r2);
			}
		}
		return ans;
	};

	cout << calc() << "\n";
	while (q--) {
		int p;
		char c;
		cin >> p >> c;

		ft[to_ndx(s[p - 1])].update(p, -1);
		ft[to_ndx(c)].update(p, 1);
		s[p - 1] = c;

		cout << calc() << "\n";
	}
}