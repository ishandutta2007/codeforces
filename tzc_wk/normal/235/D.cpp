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
const int MAXN = 3000;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int onc[MAXN + 5], dfn[MAXN + 5], tim, fa[MAXN + 5];
int bel[MAXN + 5], cmp, dep[MAXN + 5];
void dfs1(int x, int f) {
	fa[x] = f; dfn[x] = ++tim;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (!dfn[y]) dfs1(y, x);
		else if (dfn[y] > dfn[x]) {
			for (int i = y; i != x; i = fa[i]) onc[i] = 1;
			onc[x] = 1;
		}
	}
}
void dfs2(int x, int f) {
	bel[x] = cmp; fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (onc[y] || y == f) continue;
		dep[y] = dep[x] + 1;dfs2(y, x);
	}
}
int lca[MAXN + 5][MAXN + 5];
int getlca(int x, int y) {
	if (x == y) return x;
	if (~lca[x][y]) return lca[x][y];
	if (dep[x] > dep[y]) return lca[x][y] = getlca(fa[x], y);
	else if (dep[x] < dep[y]) return lca[x][y] = getlca(x, fa[y]);
	else return lca[x][y] = getlca(fa[x], fa[y]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i <= n; i++) scanf("%d%d", &u, &v), u++, v++, adde(u, v), adde(v, u);
	dfs1(1, 0);
//	for (int i = 1; i <= n; i++) printf("%d%c", onc[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) if (onc[i]) cmp++, dfs2(i, 0);
	memset(lca, -1, sizeof(lca)); double res = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (bel[i] == bel[j]) {
			int x = dep[i] + dep[j] - dep[getlca(i, j)] * 2 + 1;
			res += 1.0 / x;
		} else {
			int x = dep[i] + dep[j], y = abs(bel[i] - bel[j]), z = cmp - y;
//			printf("%d %d %d\n", x, y, z);
			res += 1.0 / (x + y + 1) + 1.0 / (x + z + 1) - 1.0 / (x + y + z);
		}
	}
	printf("%.10lf\n", res);
	return 0;
}