#include <bits/stdc++.h>

typedef long long ll;

const int N = 300000;
const int P = int(1E9) + 7;

inline int norm(int x) {if (x >= P) x -= P; return x;}
inline int reduce(int x) {if (x < 0) x += P; return x;}
inline void add(int &x, int y) {if ((x += y) >= P) x -= P;}
inline void sub(int &x, int y) {if ((x -= y) < 0) x += P;}
int mpow(int b, int p) {
	int r = 1;
	for (; p; p >>= 1, b = (ll)b * b % P)
		if (p & 1) r = (ll)r * b % P;
	return r;
}

int fct[N + 5], ifct[N + 5];
int comb(int n, int m) {
	assert (n >= 0);
	if (n < m || m < 0) return 0;
	else return (ll)fct[n] * ifct[m] % P * ifct[n - m] % P;
}
void init() {
	fct[0] = 1; for (int i = 1; i <= N; i++) fct[i] = (ll)fct[i - 1] * i % P;
	ifct[N] = mpow(fct[N], P - 2);
	for (int i = N - 1; i >= 0; i--) ifct[i] = (ll)ifct[i + 1] * (i + 1) % P;
}

int n, k;
void solve() {
	scanf("%d%d", &n, &k);

	int ans = 0;
	for (int i = 0; k * i <= n + k - 1; i++)
		ans = (ans + (ll)comb(n + k - 1 - k * i + i, i) * mpow(comb(n, i), P - 2)) % P;
	printf("%d\n", ans);
}

int main() {
	init();

	int t; scanf("%d", &t);
	while (t--) solve();
}