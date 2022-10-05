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
		(*s) = 0;
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
const int MAXN = 3e5;
int n, pp, dep[MAXN + 5], a[MAXN + 5], deg[MAXN + 5], pos[MAXN + 5];
int fa[MAXN + 5], res[MAXN + 5], tim;
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void dfs0(int x, int f) {
	fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs0(y, x);
	}
}
int mark[MAXN + 5];
void dfspush(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfspush(y, x); mark[x] += mark[y];
	}
}
bool checkPOS() {
	for (int i = 1; i <= pp; i++) {
		int d = dep[pos[i]]; mark[pos[i]] -= d;
		mark[fa[pos[i]]] += d; mark[fa[pos[i]]]++;
	}
	dfspush(1, 0);
	for (int i = 1; i <= n; i++) if (mark[i] + res[i] != a[i]) return 0;
	return 1;
}
int dfn[MAXN + 5], idx;
void dfsadd(int x, int f) {
	vector<pii> vec; dfn[x] = ++idx;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		vec.pb(mp(res[y], y));
	}
	sort(vec.begin(), vec.end());
	for (pii p : vec) dfsadd(p.se, x);
}
bool checkDFS() {
	dfsadd(1, 0);
	for (int i = 1; i <= n; i++) if (res[i] != dfn[i]) return 0;
	return 1;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n); deg[1]++;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]] = i;
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v); adde(u, v); adde(v, u);
		deg[u]++; deg[v]++;
	}
	dfs0(1, 0); pp = n;
	for (int i = 1; i < n; i++) {
		if (deg[pos[i]] != 1) {pp = i; break;}
		deg[fa[pos[i]]]--;
	}
	for (int i = 1; i <= pp; i++) {
		int stp = 0, cur = pos[i];
		while (!res[cur] && cur) stp++, cur = fa[cur];
		tim += stp; int nt = tim; cur = pos[i];
		while (!res[cur] && cur) res[cur] = nt--, cur = fa[cur];
	}
	ll sum = 0;
	for (int i = 1; i <= pp; i++) sum += dep[pos[i]];
	for (int i = 1; i <= n; i++) if (!res[i]) res[i] = a[i];
//	printf("%d\n", pp);
	if (!checkPOS()) return puts("NO"), 0;
	if (!checkDFS()) return puts("NO"), 0;
	printf("YES\n%lld\n", sum);
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	return 0;
}
/*
8
4 5 3 2 1 6 7 8
1 2
2 3
3 4
4 5
3 6
6 7
2 8
*/