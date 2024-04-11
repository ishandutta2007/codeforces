#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
const int MAXN = 14;
const int MAXM = 100;
const int MAXP = 16384;
int n, m, xa[MAXN + 5], ya[MAXN + 5];
struct dat {
	int x, y, t;
	bool operator < (const dat &rhs) {
		return t < rhs.t;
	}
} b[MAXM + 5];
int f[MAXP + 5][MAXM + 5], g[MAXP + 5][MAXM + 5];
int mn[MAXP + 5][MAXN + 5], mn_key[MAXP + 5][MAXM + 5];
int dis(int x1, int y1, int x2, int y2) {return abs(x1 - x2) + abs(y1 - y2);}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &xa[i], &ya[i]);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].t);
	sort(b + 1, b + m + 1);
	memset(mn, 63, sizeof(mn)); memset(mn_key, 63, sizeof(mn_key));
	for (int i = 0; i < (1 << n); i++) for (int j = 1; j <= n; j++)
		if (~i >> (j - 1) & 1) for (int k = 1; k <= n; k++)
			if (i >> (k - 1) & 1) chkmin(mn[i][j], dis(xa[j], ya[j], xa[k], ya[k]));
	for (int i = 0; i < (1 << n); i++) for (int j = 1; j <= m; j++)
		for (int k = 1; k <= n; k++) if (i >> (k - 1) & 1)
			chkmin(mn_key[i][j], dis(xa[k], ya[k], b[j].x, b[j].y));
	memset(f, 63, sizeof(f)); int res = 0;
	priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > q; // second: 0 for f and 1 for g
	for (int i = 1; i <= n; i++) f[1 << i - 1][0] = 0, q.push(mp(0, mp(1 << i - 1, 0)));
	memset(g, 207, sizeof(g));
	for (int i = 1; i <= m; i++) g[0][i] = 1;
	for (int j = 1; j <= m; j++) {
		while (!q.empty() && q.top().fi < b[j].t) {
			auto T = q.top(); q.pop();
			int S = T.se.fi, x = T.se.se;
			for (int i = 1; i <= n; i++) if (~S >> (i - 1) & 1) {
				if (f[S | (1 << i - 1)][x] > f[S][x] + mn[S][i]) {
					f[S | (1 << i - 1)][x] = f[S][x] + mn[S][i];
					q.push(mp(f[S | (1 << i - 1)][x], mp(S | (1 << i - 1), x)));
				}
			}
			for (int i = j; i <= m; i++) if (b[i].t >= f[S][x] + mn_key[S][i])
				chkmax(g[S][i], x + 1);
		}
		for (int S = 0; S < (1 << n); S++) if (g[S][j] > 0) {
			chkmax(res, g[S][j]);
			for (int i = 1; i <= n; i++) if (~S >> (i - 1) & 1) {
				int v = b[j].t + min(mn[S][i], dis(b[j].x, b[j].y, xa[i], ya[i]));
				if (f[S | (1 << i - 1)][g[S][j]] > v) {
					f[S | (1 << i - 1)][g[S][j]] = v;
					q.push(mp(f[S | (1 << i - 1)][g[S][j]], mp(S | (1 << i - 1), g[S][j])));
				}
			}
			for (int i = j + 1; i <= m; i++) {
				int v = b[j].t + min(mn_key[S][i], dis(b[j].x, b[j].y, b[i].x, b[i].y));
				if (b[i].t >= v) chkmax(g[S][i], g[S][j] + 1);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
/*
2 2
1 1
999 999
1000 1000 1998
0 0 2002
*/