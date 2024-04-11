// Created time: 2022/5/8 22:36:08
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
const int MAXN = 2e5;
const int LOG_N = 18;
const int MAXQ = 1e6;
int n, qu, a[MAXN + 5], pos[MAXN + 5], lg[MAXN + 5];
pii st[LOG_N + 2][MAXN + 5];
pii query_mx(int l, int r) {
	int k = lg[r - l + 1];
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}
vector<pii> add[MAXN + 5], del[MAXN + 5], qv[MAXN + 5];
ll res[MAXQ + 5];
void add_itvl(int l1, int r1, int l2, int r2) {
//	printf("add_itvl [%d, %d] [%d, %d]\n", l1, r1, l2, r2);
	add[l2].pb(mp(l1, r1));
	del[r2 + 1].pb(mp(l1, r1));
}
void init(int l, int r) {
	if (l > r) return; int p = query_mx(l, r).se;
//	printf("init %d %d\n", l, r);
	init(l, p - 1); init(p + 1, r);
	for (int i = 1; i * i < a[p]; i++) if (a[p] % i == 0) {
		int A = i, B = a[p] / i, pA = pos[A], pB = pos[B];
		if (l <= pA && pA <= p && l <= pB && pB <= p) add_itvl(l, min(pA, pB), p, r);
		if (p <= pA && pA <= r && p <= pB && pB <= r) add_itvl(l, p, max(pA, pB), r);
		if (l <= min(pA, pB) && min(pA, pB) <= p && p <= max(pA, pB) && max(pA, pB) <= r)
			add_itvl(l, min(pA, pB), max(pA, pB), r);
	}
}
struct node{int l, r, mn, num, add_lz; ll sum, cnt_lz;} s[MAXN * 4 + 5];
void pushup(int k) {
	s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);
	s[k].num = (s[k << 1].num) * (s[k << 1].mn == s[k].mn) + (s[k << 1 | 1].num) * (s[k << 1 | 1].mn == s[k].mn);
	s[k].sum = s[k << 1].sum + s[k << 1 | 1].sum;
}
void pushdown(int k) {
	if (s[k].add_lz) {
		s[k << 1].add_lz += s[k].add_lz; s[k << 1].mn += s[k].add_lz;
		s[k << 1 | 1].add_lz += s[k].add_lz; s[k << 1 | 1].mn += s[k].add_lz;
		s[k].add_lz = 0;
	}
	if (s[k].cnt_lz) {
		if (s[k << 1].mn == s[k].mn) s[k << 1].cnt_lz += s[k].cnt_lz, s[k << 1].sum += s[k].cnt_lz * s[k<<1].num;
		if (s[k << 1 | 1].mn == s[k].mn) s[k << 1 | 1].cnt_lz += s[k].cnt_lz, s[k << 1 | 1].sum += s[k].cnt_lz * s[k << 1 | 1].num;
		s[k].cnt_lz = 0;
	}
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) {s[k].num = 1; return;}
	int mid = (l + r) >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void modify(int k, int l, int r, int x) {
	if(l > r) return;
	if(l <= s[k].l && s[k].r <= r) {s[k].mn += x; s[k].add_lz += x; return;}
	pushdown(k); int mid = (s[k].l + s[k].r) >> 1;
	if (r <= mid) modify(k << 1, l, r, x);
	else if (l > mid) modify(k << 1 | 1, l, r, x);
	else modify(k << 1, l, mid, x), modify(k << 1 | 1, mid + 1, r, x);
	pushup(k);
}
void addcnt(int k, int l, int r, int x) {
	if (l > r) return;
	if (l <= s[k].l && s[k].r <= r) {
		if (!s[k].mn) s[k].cnt_lz += x, s[k].sum += s[k].num;
		return;
	}
	pushdown(k); int mid = (s[k].l + s[k].r) >> 1;
	if (r <= mid) addcnt(k << 1, l, r, x);
	else if (l > mid) addcnt(k << 1 | 1, l, r, x);
	else addcnt(k << 1, l, mid, x), addcnt(k << 1 | 1, mid + 1, r, x);
	pushup(k);
}
int querynum(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return (!s[k].mn) * s[k].num;
	pushdown(k); int mid = (s[k].l + s[k].r) >> 1;
	if (r <= mid) return querynum(k << 1, l, r);
	else if (l > mid) return querynum(k << 1 | 1, l, r);
	else return querynum(k << 1, l, mid) + querynum(k << 1 | 1, mid + 1, r);
}
ll query(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return s[k].sum;
	pushdown(k); int mid = (s[k].l + s[k].r) >> 1;
	if (r <= mid) return query(k << 1, l, r);
	else if (l > mid) return query(k << 1 | 1, l, r);
	else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), st[0][i] = mp(a[i], i), pos[a[i]] = i;
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	for (int i = 1, l, r; i <= qu; i++) scanf("%d%d", &l, &r), qv[r].pb(mp(l, i));
	init(1, n); build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		for (pii p : add[i]) modify(1, p.fi, p.se, 1);
		for (pii p : del[i]) modify(1, p.fi, p.se, -1);
		addcnt(1, 1, i, 1);
		for (pii p : qv[i]) res[p.se] = 1ll * (i - p.fi + 1) * (i - p.fi + 2) / 2 - query(1, p.fi, i);
//		for (int j = 1; j <= i; j++) printf("%d %d %d\n", j, i, querynum(1, j, i));
	}
	for (int i = 1; i <= qu; i++) printf("%lld\n", res[i]);
	return 0;
}