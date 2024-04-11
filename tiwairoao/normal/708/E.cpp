#include <bits/stdc++.h>

typedef long long ll;

const int N = 1500;
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

int n, m, a, b, p, k;

int c[N + 5], s[N + 5], s1;
void init() {
	if (p == 1) { // attention to it !!!
		if (k < m) c[k] = 1;
	} else {
		int t = mpow(P + 1 - p, k);
		for (int i = 0; i < m; i++) {
			c[i] = t;
			t = (ll)t * (k - i) % P * p % P *
				mpow((ll)(P + 1 - p) * (i + 1) % P, P - 2) % P;
			if (!t) break;
		}
	}

	s[0] = c[0];
	for (int i = 1; i < m; i++) s[i] = norm(s[i - 1] + c[i]);
	for (int i = 0; i < m; i++) s1 = (s1 + (ll)s[i] * c[m - 1 - i]) % P;
}

int solve() {
	static int f[N + 5], t[N + 5]; int g = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m - 1; j >= 0; j--) add(f[j], f[j + 1]);
		for (int j = 0; j < m; j++) t[j] = (ll)(P - f[m - j]) * c[j] % P;
		for (int j = 0; j < m; j++)
			f[j] = (((ll)g * c[j] + t[j]) % P * s[m - 1 - j]) % P;
		
		g = (ll)g * s1 % P;
		for (int j = 0; j < m; j++) g = (g + 2ll * t[j] * s[m - 1 - j]) % P;
		for (int j = 1; j < m; j++) add(t[j], t[j - 1]);
		for (int j = 0; j < m; j++) f[j] = (f[j] + (ll)t[m - 1 - j] * c[j]) % P;
	}
	return g;
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
	p = (ll)a * mpow(b, P - 2) % P, init();
	printf("%d\n", solve());
}