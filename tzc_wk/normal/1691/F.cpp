// Created time: 2022/6/22 13:08:46
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
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
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
const int MAXN = 2e5;
const int MOD = 1e9 + 7;
int fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int binom(int n, int k) {
	if (n < k) return 0;
	return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
int n, k, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int fa[MAXN + 5], siz[MAXN + 5], res = 0;
void dfs(int x, int f) {
	fa[x] = f; siz[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs(y, x); siz[x] += siz[y];
	}
}
int main() {
	scanf("%d%d", &n, &k); init_fac(MAXN);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int e = hd[i]; e; e = nxt[e]) {
			int j = to[e];
			if (j == fa[i]) sum = (sum + binom(n - siz[i], k)) % MOD;
			else sum = (sum + binom(siz[j], k)) % MOD;
		}
		for (int e = hd[i]; e; e = nxt[e]) {
			int j = to[e];
			if (j == fa[i]) {
				sum = (sum - binom(n - siz[i], k) + MOD) % MOD;
				int A = n - siz[i];
				res = (res + 1ll * (n - A) * A % MOD * (binom(n - A, k) - sum + MOD)) % MOD;
				sum = (sum + binom(n - siz[i], k)) % MOD;
			} else {
				sum = (sum - binom(siz[j], k) + MOD) % MOD;
				int A = siz[j];
				res = (res + 1ll * (n - A) * A % MOD * (binom(n - A, k) - sum + MOD)) % MOD;
				sum = (sum + binom(siz[j], k)) % MOD;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int sum = binom(n, k);
		for (int e = hd[i]; e; e = nxt[e]) {
			int j = to[e];
			if (j == fa[i]) sum = (sum - binom(n - siz[i], k) + MOD) % MOD;
			else sum = (sum - binom(siz[j], k) + MOD) % MOD;
		}
		res = (res + 1ll * n * sum) % MOD;
	}
	printf("%d\n", res);
	return 0;
}