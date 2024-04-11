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
		for ( ; a; a -= a & -a) {
			res += tree[a];
		}
		return res;
	}

	T query(int a, int b) {
		return query(b) - query(a - 1);
	}

};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<pair<int, int>> requests;
	for (int i = 0; i < q; ++i) {
		int r, c;
		cin >> r >> c;
		requests.emplace_back(r, c);
	}

	int lo = 0;
	int hi = q; 
	while (lo <= hi) {
		int mi = (lo + hi) / 2;

		vector<pair<int, int>> bad(requests.begin(), requests.begin() + mi);
		sort(bad.rbegin(), bad.rend());
		fenwick_tree<int> ft(2 * m);

		bool ok = true;
		for (auto [r, c] : bad) {
			if (r % 2 == 1) {
				ok &= (ft.query(c, 2 * m) == 0);
			} else {
				ft.update(c, 1);
			}
		}

		if (ok) {
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << (i < hi ? "YES" : "NO") << "\n";
	}
}