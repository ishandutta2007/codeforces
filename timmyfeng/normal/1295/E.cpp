#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

ll st[MX * 4], la[MX * 4];
int a[MX], p[MX], pos[MX], n;

void push(int v) {
	st[v * 2] += la[v];
	la[v * 2] += la[v];
	st[v * 2 + 1] += la[v];
	la[v * 2 + 1] += la[v];
	la[v] = 0;
}

void upd(int a, int b, int val, int v = 1, int l = 0, int r = n - 2) {
	if (r < a || b < l)
		return;
	if (a <= l && r <= b) {
		st[v] += val;
		la[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, val, v * 2, l, m);
		upd(a, b, val, v * 2 + 1, m + 1, r);
		st[v] = min(st[v * 2], st[v * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		upd(i, n - 1, a[i]);
	}

	ll ans = st[1];
	for (int i = 1; i <= n; ++i) {
		upd(pos[i], n - 1, -a[pos[i]]);
		upd(0, pos[i] - 1, a[pos[i]]);
		ans = min(ans, st[1]);
	}
	
	cout << ans << '\n';
}