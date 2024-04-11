// Created time: 2022/6/25 22:32:44
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
const int MAXN = 2.5e5;
int n, a[MAXN + 5], dp[MAXN + 5], pre_mn[MAXN + 5], pre_mx[MAXN + 5];
struct segtree {
	struct node {int l, r, mn;} s[MAXN * 4 + 5];
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; if (l == r) return s[k].mn = dp[l], void();
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);
	}
	void upd(int k, int p, int v) {
		if (s[k].l == s[k].r) return s[k].mn = v, void();
		int mid = s[k].l + s[k].r >> 1;
		if (p <= mid) upd(k << 1, p, v);
		else upd(k << 1 | 1, p, v);
		s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);
	}
	int query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].mn;
		int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return min(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r));
	}
} MN, MX;
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), dp[i] = 1e9;
	dp[1] = 0;
	static int stk_mn[MAXN + 5], stk_mx[MAXN + 5];
	int tp_mn = 0, tp_mx = 0;
	stk_mn[++tp_mn] = 1; stk_mx[++tp_mx] = 1;
	MN.build(1, 1, n); MX.build(1, 1, n);
	for (int i = 2; i <= n; i++) {
		while (tp_mx && a[stk_mx[tp_mx]] < a[i]) --tp_mx;
		pre_mx[i] = stk_mx[tp_mx]; stk_mx[++tp_mx] = i;
		while (tp_mn && a[stk_mn[tp_mn]] > a[i]) --tp_mn;
		pre_mn[i] = stk_mn[tp_mn]; stk_mn[++tp_mn] = i;
//		printf("%d %d %d\n", i, pre_mx[i], pre_mn[i]);
	}
	tp_mn = 0, tp_mx = 0;
	stk_mn[++tp_mn] = 1; stk_mx[++tp_mx] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] > a[i]) dp[i] = MX.query(1, pre_mn[i] + 1, i) + 1;
		else dp[i] = MN.query(1, pre_mx[i] + 1, i) + 1;
		while (tp_mx && a[stk_mx[tp_mx]] < a[i]) {
			MX.upd(1, stk_mx[tp_mx], 1e9);
			--tp_mx;
		}
		pre_mx[i] = stk_mx[tp_mx]; stk_mx[++tp_mx] = i;
		while (tp_mn && a[stk_mn[tp_mn]] > a[i]) {
			MN.upd(1, stk_mn[tp_mn], 1e9);
			--tp_mn;
		}
		pre_mn[i] = stk_mn[tp_mn]; stk_mn[++tp_mn] = i;
		MX.upd(1, i, dp[i]); MN.upd(1, i, dp[i]);
	}
	printf("%d\n", dp[n]);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}