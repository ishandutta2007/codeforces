#include <bits/stdc++.h>

typedef long long ll;

const int P = 998244353;

int norm(int x) {if (x >= P) x -= P; return x;}
int reduce(int x) {if (x < 0) x += P; return x;}
void add(int &x, int y) {if ((x += y) >= P) x -= P;}
void sub(int &x, int y) {if ((x -= y) < 0) x += P;}
int mpow(int b, int p) {
	int r = 1;
	for (; p; p >>= 1, b = (ll)b * b % P)
		if (p & 1) r = (ll)r * b % P;
	return r;
}

int k, s, c;

int iv[20];
void pexp(int *f) {
	assert (f[0] == 0);
	
	static int t[20];
	for (int i = 0; i <= k; i++) t[i] = f[i], f[i] = 0;
	
	f[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < i; j++)
			add(f[i], (ll)f[j] * t[i - j] % P * (i - j) % P);
		f[i] = (ll)f[i] * iv[i] % P;
	}
}
void plog(int *f) {
	assert (f[0] == 1);

	static int t[20];
	for (int i = 0; i <= k; i++) t[i] = f[i], f[i] = 0;
	
	f[0] = 0;
	for (int i = 1; i <= k; i++) {
		f[i] = (ll)i * t[i] % P;
		for (int j = 1; j < i; j++)
			sub(f[i], (ll)t[j] * f[i - j] % P * (i - j) % P);
		f[i] = (ll)f[i] * iv[i] % P;
	}
}
void ifwt(int *a, int n) {
	for (int j = 1; j < n; j <<= 1)
		for (int i = 0, t; i < n; i++) if (i & j)
			t = a[i], a[i] = reduce(a[i ^ j] - t), add(a[i ^ j], t);
	
	int ivn = mpow(n, P - 2);
	for (int i = 0; i < n; i++)
		a[i] = (ll)a[i] * ivn % P;
}

int lg[1 << 16], fct[20], ifct[20], bt[1 << 16];
void init() {
	iv[1] = 1;
	for (int i = 2; i <= k; i++)
		iv[i] = reduce(0 - (ll)iv[P % i] * (P / i) % P);

	fct[0] = ifct[0] = 1;
	for (int i = 1; i <= k; i++)
		ifct[i] = mpow(fct[i] = (ll)fct[i - 1] * i % P, P - 2);
	
	for (int i = 0; i < c; i++) lg[1 << i] = i;
	for (int i = 1; i < s || i < 32; i++) bt[i] = bt[i >> 1] ^ (i & 1);
}

int f[1 << 16][20], sgn[1 << 16];

int a[16][16], b[16];

int g[32][20], h[20], sgn1[32];
void calc_b() {
	for (int p = 0; p < 16; p++) {
		for (int j = 0; j <= k; j++)
			g[p][j] = 0;
		sgn1[p] = 0;
	}
	
	for (int i = k; i < 16; i++) {
		for (int p = 0; p < 16; p++) {
			for (int j = 0; j <= k; j++)
				h[j] = bt[(i - j) & p] ? reduce(0 - ifct[j]) : ifct[j];
			if (h[0] == P - 1) {
				for (int j = 0; j <= k; j++)
					h[j] = reduce(0 - h[j]);
				sgn1[p] ^= (b[i] & 1);
			}
			plog(h);
			
			for (int j = 0; j <= k; j++)
				add(g[p][j], (ll)b[i] * h[j] % P);
		}
	}
	
	for (int i = 0; i < s; i++) {
		int p = i & 15;
		for (int j = 0; j <= k; j++)
			add(f[i][j], g[p][j]);
		sgn[i] ^= sgn1[p];
	}
}
void calc_a(int x) {
	for (int p = 0; p < 32; p++) {
		for (int j = 0; j <= k; j++)
			g[p][j] = 0;
		sgn1[p] = 0;
	}
	
	for (int i = 0; i < k; i++) {
		for (int p = 0; p < 32; p++) {
			for (int j = 0; j <= i; j++)
				h[j] = bt[(i - j) & p] ? reduce(0 - ifct[j]) : ifct[j];
			for (int j = i + 1; j <= k; j++)
				h[j] = bt[((j - i - 1) | 16) & p] ? reduce(0 - ifct[j]) : ifct[j];
			if (h[0] == P - 1) {
				for (int j = 0; j <= k; j++)
					h[j] = reduce(0 - h[j]);
				sgn1[p] ^= (a[x][i] & 1);
			}
			plog(h);
			
			for (int j = 0; j <= k; j++)
				add(g[p][j], (ll)a[x][i] * h[j] % P);
		}
	}
	
	int m = (1 << (x + 1)) - 1;
	for (int i = 0; i < s; i++) {
		int p = (i & 15) | (bt[i & m] << 4);
		for (int j = 0; j <= k; j++)
			add(f[i][j], g[p][j]);
		sgn[i] ^= sgn1[p];
	}
}

int ans[1 << 16], mask, n;
int main() {
	scanf("%d%d%d", &n, &k, &c), s = (1 << c), init();
	for (int i = 0, x, y; i < n; i++) {
		scanf("%d", &x), y = (x & 15), x ^= y;
		
		mask ^= x;
		if (y >= k) b[y]++;
		else a[lg[x & -x]][y]++;
	}
	
	calc_b();
	for (int i = 4; i < c; i++)
		calc_a(i);
	
	for (int i = 0; i < s; i++) {
		pexp(f[i]);
		if (sgn[i]) ans[i] = reduce(0 - f[i][k]);
		else ans[i] = f[i][k];
	}
	ifwt(ans, s);
	
	int coef = (ll)fct[k] * mpow(n, (P - 1) - k) % P;
	for (int i = 0; i < s; i++)
		printf("%lld ", (ll)ans[i ^ mask] * coef % P);
	puts("");
}