#include <bits/stdc++.h> 
using namespace std;

const int MX = 3e5;
const int M = 1e9 + 7;

int inv2[MX * 2], pre[MX], rem[MX], p[MX], x[MX], ndx[MX * 2], m;
array<int, 2> vals[MX * 2];
array<int, 4> st[MX * 8];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

array<int, 4> combine(array<int, 4> a, array<int, 4> b) {
	return {
			add(mul(a[0], inv2[b[2]]), b[0]),
			add(a[1], mul(b[1], inv2[a[2]])),
			a[2] + b[2],
			add(mul(a[0], b[1]), add(a[3], b[3]))
	};
}

void upd(int a, array<int, 4> val, int v = 1, int l = 0, int r = m - 1) {
	if (l == r) {
		st[v] = val;
	} else {
		int m = (l + r) / 2;
		if (a <= m) {
			upd(a, val, v * 2, l, m);
		} else {
			upd(a, val, v * 2 + 1, m + 1, r);
		}
		st[v] = combine(st[v * 2], st[v * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	inv2[0] = 1;
	inv2[1] = (M + 1) / 2;
	for (int i = 2; i < MX * 2; ++i) {
		inv2[i] = mul(inv2[i - 1], inv2[1]);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		pre[i] = i;
		vals[i] = {p[i], i};
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a;
		cin >> a >> x[i];
		rem[i] = pre[--a];
		pre[a] = n + i;
		vals[n + i] = {x[i], n + i};
	}

	m = n + q;
	sort(vals, vals + m);
	for (int i = 0; i < m; ++i) {
		ndx[vals[i][1]] = i;
	}

	for (int i = 0; i < n; ++i) {
		upd(ndx[i], {mul(p[i], inv2[1]), mul(p[i], inv2[1]), 1, 0});
	}
	cout << st[1][3] << '\n';

	for (int i = 0; i < q; ++i) {
		upd(ndx[rem[i]], array<int, 4>());
		upd(ndx[n + i], {mul(x[i], inv2[1]), mul(x[i], inv2[1]), 1, 0});
		cout << st[1][3] << '\n';
	}
}