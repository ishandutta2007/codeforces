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
const int MAXN = 2e5;
int n;
struct graph {
	int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 1;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
} G, G0;
int fa[MAXN + 5], siz[MAXN + 5], wson[MAXN + 5], fae[MAXN + 5];
int top[MAXN + 5], rid[MAXN + 5], dfn[MAXN + 5], tim;
void dfs1(int x, int f) {
	fa[x] = f; siz[x] = 1;
	for (int e = G.hd[x]; e; e = G.nxt[e]) {
		int y = G.to[e]; if (y == f) continue;
		dfs1(y, x); siz[x] += siz[y]; fae[y] = e >> 1;
		if (siz[y] > siz[wson[x]]) wson[x] = y;
	}
}
void dfs2(int x, int tp) {
	rid[dfn[x] = ++tim] = x; top[x] = tp; if (wson[x]) dfs2(wson[x], tp);
	for (int e = G.hd[x]; e; e = G.nxt[e]) {
		int y = G.to[e]; if (y == fa[x] || y == wson[x]) continue;
		dfs2(y, y);
	}
}
struct node {int l, r, cnt[2], lz; ll sum[2];} s[MAXN * 4 + 5];
void pushup(int k) {
	s[k].cnt[0] = s[k << 1].cnt[0] + s[k << 1 | 1].cnt[0];
	s[k].cnt[1] = s[k << 1].cnt[1] + s[k << 1 | 1].cnt[1];
	s[k].sum[0] = s[k << 1].sum[0] + s[k << 1 | 1].sum[0];
	s[k].sum[1] = s[k << 1].sum[1] + s[k << 1 | 1].sum[1];
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].cnt[0] = 1, s[k].sum[0] = fae[rid[l]], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r); pushup(k);
}
void tag(int k) {s[k].lz ^= 1; swap(s[k].cnt[0], s[k].cnt[1]); swap(s[k].sum[0], s[k].sum[1]);}
void pushdown(int k) {if (s[k].lz) tag(k << 1), tag(k << 1 | 1), s[k].lz = 0;}
void modify(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return tag(k), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r);
	else if (l > mid) modify(k << 1 | 1, l, r);
	else modify(k << 1, l, mid), modify(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void flip(int x) {
	while (top[x] ^ 1) {
		modify(1, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	if (x != 1) modify(1, 2, dfn[x]);
}
bool pre; int tot = 1, _siz[MAXN + 5]; vector<int> pt;
void dfsclc(int x) {
	_siz[x] = 1; pt.pb(x);
	for (int e = G0.hd[x]; e; e = G0.nxt[e]) {
		int y = G0.to[e]; dfsclc(y); _siz[x] += _siz[y];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {scanf("%d%d", &u, &v); G.adde(u, v); G.adde(v, u);}
	dfs1(1, 0); dfs2(1, 1); build(1, 2, n);
	while (1) {
		int opt; scanf("%d", &opt); if (opt == 3) break;
		if (opt == 1) {
			int x; scanf("%d", &x); flip(x);
			G0.adde(fa[x], x); tot++;
			if (tot & 1) puts("0"), pre = 0;
			else if (s[1].cnt[1] != tot / 2) puts("0"), pre = 0;
			else printf("%lld\n", s[1].sum[1]), pre = 1;
		} else {
			if (!pre) puts("0");
			else {
				pt.clear(); dfsclc(1); vector<int> res;
				for (int x : pt) if (x != 1 && _siz[x] % 2) res.pb(fae[x]);
				sort(res.begin(), res.end());
				printf("%d", res.size());
				for (int x : res) printf(" %d", x); printf("\n");
			}
		}
		fflush(stdout);
	}
	return 0;
}
/*
4
1 2
1 3
2 4
1 2
1 3
1 4
3
*/