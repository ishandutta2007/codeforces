// Created time: 2022/7/29 16:50:10
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
const int MAXN = 3e5;
const int LOG_N = 20;
int opt, n, qu, a[3][MAXN + 5], pre[3][MAXN + 5], rht[3][MAXN + 5]; ll s[3][MAXN + 5];
int st[3][LOG_N + 2][MAXN + 5], dp[MAXN + 5], pos[MAXN + 5][2], CURI;
int query(int x, int y) {
	if (x == y) return dp[x]; int id = (x < y), stp = 0;
	if (pre[id][max(x, y)] >= min(x, y)) {
		for (int i = LOG_N; ~i; i--) if (st[id][i][max(x, y)] >= min(x, y))
			((x > y) ? x : y) = st[id][i][max(x, y)], stp |= (1 << i);
	}
	if (min(x, y) < CURI) return ((max(x, y) <= pos[min(x, y)][id]) ? dp[min(x, y)] : (dp[min(x, y)] + 1)) + stp;
	else {
		int ret = dp[min(x, y)];
		if (~pre[id][max(x, y)]) chkmax(ret, ((!id) ? query(pre[id][x], y) : query(x, pre[id][y])) + 1);
		return ret + stp;
	}
}
int main() {
//	freopen("zero.in", "r", stdin);
//	freopen("zero.out", "w", stdout);
	opt = 0; scanf("%d", &n); memset(pre, -1, sizeof(pre));
	for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) a[2][i] = a[0][i] + a[1][i];
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) s[i][j] = s[i][j - 1] + a[i][j];
		map<ll, int> buc;
		for (int j = 0; j <= n; j++) {
			if (buc.count(s[i][j])) pre[i][j] = buc[s[i][j]];
			buc[s[i][j]] = j;
		}
		for (int j = 1; j <= n; j++) chkmax(pre[i][j], pre[i][j - 1]);
		for (int j = 0; j <= n; j++) st[i][0][j] = pre[i][j];
		for (int j = 1; j <= LOG_N; j++) for (int k = 0; k <= n; k++)
			st[i][j][k] = (st[i][j - 1][k] == -1) ? -1 : st[i][j - 1][st[i][j - 1][k]];
		for (int j = 1, k = 1; j <= n; j++) {
			while (k <= n && pre[i][k] < j) ++k;
			rht[i][j] = k - 1;
		}
	}
	pos[0][0] = pos[0][1] = n;
	for (int i = 1; i <= n; i++) {
		CURI = i;
		if (~pre[0][i]) chkmax(dp[i], query(pre[0][i], i) + 1);
		if (~pre[1][i]) chkmax(dp[i], query(i, pre[1][i]) + 1);
		if (~pre[2][i]) chkmax(dp[i], query(pre[2][i], pre[2][i]) + 1);
		int l = i, r = rht[0][i];
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(mid, i) == dp[i]) pos[i][0] = mid, l = mid + 1;
			else r = mid - 1;
		}
		l = i, r = rht[1][i];
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(i, mid) == dp[i]) pos[i][1] = mid, l = mid + 1;
			else r = mid - 1;
		}
	}
	CURI = n + 1; ll sum = 0;
	if (opt) {
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
			sum += query(i, j);
		printf("%lld\n", sum);
	}
	printf("%d\n", query(n, n));
	return 0;
}