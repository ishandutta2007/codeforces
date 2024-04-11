// Created time: 2022/4/8 9:09:35
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
const int MOD = 1e9 + 7;
int pr[MAXN / 5 + 5], prcnt = 0, mu[MAXN + 5]; bool vis[MAXN + 5];
vector<int> fac[MAXN + 5];
void sieve(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, mu[i] = -1;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1;
			if (i % pr[j] == 0) break;
			mu[i * pr[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j += i)
		fac[j].pb(i);
}
int n, dp[MAXN + 5], prd[MAXN + 5], inv[MAXN + 5];
int main() {
	scanf("%d", &n); sieve(n);
	for (int i = (inv[0] = inv[1] = 1) + 1; i <= n; i++)
		inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 2; i <= n; i++) {
		int ss = n;
		for (int j : fac[i]) ss = (ss + 1ll * (n / j) * prd[j]) % MOD;
		dp[i] = 1ll * ss * inv[n - n / i] % MOD;
		for (int j = i; j <= n; j += i) prd[j] = (0ll + prd[j] + dp[i] * mu[j / i] + MOD) % MOD;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = (res + dp[i] + 1) % MOD;
	printf("%d\n", 1ll * res * inv[n] % MOD);
	return 0;
}