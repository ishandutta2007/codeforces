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
const int MAXN = 3e5;
const int LOG_N = 18;
const int INF = 0x3f3f3f3f;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dep[MAXN + 5], fa[MAXN + 5][LOG_N + 2];
void dfs(int x, int f) {
	fa[x][0] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs(y, x);
	}
}
int getlca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = LOG_N; ~i; i--) if (dep[u] - (1 << i) >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = LOG_N; ~i; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int getdis(int u, int v) {return dep[u] + dep[v] - (dep[getlca(u, v)] << 1);}
vector<int> pt[MAXN + 5];
int mxd[MAXN + 5];
void solve() {
	scanf("%d", &n); for (int i = 1; i <= n; i++) hd[i] = 0; ec = 0;
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 0; i <= n; i++) pt[i].clear();
	for (int i = 1; i <= n; i++) pt[dep[i]].pb(i);
	int X = 0, Y = 0, dis = 0;
	for (int i = n; ~i; i--) {
		for (int x : pt[i]) {
			if (!X) X = Y = x;
			else {
				vector<tuple<int, int, int> > vec;
				vec.pb(mt(getdis(X, Y), X, Y));
				vec.pb(mt(getdis(X, x), X, x));
				vec.pb(mt(getdis(Y, x), Y, x));
				sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
				X = get<1>(vec[0]), Y = get<2>(vec[0]), dis = get<0>(vec[0]);
			}
		}
		mxd[i] = (X) ? dis : (-INF);
	}
	for (int i = 1; i <= n; i++) {
		int l = 0, r = n, p = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((mxd[mid + 1] + 1 >> 1) + i <= mid) p = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d%c", p, " \n"[i == n]);
	}
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}