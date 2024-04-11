#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;
const int P = 998244353;

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

int fct[N + 5], ifct[N + 5], pw2[N + 5], ipw2[N + 5];
int binom(int n, int m) {
	if (n < m || m < 0) return 0;
	else return (ll)fct[n] * ifct[m] % P * ifct[n - m] % P;
}
void init() {
	fct[0] = 1;
	for (int i = 1; i <= N; i++) fct[i] = (ll)fct[i - 1] * i % P;
	ifct[N] = mpow(fct[N], P - 2);
	for (int i = N; i >= 1; i--) ifct[i - 1] = (ll)ifct[i] * i % P;
	pw2[0] = 1;
	for (int i = 1; i <= N; i++) pw2[i] = norm(pw2[i - 1] << 1);
	ipw2[N] = mpow(2, P - 1 - N);
	for (int i = N; i >= 1; i--) ipw2[i - 1] = norm(ipw2[i] << 1);
}

struct node{
	int a, b, s;
	void inc_a() {
		sub(s, binom(b, -a)), a++;
	}
	void dec_a() {
		a--, add(s, binom(b, -a));
	}
	void inc_b() {
		s = reduce(norm(s << 1) - binom(b, -a)), b++;
	}
	void dec_b() {
		b--, s = (ll)(s + binom(b, -a)) * ipw2[1] % P;
	}
}p;

int query() {
/*
	int ret = 0;
	for (int i = (a & 1); i <= b; i += 2) {
		ret = (ret + (ll)a * binom(b, i)) % P;
		// ret = (ret + (ll)i * binom(b, i)) % P;
		ret = (ret + (ll)b * binom(b - 1, i - 1)) % P;
	}
	int del = 0;
	for (int i = (a & 1); i <= -a; i += 2) {
		del = (del + (ll)(P + a) * binom(b, i)) % P;
		// del = (del + (ll)i * binom(b, i)) % P;
		del = (del + (ll)b * binom(b - 1, i - 1)) % P;
	}
	sub(ret, norm(del << 1));
*/
	int ret = 0;
	if (p.b) {
		add(ret, (ll)(P + p.a) * pw2[p.b] % P);
		sub(ret, (ll)(P + p.a) * norm(p.s << 1) % P);
		add(ret, (ll)(p.b + 1) * pw2[p.b - 1] % P);
		p.inc_a(), p.dec_b();
		sub(ret, (ll)(p.b + 2) * norm(p.s << 1) % P);
		p.dec_a(), p.inc_b();
	} else {
		ret = std::abs(p.a + (p.a & 1));
	}
	return (ll)ret * ipw2[p.b + 1] % P;
}

char str[N + 5], op[2];
int main() {
	init();

	int n, m; scanf("%d%d%s", &n, &m, str + 1);
	p = (node){0, 0, 1};
	for (int i = 1; i <= n; i++) {
		if (str[i] == 'w') {
			if (i & 1) p.dec_a(); else p.inc_a();
		} else if (str[i] == '?') {
			if (i & 1) p.dec_a(); p.inc_b();
		}
	}
	p.dec_b();
	
	printf("%d\n", query());
	for (int j = 1, i; j <= m; j++) {
		scanf("%d%s", &i, op);
		if (str[i] == 'w') {
			if (i & 1) p.inc_a(); else p.dec_a();
		} else if (str[i] == '?') {
			if (i & 1) p.inc_a(); p.dec_b();
		}
		str[i] = op[0];
		if (str[i] == 'w') {
			if (i & 1) p.dec_a(); else p.inc_a();
		} else if (str[i] == '?') {
			if (i & 1) p.dec_a(); p.inc_b();
		}
		printf("%d\n", query());
	}
}