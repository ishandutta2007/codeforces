// Created time: 2022/7/11 15:32:21
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
int qu, d, vis[MAXN + 5];
struct fenwick {
	int t[MAXN * 2 + 5];
	void add(int x, int v) {for (int i = x; i <= MAXN * 2; i += (i & (-i))) t[i] += v;}
	int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
	int query(int l, int r) {return query(r) - query(l - 1);}
} T;
struct node {int l, r, lz; ll s2, s1, s0;} s[MAXN * 24 + 5];
void pushup(int k) {
	s[k].s2 = s[k << 1].s2 + s[k << 1 | 1].s2;
	s[k].s1 = s[k << 1].s1 + s[k << 1 | 1].s1;
	s[k].s0 = s[k << 1].s0 + s[k << 1 | 1].s0;
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].s0 = s[k].s1 = s[k].s2 = 0; if (l == r) return;
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void tag(int k, int v) {
	s[k].lz += v;
	s[k].s2 += 2ll * v * s[k].s1 + 1ll * v * v * s[k].s0;
	s[k].s1 += 1ll * v * s[k].s0;
}
void pushdown(int k) {if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
void upd(int k, int p, int state, int v) {
	if (s[k].l == s[k].r) {
		if (state) s[k].s0 = 1, s[k].s1 = v, s[k].s2 = 1ll * v * v;
		else s[k].s0 = s[k].s1 = s[k].s2 = 0;
		return;
	}
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (p <= mid) upd(k << 1, p, state, v);
	else upd(k << 1 | 1, p, state, v);
	pushup(k);
}
int main() {
	scanf("%d%d", &qu, &d); build(1, -MAXN, MAXN * 2);
	for (int i = 1, x; i <= qu; i++) {
		scanf("%d", &x);
		if (vis[x]) {
			T.add(x, -1); upd(1, x, 0, 0);
			modify(1, x - d, x - 1, -1);
			vis[x] = 0;
		} else {
			int cnt = T.query(x + 1, x + d);
			T.add(x, 1); upd(1, x, 1, cnt);
			modify(1, x - d, x - 1, 1);
			vis[x] = 1;
		}
		printf("%lld\n", (s[1].s2 - s[1].s1) / 2);
	}
	return 0;
}