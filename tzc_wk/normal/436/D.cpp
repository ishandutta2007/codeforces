// Created time: 2022/6/15 10:01:20
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
int n, m, k;
namespace SOL {
const int MAXN = 1e5;
const int MAXM = 5e3;
const int MAXV = 1e7;
int a[MAXN + 5], l[MAXN + 5], r[MAXN + 5], b[MAXM + 5], sum[MAXV + 5];
int tot, bel[MAXV + 5], f[MAXN + 5], g[MAXN + 5];
int main() {
	for (int i = 1; i <= k; i++) scanf("%d", &a[i]); sort(a + 1, a + k + 1);
	for (int L = 1, R; L <= k; L = R + 1) {
		R = L; while (R < k && a[R + 1] == a[R] + 1) ++R;
		l[++n] = a[L]; r[n] = a[R];
	}
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), sum[b[i]]++; sort(b + 1, b + m + 1);
	for (int i = 1; i <= MAXV; i++) sum[i] += sum[i-1];
	for (int i = 1; i <= n; i++) for (int j = l[i]; j <= r[i]; j++)
		bel[++tot] = i;
	int ss = 0;
	for (int i = 1; i <= n; i++) {
		g[i] = max(g[i], f[i - 1] + sum[r[i]] - sum[l[i] - 1]);
		ss += r[i] - l[i] + 1;
		for (int j = lower_bound(b + 1, b + m + 1, r[i] + 1 - ss) - b; j <= m && b[j] < l[i]; j++)
			chkmax(g[i], f[bel[ss - r[i] + b[j]] - 1] + sum[r[i]] - sum[b[j] - 1]);
		chkmax(f[i], g[i]);
		for(int j = upper_bound(b + 1, b + m + 1, tot - ss + r[i]) - b - 1; j && b[j] >= r[i]; j--)
			chkmax(f[bel[ss + b[j] - r[i]]], g[i] + sum[b[j]] - sum[r[i]]);
	}
	printf("%d\n", f[n]);
	return 0;
}
}
const int MAXN = 1100;
const int MAXV = 1e7;
int a[MAXN + 5], dp[MAXN + 5], sum[MAXV + 5], l[MAXN + 5], r[MAXN + 5];
int main() {
	scanf("%d%d", &k, &m);
	if (k > 1100) return SOL :: main();
	for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
	sort(a + 1, a + k + 1);
	for (int L = 1, R; L <= k; L = R + 1) {
		R = L; while (R < k && a[R + 1] == a[R] + 1) ++R;
		l[++n] = a[L]; r[n] = a[R];
	}
	for (int i = 1, x; i <= m; i++) scanf("%d", &x), sum[x]++;
	for (int i = 1; i <= MAXV; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= n; i++) for (int j = 0; j < i; j++) {
		int L = 0, R = 0;
		for (int k = j + 1; k <= i; k++) R += r[k] - l[k] + 1;
		for (int k = j + 1; k <= i; k++) {
			R -= r[k] - l[k] + 1;
			int _l = l[k] - L, _r = r[k] + R;
			chkmax(dp[i], dp[j] + sum[_r] - sum[_l - 1]);
			L += r[k] - l[k] + 1;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}