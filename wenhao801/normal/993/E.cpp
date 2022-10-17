#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

#define double long double

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
const int MAXN = 1100100;
const double pi = 3.14159265358979323846;

struct C {
	double a, b;
	C (double x = 0, double y = 0) { a = x, b = y; }
	C operator + (const C &x) const { return C(a + x.a, b + x.b); }
	C operator - (const C &x) const { return C(a - x.a, b - x.b); }
	C operator * (const C &x) const { return C(a * x.a - b * x.b, a * x.b + b * x.a); }
} F[MAXN], G[MAXN];
int N, M;

int rev[MAXN] = {};

void fft (C *f, int t) {
	int i, j, k;
	for (i = 0; i < N; i++) if (i < rev[i]) swap(f[i], f[rev[i]]);
	for (i = 2; i <= N; i <<= 1) {
		C nex = C(cos(pi * 2 / i), sin(pi * 2 / i) * t);
		for (j = 0; j < N; j += i) {
			C now = C(1, 0);
			for (k = j; k < j + (i >> 1); k++) {
				C tmp = now * f[k + (i >> 1)]; // now * fr
				f[k + (i >> 1)] = f[k] - tmp; // fl - now * fr
				f[k] = f[k] + tmp; // fl + now * fr
				now = now * nex;
			}
		}
	}
}

int n, m, X, p[MAXN]; ll f[MAXN];

int main () {
	n = read(), X = read();
    int i, j;
    for (i = 1; i <= n; i++) {
        j = read();
        if (j < X) p[++m] = i;
    }
    p[++m] = n + 1;
    // for (i = 1; i <= m; i++) cout << p[i] << ' '; cout << endl;
    for (i = 1; i <= m; i++) F[m - i].a = p[i], G[i].a = p[i] - p[i - 1];
    for (N = 1; N < (m << 1); N <<= 1);

	for (i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? (N >> 1) : 0);
	fft(F, 1); fft(G, 1);
	for (i = 0; i < N; i++) F[i] = F[i] * G[i]; fft(F, -1);
	for (i = 1; i <= m; i++) f[i] = (ll)(F[m + i].a / N + 0.49);
    f[0] = 1ll * n * (n + 1) / 2;
    for (i = 0; i <= n; i++) printf("%lld ", f[i] - f[i + 1]);
	return 0;
}