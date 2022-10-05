// Created time: 2022/6/29 11:19:13
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
const int MAXN = 1e5;
int n, qu, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dep[MAXN + 5], siz[MAXN + 5], fa[MAXN + 5];
ll sum_sqr[MAXN + 5], res;
void dfs(int x, int f) {
	fa[x] = f; siz[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs(y, x); siz[x] += siz[y];
		sum_sqr[x] += 1ll * siz[y] * siz[y];
	}
}
struct dsu {
	int f[MAXN + 5], sz[MAXN + 5];
	int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
	void merge(int x, int y) { // y is father
		x = find(x); y = find(y);
		if (x != y) f[x] = y, sz[y] += sz[x];
	}
} D;
ll calc(int x) {
	x = D.find(x); int A = D.sz[x];
	ll B = 1ll * (n - A) * (n - A) - (sum_sqr[x] + 1ll * (n - siz[x]) * (n - siz[x]));
	return 1ll * A * (A - 1) * (A - 2) + 2ll * A * (A - 1) * (n - A) + 1ll * A * B;
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	for (int i = 1; i <= n; i++) D.sz[i] = 1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++) res += calc(i);
	printf("%lld\n", res);
	scanf("%d", &qu);
	while (qu--) {
		int x, y; scanf("%d%d", &x, &y);
		x = D.find(x); y = D.find(y);
		vector<int> vx, vy; int opt = 0;
		while (x ^ y) {
			if (dep[x] < dep[y]) swap(x, y), opt ^= 1;
			if (!opt) vx.pb(x); else vy.pb(x);
			x = D.find(fa[x]);
		}
		for (int z : vx) res -= calc(z);
		for (int z : vy) res -= calc(z);
		res -= calc(x);
		for (int z : vx) D.merge(z, x);
		for (int z : vy) D.merge(z, x);
		ll tot = 0;
		for (int z : vx) tot += sum_sqr[z] - 1ll * siz[z] * siz[z];
		for (int z : vy) tot += sum_sqr[z] - 1ll * siz[z] * siz[z];
		sum_sqr[x] += tot;
		res += calc(x);
		printf("%lld\n", res);
	}
	return 0;
}