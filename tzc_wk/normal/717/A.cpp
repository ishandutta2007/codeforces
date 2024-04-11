// Created time: 2022/4/24 16:57:39
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
const int MAXN = 200;
const int MOD = 1e9 + 7;
const int INV2 = MOD + 1 >> 1;
int k; ll l, r;
int fac[MAXN + 5], ifac[MAXN + 5], S[MAXN + 5][MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
	S[0][0] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++)
		S[i][j] = (S[i - 1][j - 1] + 1ll * (i - 1) * S[i - 1][j]) % MOD;
}
int binom(int n, int k) {return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;}
int qpow(int x, ll e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
struct comp {
	int a, b; // a + b sqrt(5)
	comp() {a = b = 0;}
	comp(int _a, int _b) {a = _a; b = _b;}
	friend comp operator + (const comp &X, const comp &Y) {return comp((X.a + Y.a) % MOD, (X.b + Y.b) % MOD);}
	friend comp operator - (const comp &X, const comp &Y) {return comp((X.a - Y.a + MOD) % MOD, (X.b - Y.b + MOD) % MOD);}
	friend comp operator * (const comp &X, const comp &Y) {
		return comp((1ll * X.a * Y.a + 5ll * X.b * Y.b) % MOD,
					(1ll * X.a * Y.b + 1ll * Y.a * X.b) % MOD);
	}
	friend comp operator / (const comp &X, const comp &Y) {
		comp Z = X * comp(Y.a, MOD - Y.b);
		int v = qpow((1ll * Y.a * Y.a - 5ll * Y.b * Y.b % MOD + MOD) % MOD, MOD - 2);
		Z.a = 1ll * Z.a * v % MOD; Z.b = 1ll * Z.b * v % MOD;
		return Z;
	}
} A(INV2, INV2), B(INV2, MOD - INV2), C(0, qpow(5, MOD - 2));
comp qpow_cmp(comp x, ll e) {
	comp ret(1, 0);
	for (; e; e >>= 1, x = x * x)
		if (e & 1) ret = ret * x;
	return ret;
}
comp getsum(comp x, ll l, ll r) {
	if (x.a == 1 && x.b == 0) return comp((r - l + 1) % MOD, 0);
	comp X = (qpow_cmp(x, r + 1) - comp(1, 0)) / (x - comp(1, 0));
	comp Y = (qpow_cmp(x, l) - comp(1, 0)) / (x - comp(1, 0));
	return X - Y;
}
int main() {
	scanf("%d%lld%lld", &k, &l, &r); l += 2; r += 2; init_fac(MAXN);
	int res = 0;
	for (int j = 0; j <= k; j++) {
		int coef = 1ll * S[k][j] % MOD * qpow(MOD - 1, k - j) % MOD;
		comp iv = qpow_cmp(C, j);
		for (int x = 0; x <= j; x++) {
			comp E = qpow_cmp(A, x) * qpow_cmp(B, j - x);
			comp val = iv * getsum(E, l, r);
			if ((j - x) & 1) res = (res - 1ll * val.a * binom(j, x) % MOD * coef % MOD + MOD) % MOD;
			else res = (res + 1ll * val.a * binom(j, x) % MOD * coef) % MOD;
		}
	}
	printf("%d\n", 1ll * res * ifac[k] % MOD);
	return 0;
}