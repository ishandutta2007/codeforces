// Created time: 2022/7/16 22:34:42
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
const int LOG_N = 18;
int n, m, on[MAXN + 5]; struct edge {int u, v;} e[MAXN + 5];
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int f[MAXN + 5]; int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
int fa[MAXN + 5][LOG_N + 2], dep[MAXN + 5];
void dfs0(int x, int f) {
	fa[x][0] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs0(y, x);
	}
}
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int get_kanc(int x, int k) {
	for (int i = LOG_N; ~i; i--) if (k >> i & 1) x = fa[x][i];
	return x;
}
int mark[MAXN + 5], A;
void dfspush(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		mark[y] += mark[x]; dfspush(y, x);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v;
	for (int i = 1; i <= m; i++) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) f[fu] = fv, adde(e[i].u, e[i].v), adde(e[i].v, e[i].u), on[i] = 1;
	}
	dfs0(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
	int tot = 0;
	for (int i = 1; i <= m; i++) if (!on[i]) {
//		printf("%d\n", i);
		int lc = getlca(e[i].u, e[i].v);
		if (e[i].u == lc) A++, mark[get_kanc(e[i].v, dep[e[i].v] - dep[e[i].u] - 1)]--;
		else mark[e[i].u]++;
		if (e[i].v == lc) A++, mark[get_kanc(e[i].u, dep[e[i].u] - dep[e[i].v] - 1)]--;
		else mark[e[i].v]++;
//		printf("%d %d\n", u, v);
		tot++;
	}
	dfspush(1, 0);
	for (int i = 1; i <= n; i++) printf("%d", mark[i] + A == tot);
	return 0;
}