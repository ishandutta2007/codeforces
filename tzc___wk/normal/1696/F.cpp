// Created time: 2022/6/25 22:32:44
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
const int MAXN = 100;
int n, a[MAXN + 5][MAXN + 5][MAXN + 5];
int f[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return; f[x] = y;
}
int find_mxdep(int x, vector<int> A) {
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int y : A) for (int z : A) if (a[x][y][z]) merge(y, z);
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += (find(i) == i);
	return sum;
}
vector<int> find_dia(vector<int> A) {
	static int mxdep[MAXN + 5]; int mx = 0;
	for (int x : A) mxdep[x] = find_mxdep(x, A);
	for (int x : A) chkmax(mx, mxdep[x]);
	vector<int> res;
	for (int x : A) if (mx == mxdep[x]) res.pb(x);
	return res;
}
int fa[MAXN + 5], hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
int dis[MAXN + 5][MAXN + 5];
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void dfs(int x, int f, int rt) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dis[rt][y] = dis[rt][x] + 1; dfs(y, x, rt);
	}
}
void solve() {
	scanf("%d", &n); memset(fa, 0, sizeof(fa)); vector<pii> E;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
		for (int k = 1; k <= n; k++) {
			scanf("%1d", &a[k][i][j]); a[k][j][i] = a[k][i][j];
		}
	vector<int> tot;
	for (int i = 1; i <= n; i++) tot.pb(i);
	vector<vector<int> > vec;
	while (!tot.empty()) {
		vector<int> v = find_dia(tot);
		vec.pb(v); static bool in[MAXN + 5];
		for (int i = 1; i <= n; i++) in[i] = 0;
		for (int x : v) in[x] = 1;
		vector<int> ntot;
		for (int x : tot) if (!in[x]) ntot.pb(x);
		tot = ntot;
	}
	if (vec.back().size() > 2) return puts("No"), void();
	else if (vec.back().size() == 2) {
		fa[vec.back()[0]] = vec.back()[1];
		fa[vec.back()[1]] = vec.back()[0];
		E.pb(mp(vec.back()[0], vec.back()[1]));
		for (int i = (int)(vec.size()) - 2; ~i; i--) {
			for (int x : vec[i]) {
				for (int y : vec[i + 1])
					if (a[y][fa[y]][x]) {
						fa[x] = y, E.pb(mp(x, y));
						break;
					}
			}
		}
	} else {
		for (int x : vec[vec.size() - 2]) {
			fa[x] = vec.back()[0];
			E.pb(mp(x, vec.back()[0]));
		}
		for (int i = (int)(vec.size()) - 3; ~i; i--) {
			for (int x : vec[i]) {
				for (int y : vec[i + 1])
					if (a[y][fa[y]][x]) {
						fa[x] = y, E.pb(mp(x, y));
						break;
					}
			}
		}
	}
	if (E.size() != n - 1) return puts("No"), void();
	memset(hd, 0, sizeof(hd)); ec = 0;
	memset(dis, 0, sizeof(dis));
	for (pii p : E) adde(p.fi, p.se), adde(p.se, p.fi);
	for (int i = 1; i <= n; i++) dfs(i, 0, i);
	for (int x = 1; x <= n; x++) for (int y = 1; y <= n; y++) for (int z = y + 1; z <= n; z++)
		if (a[x][y][z] != (dis[x][y] == dis[x][z])) return puts("No"), void();
	puts("Yes");
	for (pii p : E) printf("%d %d\n", p.fi, p.se);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}