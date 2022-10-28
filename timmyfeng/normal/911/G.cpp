#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
const int MXA = 101;

short seg_tree[MX * 4][MXA], a[MX];
int n;

void push(int v) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j < MXA; ++j) {
			seg_tree[v * 2 + i][j] = seg_tree[v][seg_tree[v * 2 + i][j]];
		}
	}
	iota(seg_tree[v], seg_tree[v] + MXA, 0);
}

void bld(int v, int l, int r) {
	iota(seg_tree[v], seg_tree[v] + MXA, 0);
	if (l != r) {
		int m = (l + r) / 2;
		bld(v * 2, l, m);
		bld(v * 2 + 1, m + 1, r);
	}
}

void upd(int a, int b, int x, int y, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		for (int i = 1; i < MXA; ++i) {
			if (seg_tree[v][i] == x) {
				seg_tree[v][i] = y;
			}
		}
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, x, y, v * 2, l, m);
		upd(a, b, x, y, v * 2 + 1, m + 1, r);
	}
}

void traverse(int v, int l, int r) {
	if (l == r) {
		a[l] = seg_tree[v][a[l]];
	} else {
		push(v);
		int m = (l + r) / 2;
		traverse(v * 2, l, m);
		traverse(v * 2 + 1, m + 1, r);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	bld(1, 0, n - 1);

	int q;
	cin >> q;
	while (q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		upd(l - 1, r - 1, x, y);
	}

	traverse(1, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}