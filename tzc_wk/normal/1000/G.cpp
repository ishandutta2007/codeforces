// Created time: 2022/7/2 8:30:25
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
const int LOG_N = 18;
int n, qu, a[MAXN + 5];
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], val[MAXN * 2 + 5], ec = 1;
void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
ll dp[MAXN + 5], dp_out[MAXN + 5], sum_dw[MAXN + 5], sum_up[MAXN + 5], sum_a[MAXN + 5];
int dep[MAXN + 5], fa[MAXN + 5][LOG_N + 2];
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y])
		x = fa[x][i];
	if (x == y) return x;
	for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i])
		x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void dfs1(int x, int f) {
	dp[x] = a[x]; fa[x][0] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1;
		sum_dw[y] = sum_dw[x] + val[e];
		sum_up[y] = sum_up[x] + val[e ^ 1];
		dfs1(y, x); dp[x] += max(0ll, dp[y] - val[e] - val[e ^ 1]);
	}
}
void dfs2(int x, int f) {
	ll sum = a[x];
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (y == f) sum += dp_out[x];
		else sum += max(0ll, dp[y] - val[e] - val[e ^ 1]);
	}
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		sum -= max(0ll, dp[y] - val[e] - val[e ^ 1]);
		dp_out[y] = max(0ll, sum - val[e] - val[e ^ 1]);
		sum += max(0ll, dp[y] - val[e] - val[e ^ 1]);
		dfs2(y, x);
	}
}
ll sum_dp[MAXN + 5], upv[MAXN + 5], sum_upv[MAXN + 5];
void dfs3(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		sum_dp[y] = sum_dp[x] + dp[y];
		sum_upv[y] = sum_upv[x] + upv[y];
		dfs3(y, x);
	}
}
int main() {
//	freopen("strawberry.in", "r", stdin);
//	freopen("strawberry.out", "w", stdout);
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, u, v, w1, w2; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w1); w2 = w1;
		adde(u, v, w1); adde(v, u, w2);
	}
	dfs1(1, 0); dfs2(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 1; i <= n; i++) for (int e = hd[i]; e; e = nxt[e]) {
		int j = to[e]; if (j == fa[i][0]) continue;
		upv[j] = max(0ll, dp[j] - val[e] - val[e ^ 1]);
	}
	sum_dp[1] = dp[1]; sum_upv[1] = upv[1]; dfs3(1, 0);
	while (qu--) {
		int x, y; scanf("%d%d", &x, &y); int lc = getlca(x, y);
		ll res = sum_dp[x] + sum_dp[y] - sum_dp[lc] - sum_dp[fa[lc][0]];
		res -= sum_up[x] - sum_up[lc]; res -= sum_dw[y] - sum_dw[lc];
		res -= sum_upv[x] - sum_upv[lc]; res -= sum_upv[y] - sum_upv[lc];
		res += dp_out[lc];
		printf("%lld\n", res);
	}
	return 0;
}