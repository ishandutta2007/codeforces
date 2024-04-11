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
const int MAXN = 4e5;
const int LOG_N = 18;
int n, k, r, qu, hd[MAXN + 5], nxt[MAXN * 2 + 5], to[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
bool has[MAXN + 5];
int bel[MAXN + 5], f[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {x = find(x); y = find(y); if (x ^ y) f[x] = y;}
int dep[MAXN + 5], fa[MAXN + 5][LOG_N + 2];
void dfs(int x, int f) {
	fa[x][0] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs(y, x);
	}
}
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i])
		x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int getdis(int x, int y) {return dep[x] + dep[y] - (dep[getlca(x, y)] << 1);}
int get_kanc(int x, int v) {
//	printf("kanc %d %d\n", x, v);
	for (int i = LOG_N; ~i; i--) if (v >> i & 1) x = fa[x][i];
	return x;
}
int getstp(int x, int y) {
	int z = getlca(x, y);
	if (dep[x] - dep[z] >= (k >> 1)) return get_kanc(x, k >> 1);
	else return get_kanc(y, dep[y] - dep[z] - ((k >> 1) - (dep[x] - dep[z])));
}
int main() {
	scanf("%d%d%d", &n, &k, &r);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, i + n); adde(i + n, u);
		adde(v, i + n); adde(i + n, v);
	}
	for (int i = 1, x; i <= r; i++) scanf("%d", &x), has[x] = 1;
	n = n * 2 - 1; k <<= 1; queue<pii> q;
	for (int i = 1; i <= n; i++) if (has[i]) q.push(mp(0, i)), bel[i] = i;
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		if (p.fi == k / 2) continue; int x = p.se;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			if (bel[y]) merge(bel[x], bel[y]);
			else merge(y, bel[x]), bel[y] = x, q.push(mp(p.fi + 1, y));
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
	scanf("%d", &qu);
	while (qu--) {
		int x, y; scanf("%d%d", &x, &y);
		if (getdis(x, y) <= k) puts("YES");
		else {
			int px = getstp(x, y), py = getstp(y, x);
			printf("%s\n", (find(px) == find(py)) ? "YES" : "NO");
		}
	}
	return 0;
}