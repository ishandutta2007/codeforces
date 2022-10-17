#include <bits/stdc++.h>
using namespace std;
int n, a[200020];
int tt, t[200020 * 30][2];
long long ans;
void ins(int x) {
	int p = 0;
	for (int i = 29; i >= 0; i--) {
		if (t[p][x >> i & 1] == 0) {
			t[p][x >> i & 1] = ++tt;
		}
		p = t[p][x >> i & 1];
	}
}
int ask(int x) {
	int p = 0, re = 0;
	for (int i = 29; i >= 0; i--) {
		if (t[p][x >> i & 1] == 0) {
			p = t[p][~x >> i & 1];
			re += 1 << i; 
		} else {
			p = t[p][x >> i & 1];
		}
	}
	return re;
}
void dp(int l, int r, int d, int v) {
	if (d < 0 || r - l < 2) {
		return;
	}
	int m = v + (1 << d);
	int p = lower_bound(a + l, a + r, m) - a;
	if (l != p && p != r) {
		while (tt-- > 0) {
			t[tt][0] = t[tt][1] = 0;
		}
		tt = 0;
		int u = 1 << 30;
		for (int i = l; i < p; i++) {
			ins(a[i]);
		}
		for (int i = p; i < r; i++) {
			u = min(u, ask(a[i] - (1 << d)));
		}
		ans += u;
		ans += (1 << d);
	}
	dp(l, p, d - 1, v);
	dp(p, r, d - 1, m);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	dp(0, n, 29, 0);
	cout << ans << endl;
	return 0;
}