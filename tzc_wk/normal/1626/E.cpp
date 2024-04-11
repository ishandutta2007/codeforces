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
const int MAXN = 3e5;
int n, c[MAXN + 5], hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int siz[MAXN + 5], tot = 0, fa[MAXN + 5];
bool has[MAXN + 5], has_out[MAXN + 5];
int adj_blk[MAXN + 5], ok[MAXN + 5], ok_out[MAXN + 5];
void dfs1(int x, int f) {
	siz[x] = c[x]; fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue; dfs1(y, x);
		has[x] |= has[y]; siz[x] += siz[y];
	}
	has[x] |= (siz[x] >= 2 && c[x]);
}
void dfs2(int x, int f) {
	int tot_has = 0;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (y == f) tot_has += has_out[x];
		else tot_has += has[y];
	}
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		has_out[y] = !!(tot_has - has[y]);
		has_out[y] |= (c[y] && (tot - siz[x]));
		dfs2(y, x);
	}
}
void dfs3(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		ok_out[y] += ok_out[x]; dfs3(y, x);
		ok[x] += ok[y];
	}
}
bool has_pth[MAXN + 5];
void dfs4(int x, int f) {
	int sum = 0;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		sum += ok[y];
	}
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		has_pth[y] = has_pth[x] | (sum - ok[y] > 0);
		dfs4(y, x);
	}
}
int main() {
	scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &c[i]), tot += c[i];
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	for (int i = 1; i <= n; i++) for (int e = hd[i]; e; e = nxt[e])
		adj_blk[i] += c[to[e]];
	dfs1(1, 0); dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		ok[i] = ((adj_blk[i] > 0) && siz[i] >= 2);
		ok_out[i] = ((adj_blk[fa[i]] > 0) && (tot - siz[i] >= 2));
	}
	dfs3(1, 0); dfs4(1, 0);
	for (int x = 1; x <= n; x++) {
		int res = c[x];
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e]; res |= c[y];
			if (y == fa[x]) {
				res |= has_out[x];
				res |= (ok_out[x] > 0);
				res |= has_pth[x];
			} else {
				res |= has[y];
				res |= (ok[y] > 0);
			}
		}
		printf("%d ", res);
	}
	return 0;
}
/*
6
0 0 0 0 1 1
1 2
2 3
3 4
4 5
4 6
*/