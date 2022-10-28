#include <bits/stdc++.h> 
using namespace std;

const int MX = 3e5 + 1;

int st[4 * MX], la[4 * MX], p[MX], q[MX], pos[MX], n;

void push(int v) {
	st[v * 2] += la[v];
	la[v * 2] += la[v];
	st[v * 2 + 1] += la[v];
	la[v * 2 + 1] += la[v];
	la[v] = 0;
}

void upd(int a, int b, int val, int v = 1, int l = 1, int r = n) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		st[v] += val;
		la[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, val, v * 2, l, m);
		upd(a, b, val, v * 2 + 1, m + 1, r);
		st[v] = max(st[v * 2], st[v * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
	}

	int cur = n;
	upd(1, pos[n], 1);
	for (int i = 1; i <= n; ++i) {
		cout << cur << ' ';
		upd(1, q[i], -1);
		while (cur && st[1] <= 0) {
			upd(1, pos[--cur], 1);
		}
	}
	cout << '\n';
}