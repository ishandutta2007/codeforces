#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;
const int L = 2000000;

const char THE_ORDER[][2] = {
	{'L', 'D'},
	{'U', 'R'}
};

struct node{
	ll p, q, x; // t = pl + q
	friend bool operator < (const node &a, const node &b) {
		return a.q < b.q;
	}
}a[N + 5];

int ans[2][L + 5], n, l;
ll t[N + 5], x[2][N + 5];
bool check(int o) {
	a[0] = (node){0, 0, 0}, a[n + 1] = (node){-1, l, 0};
	for (int i = 1; i <= n; i++)
		a[i] = (node){t[i] / l, t[i] % l, x[o][i]};
	std::sort(a + 1, a + n + 1);

	ll le = 0, ri = l;
	for (int i = 0; i <= n; i++) {
		if (a[i].p == a[i + 1].p) {
			if (a[i + 1].x - a[i].x < 0 || a[i + 1].x - a[i].x > a[i + 1].q - a[i].q)
				return false;
		} else if (a[i].p < a[i + 1].p) {
			ll A = a[i + 1].x - a[i + 1].q - a[i].x + a[i].q, B = a[i + 1].p - a[i].p;
			if (A >= 0) le = std::max(le, (A + B - 1) / B);

			A = a[i + 1].x - a[i].x;
			if (A >= 0) ri = std::min(ri, A / B); else return false;
		} else {
			ll A = a[i].x - a[i + 1].x, B = a[i].p - a[i + 1].p;
			if (A + B - 1 >= 0) le = std::max(le, (A + B - 1) / B);

			A = a[i].x - a[i].q - a[i + 1].x + a[i + 1].q;
			if (A >= 0) ri = std::min(ri, A / B); else return false;
		}
	}
	if (le > ri) return false;
	
	ll s = 0;
	for (int i = 0; i <= n; i++) {
		ll t = (a[i + 1].x - a[i].x) - (a[i + 1].p - a[i].p) * le; s += t;
		assert (0 <= t && t <= a[i + 1].q - a[i].q);
		for (int j = a[i].q + 1; j <= a[i].q + t; j++) ans[o][j] = 1;
		for (int j = a[i].q + t + 1; j <= a[i + 1].q; j++) ans[o][j] = 0;
	}
	assert (s == le);
	return true;
}
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) {
		ll x0, y0; scanf("%lld%lld%lld", &t[i], &x0, &y0);
		if ((x0 + y0 + t[i]) & 1) {puts("NO"); return 0;}
		x[0][i] = (x0 + y0 + t[i]) >> 1, x[1][i] = (x0 - y0 + t[i]) >> 1;
	}

	if (check(0) && check(1)) {
		for (int i = 1; i <= l; i++)
			putchar(THE_ORDER[ans[0][i]][ans[1][i]]);
		puts("");
	} else {
		puts("NO");
	}	
}