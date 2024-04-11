// Created time: 2022/7/28 8:25:16
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
const int MAXN = 1e5;
const int LOG_N = 17;
int n, qu, a[MAXN + 5], lg[MAXN + 5];
struct itvl {
	int l, r;
	itvl() {l = r = 0;}
	itvl(int _l, int _r) {l = _l; r = _r;}
	friend itvl operator + (const itvl &X, const itvl &Y) {
		return itvl(min(X.l, Y.l), max(X.r, Y.r));
	}
	bool check() {return l == 1 && r == n;}
};
itvl st[LOG_N * 2 + 2][LOG_N + 2][MAXN + 5];
itvl query(int k, int l, int r) {
	if (l >= r) return itvl(n, 1); --r; int b = lg[r - l + 1];
	return st[k][b][l] + st[k][b][r - (1 << b) + 1];
}
int main() {
	for (int i = 2; i <= MAXN; i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i <= LOG_N * 2; i++) {
		for (int j = 1; j < n; j++) {
			if (i) st[i][0][j] = query(i - 1, st[i - 1][0][j].l, st[i - 1][0][j].r);
			else st[i][0][j] = itvl(min(a[j], a[j + 1]), max(a[j], a[j + 1]));
		}
		for (int j = 1; j <= LOG_N; j++) for (int k = 1; k + (1 << j) - 1 <= n; k++)
			st[i][j][k] = st[i][j - 1][k] + st[i][j - 1][k + (1 << j - 1)];
	}
	while (qu--) {
		int l, r; scanf("%d%d", &l, &r); ll res = 0; itvl tmp;
		if (l == 1 && r == n) {puts("0"); continue;}
		for (int i = LOG_N * 2; ~i; i--) if (!(tmp = query(i, l, r)).check())
			l = tmp.l, r = tmp.r, res += 1ll << i;
		tmp = itvl(l, r);
		if (!tmp.check()) tmp = query(0, l, r), res++;
		if (!tmp.check()) puts("-1");
		else printf("%lld\n", res);
	}
	return 0;
}