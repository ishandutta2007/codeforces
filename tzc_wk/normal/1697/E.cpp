// Created time: 2022/6/22 13:32:46
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
const int MAXN = 100;
const int MOD = 998244353;
int n, x[MAXN + 5], y[MAXN + 5], mn[MAXN + 5];
int getdis(int a, int b) {return abs(x[a] - x[b]) + abs(y[a] - y[b]);}
int f[MAXN + 5], siz[MAXN + 5], E[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x ^ y) {
		f[x] = y; siz[y] += siz[x];
		E[y] += E[x];
	}
	E[y]++;
}
int cmp = 0, dp[MAXN + 5][MAXN + 5];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) {
		mn[i] = 1e9;
		for (int j = 1; j <= n; j++) if (i != j)
			chkmin(mn[i], getdis(i, j));
	}
	for (int i = 1; i <= n; i++) siz[i] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (i != j && mn[i] == mn[j] && getdis(i, j) == mn[i])
			merge(i, j);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) if (find(i) == i) {
		cmp++;
		for (int j = 0; j <= n; j++) if (dp[cmp - 1][j]) {
			int coef = 1;
			for (int k = 1; k <= siz[i]; k++) coef = 1ll * coef * (n - j - k + 1) % MOD;
			dp[cmp][j + siz[i]] = (dp[cmp][j + siz[i]] + 1ll * dp[cmp - 1][j] * coef) % MOD;
		}
		bool flg = (E[i] == siz[i] * (siz[i] - 1));
		for (int x = 1; x <= n; x++) if (find(x) == i)
			for (int y = 1; y <= n; y++) if (find(y) != i)
				flg &= (getdis(x, y) != mn[x]);
		if (flg) {
			for (int j = 0; j <= n; j++) if (dp[cmp - 1][j]) {
				dp[cmp][j + 1] = (dp[cmp][j + 1] + 1ll * (n - j) * dp[cmp - 1][j]) % MOD;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = (res + dp[cmp][i]) % MOD;
	printf("%d\n", res);
	return 0;
}