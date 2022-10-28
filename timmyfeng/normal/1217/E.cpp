#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

int n;

struct node {
	int mn[9];
	int sum;

	node() {
		fill(mn, mn + 9, 1e9);
		sum = 2e9;
	}

	int& operator[](int a) {
		return mn[a];
	}
} st[MX * 2];

node merge(node& a, node& b) {
	node c;
	c.sum = min(a.sum, b.sum);
	for (int i = 0; i < 9; ++i) {
		if (a[i] < 1e9 && b[i] < 1e9) {
			c.sum = min(c.sum, a[i] + b[i]);
		}
		c[i] = min(a[i], b[i]);
	}
	return c;
}

int query(int a, int b) {
	a += n;
	b += n;
	node res;
	while (a <= b) {
		if (a % 2 == 1) {
			res = merge(res, st[a++]);
		}
		if (b % 2 == 0) {
			res = merge(res, st[b--]);
		}
		a /= 2;
		b /= 2;
	}
	return res.sum;
}

void update(int a, int val) {
	a += n;
	int v = val;
	for (int i = 0; i < 9; ++i) {
		st[a][i] = (v % 10 ? val : 1e9);
		v /= 10;
	}
	for (a /= 2; a; a /= 2) {
		st[a] = merge(st[a * 2], st[a * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		update(i, a);
	}

	while (m--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			update(a - 1, b);
		} else {
			int ans = query(a - 1, b - 1);
			cout << (ans == 2e9 ? -1 : ans) << '\n';
		}
	}
}