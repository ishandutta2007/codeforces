#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;
const int INF = 1e9;

pair<int, int> seg_tree[MX * 4];
int lazy[MX * 4];

void push(int v) {
	for (int i = 0; i < 2; ++i) {
		seg_tree[v * 2 + i].first += lazy[v];
		lazy[v * 2 + i] += lazy[v];
	}
	lazy[v] = 0;
}

void bld(int v, int l, int r) {
	if (l == r) {
		seg_tree[v].second = -l;
	} else {
		int m = (l + r) / 2;
		bld(v * 2, l, m);
		bld(v * 2 + 1, m + 1, r);
		seg_tree[v] = min(seg_tree[v * 2], seg_tree[v * 2 + 1]);
	}
}

void upd(int a, int b, int val, int v = 1, int l = 1, int r = MX) {
	if (b < l || r < a) {
		return;
	} else if (a <= l && r <= b) {
		seg_tree[v].first += val;
		lazy[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, val, v * 2, l, m);
		upd(a, b, val, v * 2 + 1, m + 1, r);
		seg_tree[v] = min(seg_tree[v * 2], seg_tree[v * 2 + 1]);
	}
}

pair<int, int> qry(int a, int b, int v = 1, int l = 1, int r = MX) {
	if (b < l || r < a) {
		return {INF, INF};
	} else if (a <= l && r <= b) {
		return seg_tree[v];
	} else {
		push(v);
		int m = (l + r) / 2;
		return min(qry(a, b, v * 2, l, m),
				qry(a, b, v * 2 + 1, m + 1, r));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	bld(1, 1, MX);

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
		upd(i, MX, 1);
	}

	vector<int> b(m);
	for (auto& i : b) {
		cin >> i;
		upd(i, MX, -1);
	}

	int q;
	cin >> q;
	while (q--) {
		int t, i, x;
		cin >> t >> i >> x;
		--i;

		if (t == 1) {
			upd(a[i], MX, -1);
			a[i] = x;
			upd(a[i], MX, 1);
		} else {
			upd(b[i], MX, 1);
			b[i] = x;
			upd(b[i], MX, -1);
		}

		int lb = 0;
		int rb = MX - 1;
		while (lb <= rb) {
			int mb = (lb + rb) / 2;
			if (qry(mb, MX).first == qry(MX, MX).first) {
				rb = mb - 1;
			} else {
				lb = mb + 1;
			}
		}
		cout << (lb ? lb : -1) << "\n";
	}
}