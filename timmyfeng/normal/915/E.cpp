#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;

int l[MX], r[MX], k[MX], ps[MX], m;
int seg_tree[MX * 4], lazy[MX * 4];

void push(int v, int l, int r) {
	if (!lazy[v])
		return;

	int m = (l + r) / 2;
	lazy[v * 2] = lazy[v];
	lazy[v * 2 + 1] = lazy[v];

	if (lazy[v] == 1) {
		seg_tree[v * 2] = 0;
		seg_tree[v * 2 + 1] = 0;
	} else if (lazy[v] == 2) {
		seg_tree[v * 2] = ps[m] - ps[l - 1];
		seg_tree[v * 2 + 1] = ps[r] - ps[m];
	}
	lazy[v] = 0;
}

void upd(int a, int b, int type, int v = 1, int l = 1, int r = m - 1) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		seg_tree[v] = type == 2 ? ps[r] - ps[l - 1] : 0;
		lazy[v] = type;
	} else {
		push(v, l, r);
		int m = (l + r) / 2;
		upd(a, b, type, v * 2, l, m);
		upd(a, b, type, v * 2 + 1, m + 1, r);
		seg_tree[v] = seg_tree[v * 2] + seg_tree[v * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> vals;
	for (int i = 0; i < q; ++i) {
		cin >> l[i] >> r[i] >> k[i];
		++r[i];
		vals.push_back(l[i]);
		vals.push_back(r[i]);
	}

	vals.push_back(1);
	vals.push_back(n + 1);
	sort(vals.begin(), vals.end());
	m = unique(vals.begin(), vals.end()) - vals.begin();

	map<int, int> ndx;
	for (int i = 0; i < m; ++i) {
		ps[i] = i ? ps[i - 1] + vals[i] - vals[i - 1] : 0;
		ndx[vals[i]] = i + 1;
	}

	seg_tree[1] = n;
	lazy[1] = 2;

	for (int i = 0; i < q; ++i) {
		upd(ndx[l[i]], ndx[r[i]] - 1, k[i]);
		cout << seg_tree[1] << '\n';
	}
}