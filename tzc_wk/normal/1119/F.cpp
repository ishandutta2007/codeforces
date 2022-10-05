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
const int MAXN = 2.5e5;
int n, deg[MAXN + 5]; pii dd[MAXN + 5]; vector<pii> g[MAXN + 5];
bool cmp(pii lhs, pii rhs) {return deg[lhs.fi] > deg[rhs.fi];}
int vis[MAXN + 5], curX;
multiset<ll> dpv[MAXN + 5];
ll sum[MAXN + 5], dp[MAXN + 5][2];
void del_pt(int x) {
//	printf("del %d\n", x);
	for (pii pp : g[x]) {
		if (deg[pp.fi] <= curX) break;
		dpv[pp.fi].insert(pp.se);
//		printf("ins %d\n", pp.fi);
		sum[pp.fi] += pp.se;
	}
}
void dfs(int x, int f) {
	vis[x] = curX; int lim = deg[x] - curX;
//	printf("dfs %d %d %d\n", x, f, lim);
	while (dpv[x].size() > max(lim, 0) && !dpv[x].empty()) {
		ll mxv = *dpv[x].rbegin();
		dpv[x].erase(dpv[x].find(mxv));
		sum[x] -= mxv;
	}
	vector<ll> nd_ins, nd_del; ll ss = 0;
	for (pii pp : g[x]) {
		int y = pp.fi, z = pp.se;
		if (y == f) continue;
		if (deg[y] <= curX) break; dfs(y, x);
		ss += min(dp[y][0], dp[y][1] + z);
		if (dp[y][0] < dp[y][1] + z) {
			dpv[x].insert(dp[y][1] + z - dp[y][0]);
			nd_del.pb(dp[y][1] + z - dp[y][0]);
			sum[x] += dp[y][1] + z - dp[y][0];
		} else --lim;
	}
	while (dpv[x].size() > max(lim, 0) && !dpv[x].empty()) {
		ll val = *dpv[x].rbegin();
		sum[x] -= val; dpv[x].erase(dpv[x].find(val));
		nd_ins.pb(val);
	}
	dp[x][0] = ss + sum[x];
	while (dpv[x].size() > max(lim - 1, 0) && !dpv[x].empty()) {
		ll val = *dpv[x].rbegin();
		sum[x] -= val; dpv[x].erase(dpv[x].find(val));
		nd_ins.pb(val);
	}
	dp[x][1] = ss + sum[x];
//	eprintf("%d %d\n", nd_del.size(), nd_ins.size());
//	printf("DP %d %d %lld %lld %lld\n", x, lim, ss, dp[x][0], dp[x][1]);
	for (ll v : nd_ins) sum[x] += v, dpv[x].insert(v);
	for (ll v : nd_del) sum[x] -= v, dpv[x].erase(dpv[x].find(v));
}
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d", &n); ll sum = 0;
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
		deg[u]++; deg[v]++; sum += w;
	}
	for (int i = 1; i <= n; i++) dd[i] = mp(deg[i], i);
	sort(dd + 1, dd + n + 1);
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), cmp);
	printf("%lld", sum);
	int cur;
	for (curX = 1, cur = 1; curX < n; curX++) {
		while (cur <= n && dd[cur].fi == curX) del_pt(dd[cur].se), cur++;
		ll res = 0;
		for (int i = cur; i <= n; i++) if (vis[dd[i].se] != curX)
			dfs(dd[i].se, 0), res += dp[dd[i].se][0];
		printf(" %lld", res);
	}
	printf("\n");
	return 0;
}
/*
10
2 1 7
3 2 3
4 2 4
5 4 7
6 4 5
7 3 7
8 7 2
9 6 3
10 3 9
*/