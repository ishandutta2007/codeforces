#include <bits/stdc++.h>

const int N = 400;

typedef long long ll;

int M;
int norm(int x) {if (x >= M) x -= M; return x;}
int reduce(int x) {if (x < 0) x += M; return x;}
void add(int &x, int y) {if ((x += y) >= M) x -= M;}
void sub(int &x, int y) {if ((x -= y) < 0) x += M;}
int mpow(int b, int p) {
	int r = 1;
	for (; p; p >>= 1, b = (ll)b * b % M)
		if (p & 1) r = (ll)r * b % M;
	return r;
}

int fct[N + 5], ifct[N + 5];
void init() {
	fct[0] = 1;
	for (int i = 1; i <= N; i++)
		fct[i] = (ll)fct[i - 1] * i % M;
	ifct[N] = mpow(fct[N], M - 2);
	for (int i = N - 1; i >= 0; i--)
		ifct[i] = (ll)ifct[i + 1] * (i + 1) % M;
}

int f[N + 5], g[N + 5], n;
int main() {
	scanf("%d%d", &n, &M), init();

	for (int i = 1, p = 1; i <= n; i++, p = norm(p << 1))
		f[i] = (ll)p * ifct[i] % M;

	int ans = 0; g[0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = n - i; j >= 0; j--) {
			g[j] = (ll)g[j] * f[0] % M;
			for (int k = 1; k <= j; k++)
				g[j] = (g[j] + (ll)f[k] * g[j - k]) % M;
		}
		ans = (ans + (ll)g[n - i] * fct[n - i]) % M;
	}
	printf("%d\n", ans);
}