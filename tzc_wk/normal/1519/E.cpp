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
const int MAXN = 2e5;
int n;
ll gcd(ll x, ll y) {return (!y) ? x : gcd(y, x % y);}
pair<ll, ll> getslope(pii X, pii Y) {
	pair<ll, ll> res = mp(1ll * Y.fi * X.se, 1ll * Y.se * X.fi);
	ll d = gcd(res.fi, res.se); res.fi /= d; res.se /= d;
	return res;
}
map<pair<ll, ll>, int> id;
int idcnt = 0;
int getid(pii X, pii Y) {
	pair<ll, ll> K = getslope(X, Y);
	if (!id[K]) id[K] = ++idcnt;
	return id[K];
}
int hd[MAXN * 2 + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 1;
void adde(int u, int v) {
//	printf("%d %d\n", u, v);
	to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;
}
bool vis[MAXN + 5], has[MAXN + 5];
int mch[MAXN * 2 + 5]; vector<pii> res;
void dfs(int x, int pre) {
	if (vis[x]) return; vis[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (has[e >> 1]) continue;
		has[e >> 1] = 1;
//		printf("! %d %d\n", y, x);
		if (!vis[y]) dfs(y, e);
		if (mch[y]) res.pb(mp(e >> 1, mch[y])), mch[y] = 0;
		else if (mch[x]) res.pb(mp(e >> 1, mch[x])), mch[x] = 0;
		else mch[x] = e >> 1;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1, a, b, c, d; i <= n; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int u = getid(mp(a + b, b), mp(c, d));
		int v = getid(mp(a, b), mp(c + d, d));
		adde(u, v); adde(v, u);
	}
	for (int i = 1; i <= idcnt; i++) if (!vis[i]) dfs(i, 0);
	printf("%d\n", res.size());
	for (pii p : res) printf("%d %d\n", p.fi, p.se);
	return 0;
}