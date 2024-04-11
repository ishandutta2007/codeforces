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
const int MAXN = 1e5;
const int MAXM = 2e5;
mt19937 rng(20060729 ^ chrono :: steady_clock :: now().time_since_epoch().count());
int n, m;
struct graph {
	int hd[MAXN + 5], to[MAXM + 5], nxt[MAXM + 5], ec = 0;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
	void init() {for (int i = 1; i <= n; i++) hd[i] = 0; ec = 0;}
} G, T;
int dfn[MAXN + 5], fa[MAXN + 5], edt[MAXN + 5], tim = 0;
void dfs(int x) {
	dfn[x] = ++tim;
	for (int e = G.hd[x]; e; e = G.nxt[e]) {
		int y = G.to[e];
		if (!dfn[y]) fa[y] = x, dfs(y);
	}
	edt[x] = tim;
}
bool check(int x) {
	for (int i = 1; i <= n; i++) dfn[i] = fa[i] = edt[i] = 0; tim = 0;
	dfs(x);
//	for (int i = 1; i <= n; i++) printf("%d %d\n", dfn[i], edt[i]);
	for (int i = 1; i <= n; i++) for (int e = G.hd[i]; e; e = G.nxt[e]) {
		int j = G.to[e]; if (fa[j] == i) continue;
		if (edt[j] < edt[i] || dfn[j] > dfn[i]) return 0;
	}
	return 1;
}
vector<int> add[MAXN + 5];
multiset<int> st[MAXN + 5];
bool res[MAXN + 5];
int tov[MAXN + 5];
void dfsclc(int x) {
	for (int y : add[x]) st[x].insert(y);
	for (int e = T.hd[x]; e; e = T.nxt[e]) {
		int y = T.to[e]; dfsclc(y);
		if (st[x].size() < st[y].size()) swap(st[x], st[y]);
		for (int z : st[y]) st[x].insert(z);
	}
	while (st[x].find(x) != st[x].end()) st[x].erase(st[x].find(x));
	if (st[x].size() == 0) res[x] = 1;
	else if (st[x].size() == 1) tov[x] = (*st[x].begin());
	else res[x] = 0;
}
void dfspush(int x) {
	if (tov[x]) res[x] = res[tov[x]];
	for (int e = T.hd[x]; e; e = T.nxt[e]) {
		int y = T.to[e]; dfspush(y);
	}
}
void calc(int rt) {
	dfs(rt);
	for (int i = 1; i <= n; i++) if (i != rt) T.adde(fa[i], i);
	for (int i = 1; i <= n; i++) add[i].clear(), st[i].clear(), res[i] = tov[i] = 0;
	for (int i = 1; i <= n; i++) for (int e = G.hd[i]; e; e = G.nxt[e]) {
		int j = G.to[e];
		if (fa[j] != i) add[i].pb(j);
	}
	dfsclc(rt); dfspush(rt);
	vector<int> ans;
	for (int i = 1; i <= n; i++) if (res[i]) ans.pb(i);
	if (ans.size() * 5 < n) puts("-1");
	else {
		for (int x : ans) printf("%d ", x);
		printf("\n");
	}
}
void solve() {
	scanf("%d%d", &n, &m); G.init(); T.init();
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), G.adde(u, v);
//	cout << check(2) << endl;
	int lim = 100;
	while (lim--) {
		int x = rng() % n + 1;
		if (check(x)) return calc(x), void();
	}
	puts("-1");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}