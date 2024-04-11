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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
const int MAXN = 2000;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int s[MAXN + 5][MAXN + 5], fac[MAXN + 5], inv[MAXN + 5];
void init_fac(int n) {
	for (int i = (s[0][0] = fac[0] = 1); i <= n; i++) {
		for (int j = 1; j <= i; j++) s[i][j] = (s[i - 1][j - 1] + 1ll * j * s[i - 1][j]) % MOD;
		fac[i] = 1ll * fac[i - 1] * i % MOD;
	}
	for (int i = (inv[0] = inv[1] = 1) + 1; i <= n; i++) inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	init_fac(MAXN); int qu; scanf("%d", &qu);
	while (qu--) {
		int n, m, k, res = 0, C = 1; scanf("%d%d%d", &n, &m, &k);
		int pw1 = 1, pw2 = qpow(m, n), iv = qpow(m, MOD - 2);
		for (int i = 0; i <= min(k, n); i++) {
			res = (res + 1ll * s[k][i] * pw1 % MOD * pw2 % MOD * C % MOD * fac[i]) % MOD;
			C = 1ll * C * (n - i) % MOD * inv[i + 1] % MOD;
			pw1 = 1ll * pw1 * (m + 1 >> 1) % MOD; pw2 = 1ll * pw2 * iv % MOD;
		}
		printf("%d\n", res);
	}
	return 0;
}