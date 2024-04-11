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
const int MAXN = 2.5e5;
const int LOG_N = 18;
int n;
struct graph {
	int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
} T1, T2;
int fa[MAXN + 5][LOG_N + 2], dep[MAXN + 5];
void dfs1(int x, int f) {
	fa[x][0] = f;
	for (int e = T1.hd[x]; e; e = T1.nxt[e]) {
		int y = T1.to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs1(y, x);
	}
}
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y])
		x = fa[x][i];
	if (x == y) return x;
	for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i])
		x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int F[MAXN + 5];
int find(int x) {return (!F[x]) ? x : F[x] = find(F[x]);}
void dfs2(int x, int f) {
	for (int e = T2.hd[x]; e; e = T2.nxt[e]) {
		int y = T2.to[e]; if (y == f) continue; dfs2(y, x);
		int lc = getlca(x, y);
		if (dep[find(y)] > dep[lc]) {
			printf("%d %d %d %d\n", find(y), fa[find(y)][0], x, y);
			F[find(y)] = fa[find(y)][0];
		} else {
			int cur = x;
			for (int j = LOG_N; ~j; j--)
				if (dep[cur] - (1 << j) >= dep[lc] && find(fa[cur][j]) != find(y))
					cur = fa[cur][j];
			printf("%d %d %d %d\n", find(cur), fa[find(cur)][0], x, y);
			F[find(cur)] = fa[find(cur)][0];
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), T1.adde(u, v), T1.adde(v, u);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), T2.adde(u, v), T2.adde(v, u);
	printf("%d\n", n - 1); dfs1(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
	dfs2(1, 0);
	return 0;
}