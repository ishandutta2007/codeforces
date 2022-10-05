// Created time: 2022/4/27 9:38:03
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
const int MAXN = 1e5;
const int LOG_V = 21;
const int MAXK = 2000;
const int MOD = 1e9 + 7;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, m, k, s, val[LOG_V + 2]; pii p[MAXK + 5];
int fac[MAXN * 2 + 5], ifac[MAXN * 2 + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int calc(int x, int y) {return 1ll * fac[x + y] * ifac[x] % MOD * ifac[y] % MOD;}
int dp[MAXK + 5][LOG_V + 2];
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &s); init_fac(MAXN * 2);
	for (int i = 1; i <= k; i++) scanf("%d%d", &p[i].fi, &p[i].se);
	sort(p + 1, p + k + 1); p[0] = mp(1, 1); p[++k] = mp(n, m);
	dp[0][0] = 1;
	for (int i = 0; i <= k; i++) for (int j = 0; j <= LOG_V; j++) if (dp[i][j]) {
		for (int l = i + 1; l <= k; l++) if (p[i].fi <= p[l].fi && p[i].se <= p[l].se) {
			if (l != k) dp[l][j] = (dp[l][j] - 1ll * dp[i][j] * calc(p[l].fi - p[i].fi, p[l].se - p[i].se) % MOD + MOD) % MOD;
			dp[l][min(j + 1, LOG_V)] = (dp[l][min(j + 1, LOG_V)] + 1ll * dp[i][j] * calc(p[l].fi - p[i].fi, p[l].se - p[i].se)) % MOD;
		}
	}
	val[0] = s;
	for (int i = 1; i <= LOG_V; i++) val[i] = val[i - 1] + 1 >> 1;
	int res = 0;
	for (int i = 1; i <= LOG_V; i++) res = (res + 1ll * val[i - 1] * dp[k][i]) % MOD;
	printf("%d\n", 1ll * res * qpow(calc(n - 1, m - 1), MOD - 2) % MOD);
	return 0;
}