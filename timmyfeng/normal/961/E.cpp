#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

int a[MX], n;

struct node {
	int mn, ndx, cnt;
} st[MX * 2];

node combine(node a, node b) {
	return {min(a.mn, b.mn), a.mn < b.mn ? a.ndx : b.ndx, a.cnt + b.cnt};
}

void upd(int a, node val) {
	a += n - 1;
	st[a] = val;
	for (a /= 2; a; a /= 2) {
		st[a] = combine(st[a * 2], st[a * 2 + 1]);
	}
}

node qry(int a, int b) {
	node res = {n + 1, -1, 0};
	for (a += n - 1, b += n - 1; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			res = combine(res, st[a++]);
		}
		if (b % 2 == 0) {
			res = combine(res, st[b--]);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = min(n, a[i]);
		upd(i, {a[i], i, 1});
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= i)
			continue;
		node res = qry(i + 1, a[i]);
		while (res.mn < i) {
			upd(res.ndx, {n + 1, -1, 0});
			res = qry(i + 1, a[i]);
		}
		ans += res.cnt;
	}

	cout << ans << '\n';
}