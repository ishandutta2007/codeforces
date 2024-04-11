// Created time: 2022/6/23 14:05:25
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
const int MAXN = 4e5;
int n, qu, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dep[MAXN + 5], fa[MAXN + 5];
vector<int> pth[MAXN + 5];
struct qry {int u, v; string s;} q[MAXN + 5];
void dfs(int x, int f) {
	fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs(y, x);
	}
}
char able[MAXN + 5][3];
int cd[MAXN + 5];
bitset<26> can[MAXN + 5];
namespace Tarjan {
	const int MAXV = 8e5;
	const int MAXE = 2e7;
	int hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], ec = 0;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
	int dfn[MAXV + 5], low[MAXV + 5], tim = 0, stk[MAXV + 5], tp, cmp, bel[MAXV + 5], vis[MAXV + 5];
	void tarjan(int x) {
		dfn[x] = low[x] = ++tim; stk[++tp] = x; vis[x] = 1;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			if (!dfn[y]) tarjan(y), chkmin(low[x], low[y]);
			else if (vis[y]) chkmin(low[x], dfn[y]);
		}
		if (dfn[x] == low[x]) {
			cmp++; int o; do {
				o = stk[tp--]; bel[o] = cmp;
				vis[o] = 0;
			} while (o ^ x);
		}
	}
	void work() {
		for (int i = 1; i <= n * 2; i++) if (!dfn[i]) tarjan(i);
	}
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v); adde(v, u);
	}
	for (int i = 1; i <= n; i++) can[i].set();
	dfs(1, 0);
	for (int i = 1; i <= qu; i++) {
		static char buf[MAXN + 5];
		scanf("%d%d%s", &q[i].u, &q[i].v, buf + 1);
		int len = strlen(buf + 1);
		for (int j = 1; j <= len; j++) q[i].s.pb(buf[j]);
		int x = q[i].u, y = q[i].v; vector<int> A, B;
		while (dep[x] > dep[y]) A.pb(x), x = fa[x];
		while (dep[y] > dep[x]) B.pb(y), y = fa[y];
		while (x ^ y) A.pb(x), x = fa[x], B.pb(y), y = fa[y];
		A.pb(x); reverse(B.begin(), B.end());
		for (int e : A) pth[i].pb(e);
		for (int e : B) pth[i].pb(e);
		for (int j = 0; j < pth[i].size(); j++) {
			bitset<26> bs;
			bs.set(q[i].s[j] - 'a');
			bs.set(q[i].s[pth[i].size() - j - 1] - 'a');
			can[pth[i][j]] &= bs;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!can[i].any()) return puts("NO"), 0;
		else if (can[i].count() == 26) continue;
		else if (can[i].count() == 2) {
			able[i][0] = can[i]._Find_first() + 'a';
			able[i][1] = can[i]._Find_next(able[i][0] - 'a') + 'a';
			cd[i] = 2;
		}
		else if (can[i].count() == 1) {
			able[i][0] = can[i]._Find_first() + 'a';
			cd[i] = 1;
			Tarjan :: adde(i + n, i);
		} else assert(0);
	}
	for (int i = 1; i <= qu; i++) {
		string &s = q[i].s; int dir = -1;
		for (int j = 0; j < pth[i].size(); j++) {
			int x = pth[i][j];
			if (cd[x] == 1 && s[j] != s[s.size() - j - 1]) {
				int shd = (able[x][0] == s[j]) ? 0 : 1;
				if (dir == (shd ^ 1)) return puts("NO"), 0;
				dir = shd;
			}
		}
		if (dir == 0) {
			for (int j = 0; j < pth[i].size(); j++) {
				int x = pth[i][j];
				if (cd[x] == 2) {
					int ban = (able[x][1] == s[s.size() - j - 1]);
					Tarjan :: adde(x + ban * n, x + (ban ^ 1) * n);
				}
			}
		} else if (dir == 1) {
			for (int j = 0; j < pth[i].size(); j++) {
				int x = pth[i][j];
				if (cd[x] == 2) {
					int ban = (able[x][1] == s[j]);
					Tarjan :: adde(x + ban * n, x + (ban ^ 1) * n);
				}
			}
		} else {
			int pt = 0, pos = 0;
			for (int j = 0; j < pth[i].size(); j++) {
				int x = pth[i][j];
				if (cd[x] == 2) pt = x, pos = j;
			}
			if (!pt) continue;
			for (int j = 0; j < pth[i].size(); j++) {
				int x = pth[i][j];
				if (cd[x] == 2 && x != pt) {
					Tarjan :: adde(x + (s[j] == able[x][1]) * n, pt + (s[pos] == able[pt][1]) * n);
					Tarjan :: adde(pt + (s[pos] == able[pt][1]) * n, x + (s[j] == able[x][1]) * n);
					Tarjan :: adde(x + (s[s.size() - j - 1] == able[x][1]) * n, pt + (s[s.size() - pos - 1] == able[pt][1]) * n);
					Tarjan :: adde(pt + (s[s.size() - pos - 1] == able[pt][1]) * n, x + (s[s.size() - j - 1] == able[x][1]) * n);
				}
			}
		}
	}
	Tarjan :: work();
	for (int i = 1; i <= n; i++) if (Tarjan :: bel[i] == Tarjan :: bel[i + n])
		return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= n; i++) {
		if (can[i].count() == 26) putchar('a');
		else putchar(able[i][Tarjan :: bel[i] > Tarjan :: bel[i + n]]);
	}
	return 0;
}