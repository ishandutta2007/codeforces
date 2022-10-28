#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

vector<int> st[MX * 4], stOth[MX * 4];
bool la[MX * 4], a[MX];
int n, m, ma, cur;

vector<int> combine(vector<int>& a, vector<int>& b) {
	vector<int> res(1 << m);
	for (int i = 0; i < (1 << m); ++i) {
		res[i] = a[b[i]];
	}
	return move(res);
}

void push(int v) {
	if (la[v]) {
		for (int c = v * 2; c < v * 2 + 2; ++c) {
			swap(st[c], stOth[c]);
			la[c] ^= true;
		}
	}
	la[v] = false;
}

void pull(int v) {
	st[v] = combine(st[v * 2], st[v * 2 + 1]);
	stOth[v] = combine(stOth[v * 2], stOth[v * 2 + 1]);
}

void qry(int a, int b, int v = 1, int l = 1, int r = n) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		cur = st[v][cur];
	} else {
		push(v);
		int m = (l + r) / 2;
		qry(a, b, v * 2 + 1, m + 1, r);
		qry(a, b, v * 2, l, m);
	}
}

void upd(int a, int b, int v = 1, int l = 1, int r = n) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		la[v] ^= true;
		swap(st[v], stOth[v]);
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, v * 2, l, m);
		upd(a, b, v * 2 + 1, m + 1, r);
		pull(v);
	}
}

void bld(int v = 1, int l = 1, int r = n) {
	if (l == r) {
		st[v].resize(1 << m);
		stOth[v].resize(1 << m);
		for (int i = 0; i < (1 << m); ++i) {
			st[v][i] = (ma & (i << 1)) ^ (i != ma);
			stOth[v][i] = (ma & (i << 1)) ^ 1;
		}
		if (!a[l]) {
			swap(st[v], stOth[v]);
		}
	} else {
		int m = (l + r) / 2;
		bld(v * 2, l, m);
		bld(v * 2 + 1, m + 1, r);
		pull(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> m >> q;
	ma = (1 << m) - 1;
	for (int i = 1; i <= n; ++i) {
		ll b;
		cin >> b;
		a[i] = b % 2;
	}
	bld();

	while (q--) {
		int t, l, r;
		cin >> t;
		if (t == 1) {
			ll d;
			cin >> l >> r >> d;
			if (d % 2) {
				upd(l, r);
			}
		} else {
			cin >> l >> r;
			cur = ma;
			qry(l, r);
			cout << ((cur & 1) ? 1 : 2) << '\n';
		}
	}
}