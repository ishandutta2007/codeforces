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
const int B = 316;
const int NUMP = 700;
const int LIM = 350;
int n, m, hd[MAXN + 5], to[MAXN + 5], nxt[MAXN + 5], ec = 0, t[MAXN + 5];
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int q[MAXN + 5]; bool is[MAXN + 5];
namespace virt_builder {
	bool vis[MAXN + 5], ont[MAXN + 5];
	vector<int> g[MAXN + 5];
	// vis: whether i is a key point
	// ont: whether i is on (is a key point or on one of the edges) the virtual tree
	int dw[MAXN + 5];
	int dfs_build(int x) {
		int G = 0, two = 0; ont[x] = vis[x];
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = dfs_build(y);
			if (z) {
				if (G) two = 1, g[x].pb(z);
				else G = z;
			}
		}
		if (!G) return (vis[x]) ? x : 0;
		else {
			ont[x] = 1;
			if (two) return vis[x] = 1, g[x].pb(G), x;
			else {
				if (vis[x]) return g[x].pb(G), x;
				else return dw[x] = G;
			}
		}
	}
}
using namespace virt_builder;
int siz[MAXN + 5];
void dfsclc(int x) {
	siz[x] = is[x];
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; dfsclc(y);
		siz[x] += siz[y];
	}
}
int fa_vt[MAXN + 5];
void dfs_vt(int x, int f) {
	fa_vt[x] = f;
	for (int y : g[x]) dfs_vt(y, x);
}
int id[MAXN + 5], idcnt = 0, pt[NUMP + 5];
int sum[NUMP + 5][NUMP + 5], mark[MAXN + 5];
bool occ[MAXN + 5];
void clear() {
	memset(vis, 0, sizeof(vis)); memset(ont, 0, sizeof(ont));
	for (int i = 1; i <= n; i++) g[i].clear();
	memset(sum, 0, sizeof(sum)); memset(mark, 0, sizeof(mark));
	memset(occ, 0, sizeof(occ)); idcnt = 0;
}
void deal(int l, int r) {
	clear();
	for (int i = l; i <= r; i++) vis[abs(q[i])] = occ[abs(q[i])] = 1;
	vis[1] = 1; dfs_build(1); dfsclc(1); dfs_vt(1, 0);
	for (int i = 1; i <= n; i++) if (vis[i]) id[i] = ++idcnt, pt[idcnt] = i;
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (!ont[i]) num += (siz[i] > t[i] && !occ[i] && !is[i]);
		else if (!vis[i] && !occ[i] && !is[i]) {
			int j = dw[i], lim = t[i] - siz[i] + 1;
			chkmin(lim, LIM); chkmax(lim, -LIM);
			sum[id[j]][lim + LIM]++;
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d%c", vis[i], " \n"[i == n]);
//	printf("key points:\n");
//	for (int i = 1; i <= idcnt; i++) printf("%d%c", pt[i], " \n"[i == idcnt]);
	for (int i = 1; i <= idcnt; i++) for (int j = 1; j <= LIM * 2; j++)
		sum[i][j] += sum[i][j - 1];
	vector<int> occ_pts;
	for (int i = 1; i <= n; i++) if (occ[i]) occ_pts.pb(i);
	for (int i = l; i <= r; i++) {
		int coef = (q[i] > 0) ? 1 : -1, cur = abs(q[i]), cnt = 0;
		while (cur) mark[cur] += coef, cur = fa_vt[cur];
		for (int j = 1; j <= idcnt; j++) {
			cnt += (siz[pt[j]] + mark[pt[j]] > t[pt[j]] && !occ[pt[j]] && !is[pt[j]]);
			cnt += sum[j][mark[pt[j]] + LIM];
		}
		if (q[i] > 0) is[q[i]] = 1; else is[-q[i]] = 0;
		for (int p : occ_pts) if (!is[p] && siz[p] + mark[p] > t[p]) cnt++;
		printf("%d ", cnt + num);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2, fa; i <= n; i++) scanf("%d", &fa), adde(fa, i);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &q[i]);
	for (int i = 1; i <= (m - 1) / B + 1; i++) {
		int L = (i - 1) * B + 1, R = min(i * B, m);
		deal(L, R);
	}
	return 0;
}