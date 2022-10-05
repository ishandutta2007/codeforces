#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
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
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 3e5;
const int LOG_N = 19;
const int INF = 0x3f3f3f3f;
int n, qu, f[MAXN * 2 + 5], val[MAXN * 2 + 5], ncnt;
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
int hd[MAXN * 2 + 5], nxt[MAXN * 2 + 5], to[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
struct edge {
	int u, v, w;
	bool operator < (const edge &rhs) {
		return w < rhs.w;
	}
} e[MAXN + 5];
int fa[LOG_N + 2][MAXN * 2 + 5], dep[MAXN * 2 + 5];
int rid[MAXN * 2 + 5], dfn[MAXN * 2 + 5], tim = 0;
void dfs(int x, int f) {
	fa[0][x] = f; rid[dfn[x] = ++tim] = x;
	for (int E = hd[x]; E; E = nxt[E]) {
		int y = to[E]; dep[y] = dep[x] + 1;
		dfs(y, x);
	}
}
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y]) x = fa[i][x];
	if (x == y) return x;
	for (int i = LOG_N; ~i; i--) if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}
struct node {int l, r, lz, mn, mx, cmn, cmx;} s[MAXN * 4 + 5];
void pushup(int k) {
	s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);
	s[k].mx = max(s[k << 1].mx, s[k << 1 | 1].mx);
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].lz = -1; s[k].mn = INF; s[k].mx = 0;
	if (l == r) {s[k].cmn = s[k].cmx = dfn[l]; return;}
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	s[k].cmn = min(s[k << 1].cmn, s[k << 1 | 1].cmn);
	s[k].cmx = max(s[k << 1].cmx, s[k << 1 | 1].cmx);
}
void tag(int k, int v) {
	if (v) s[k].mn = s[k].cmn, s[k].mx = s[k].cmx;
	else s[k].mn = INF, s[k].mx = 0;
	s[k].lz = v;
}
void pushdown(int k) {if (~s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = -1;}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
int main() {
	scanf("%d%d", &n, &qu); ncnt = n;
	for (int i = 1; i < n; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + n);
	for (int i = 1; i < n; i++) {
		int fu = find(e[i].u), fv = find(e[i].v); ++ncnt;
		adde(ncnt, fu); adde(ncnt, fv); val[ncnt] = e[i].w;
		f[fu] = f[fv] = ncnt;
	}
	dfs(ncnt, 0); build(1, 1, n);
//	for (int i = 1; i <= n; i++) printf("%d%c", dfn[i], " \n"[i == n]);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= ncnt; j++)
		fa[i][j] = fa[i - 1][fa[i - 1][j]];
	while (qu--) {
		int opt; scanf("%d", &opt);
		if (opt <= 2) {
			int l, r; scanf("%d%d", &l, &r);
			modify(1, l, r, opt % 2);
		} else {
			int x; scanf("%d", &x);
			int X = s[1].mn, Y = s[1].mx;
			if (X == INF || (X == dfn[x] && Y == dfn[x])) puts("-1");
			else printf("%d\n", val[getlca(x, getlca(rid[X], rid[Y]))]);
		}
	}
	return 0;
}