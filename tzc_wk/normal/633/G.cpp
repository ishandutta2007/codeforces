#include <bits/stdc++.h>
using namespace std;
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
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*++s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1e5;
const int MAXM = 1000;
int n, m, qu, a[MAXN + 5], pr[MAXM + 5], vis[MAXM + 5], prcnt = 0;
void sieve(int m) {
	vis[1] = 1;
	for (int i = 2; i <= m; i++) {
		if (!vis[i]) pr[++prcnt] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= m; j++) {
			vis[pr[j] * i] = 1;
			if (i % pr[j] == 0);
		}
	}
}
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int bgt[MAXN + 5], edt[MAXN + 5], tim = 0, rid[MAXN + 5];
void dfs(int x, int f) {
	bgt[x] = ++tim; rid[tim] = x;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs(y, x);
	}
	edt[x] = tim;
}
struct node {int l, r, lz; bitset<MAXM + 5> v;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].v = s[k << 1].v | s[k << 1 | 1].v;}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r;
	if (l == r) {s[k].v.set(a[rid[l]]); return;}
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void tag(int k, int v) {
	s[k].v = (s[k].v << v) | (s[k].v >> (m - v));
	s[k].lz = (s[k].lz + v) % m;
}
void pushdown(int k) {
	if (s[k].lz) {
		tag(k << 1, s[k].lz); tag(k << 1 | 1, s[k].lz);
		s[k].lz = 0;
	}
}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
bitset<MAXM + 5> query(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return s[k].v;
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) return query(k << 1, l, r);
	else if (l > mid) return query(k << 1 | 1, l, r);
	else return query(k << 1, l, mid) | query(k << 1 | 1, mid + 1, r);
}
int main() {
	scanf("%d%d", &n, &m); sieve(m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] %= m;
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v); adde(v, u);
	}
	dfs(1, 0); build(1, 1, n);
	scanf("%d", &qu);
	while (qu--) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int v, x; scanf("%d%d", &v, &x); x %= m;
			if (x) modify(1, bgt[v], edt[v], x);
		} else {
			int v; scanf("%d", &v);
			bitset<MAXM + 5> bt = query(1, bgt[v], edt[v]);
			int res = 0;
			for (int i = 1; i < m; i++) res += (!vis[i] && bt[i]);
			printf("%d\n", res);
		}
	}
	return 0;
}