#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

int seg_tree[4 * MX];
vector<int> vals;

int res[MX];
int a[MX];
int n;

void upd(int a, int val, int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		seg_tree[v] = val;
	} else {
		int m = (l + r) / 2;
		if (a <= m) {
			upd(a, val, v * 2, l, m);
		} else {
			upd(a, val, v * 2 + 1, m + 1, r);
		}
		seg_tree[v] = max(seg_tree[v * 2], seg_tree[v * 2 + 1]);
	}
}

int qry(int a, int b, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a) {
		return 0;
	} else if (a <= l && r <= b) {
		return seg_tree[v];
	} else {
		int m = (l + r) / 2;
		return max(qry(a, b, v * 2, l, m),
				qry(a, b, v * 2 + 1, m + 1, r));
	}
}

void add(int u) {
	int ndx = lower_bound(vals.begin(), vals.end(), u) - vals.begin();

	int dep;
	if (ndx == int(vals.size())) {
		dep = ndx;
	} else {
		dep = qry(ndx, vals.size() - 1u) + 1;
	}

	vals.erase(vals.begin() + ndx, vals.end());
	vals.push_back(u);

	upd(ndx, dep);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int rt = find(a, a + n, 1) - a;

	for (int i = 1; i < n; ++i) {
		add(a[(rt + i) % n]);
		res[(rt + i + 1) % n] = max(res[(rt + i + 1) % n], seg_tree[1] + 1);
	}

	vals.clear();
	memset(seg_tree, 0, sizeof seg_tree);

	for (int i = 1; i < n; ++i) {
		add(a[(rt - i + n) % n]);
		res[(rt - i + n) % n] = max(res[(rt - i + n) % n], seg_tree[1] + 1);
	}

	int ans = min_element(res, res + n) - res;
	cout << res[ans] + 1 << " " << ans << "\n";
}