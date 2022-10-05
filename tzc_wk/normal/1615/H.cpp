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
const int MAXN = 1e3;
const int MAXV = 1002;
const int MAXE = 1e4;
const int INF = 0x3f3f3f3f;
int n, m, a[MAXN + 5], res[MAXN + 5];
vector<int> g[MAXN + 5];
int S, T, hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], cap[MAXE + 5], ec = 1;
void init() {memset(hd, 0, sizeof(hd)); ec = 1;}
void adde(int u, int v, int f) {
//	printf("adde %d %d %d\n", u, v, f);
	to[++ec] = v; cap[ec] = f; nxt[ec] = hd[u]; hd[u] = ec;
	to[++ec] = u; cap[ec] = 0; nxt[ec] = hd[v]; hd[v] = ec;
}
int dep[MAXN + 5], now[MAXN + 5];
bool getdep(int S, int T) {
	memset(dep, -1, sizeof(dep)); dep[S] = 0;
	queue<int> q; q.push(S);
	while (!q.empty()) {
		int x = q.front(); q.pop(); now[x] = hd[x];
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = cap[e];
			if (z && !~dep[y]) {dep[y] = dep[x] + 1; q.push(y);}
		}
	}
	return ~dep[T];
}
int getflow(int x, int f) {
	if (x == T) return f; int ret = 0;
	for (int &e = now[x]; e; e = nxt[e]) {
		int y = to[e], z = cap[e];
		if (dep[y] == dep[x] + 1) {
			int w = getflow(y, min(f - ret, z));
			ret += w; cap[e] -= w; cap[e ^ 1] += w;
			if (f == ret) return ret;
		}
	}
	return ret;
}
int dinic() {
	int ret = 0;
	while (getdep(S, T)) ret += getflow(S, INF);
	return ret;
}
void solve(int l, int r, vector<int> pt) {
	if (pt.empty()) return;
	if (l == r) {
		for (int x : pt) res[x] = l;
		return;
	}
	init(); int mid = l + r >> 1;
	static bool vis[MAXN + 5]; memset(vis, 0, sizeof(vis));
	for (int x : pt) vis[x] = 1;
	for (int x : pt) for (int y : g[x]) adde(y, x, INF);
	for (int x : pt) { // S: mid, T : mid + 1
		int df = abs(a[x] - mid) - abs(a[x] - mid - 1);
		if (df > 0) adde(x, T, df); else adde(S, x, -df);
	}
	dinic(); vector<int> L, R;
	for (int x : pt) {
		if (~dep[x]) L.pb(x);
		else R.pb(x);
	}
	solve(l, mid, L); solve(mid + 1, r, R);
}
int main() {
	scanf("%d%d", &n, &m); T = (S = n + 1) + 1;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), g[u].pb(v);
	vector<int> ini; for (int i = 1; i <= n; i++) ini.pb(i);
	solve(0, INF, ini);
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	return 0;
}