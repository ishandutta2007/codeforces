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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
const int MAXN = 1e6;
int n, qu, deg[MAXN + 5], fa[MAXN + 5], hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dis[MAXN + 5], dson[MAXN + 5], mxdep[MAXN + 5];
vector<int> dp[MAXN + 5];
void dfs1(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue; dfs1(y, x);
		if (mxdep[y] + 1 > mxdep[x]) mxdep[x] = mxdep[y] + 1, dson[x] = y;
	}
}
int mx = 0;
void dfs2(int x, int f, int V) {
	if (dson[x]) dfs2(dson[x], x, V), swap(dp[x], dp[dson[x]]); dp[x].pb(dis[x]);
	if (dp[x].size() > 1) chkmax(dp[x][dp[x].size() - 1], dp[x][dp[x].size() - 2]);
	auto upd = [&](int X, int Y) {
		// printf("upd %d %d %d\n", x, X, Y);
		// the last position with dp[x][pos] + X <= mxdep[x] - pos + Y
		int L = 0, R = mxdep[x], p = -1;
		while (L <= R) {
			int mid = L + R >> 1;
			if (dp[x][mid] + X <= mxdep[x] - mid + Y) p = mid, L = mid + 1;
			else R = mid - 1;
		}
		// printf("p = %d\n", p);
		if (~p) chkmax(mx, dp[x][p] + X)/*, printf("%d\n", dp[x][p] + X)*/;
		if (p + 1 <= mxdep[x]) chkmax(mx, mxdep[x] - (p + 1) + Y)/*, printf("%d\n", mxdep[x] - (p + 1) + Y)*/;
	};
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f || y == dson[x]) continue; dfs2(y, x, V);
		for (int i = 0; i < dp[y].size(); i++) {
			int D = dp[y].size() - i; upd(dp[y][i] + V, D);
		}
		for (int i = 0; i < dp[y].size(); i++) {
			int D = dp[y].size() - i;
			chkmax(dp[x][mxdep[x] - D], dp[y][i]);
		}
		chkmax(dp[x][dp[x].size() - 1], dp[x][dp[x].size() - 2]);
	}
	upd(dis[x] + V, 0);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &fa[i]); deg[i]++; deg[fa[i]]++;
		adde(i, fa[i]); adde(fa[i], i);
	}
	memset(dis, -1, sizeof(dis)); queue<int> q;
	for (int i = 1; i <= n; i++) if (deg[i] == 1) dis[i] = 0, q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			if (!~dis[y]) dis[y] = dis[x] + 1, q.push(y);
		}
	}
	dfs1(1, 0); scanf("%d", &qu);
	while (qu--) {
		for (int i = 1; i <= n; i++) dp[i].clear();
		int x; scanf("%d", &x); mx = 0;
		dfs2(1, 0, x); printf("%d ", mx);
	}
	return 0;
}