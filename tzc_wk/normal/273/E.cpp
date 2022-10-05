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
const int MAXN = 1000;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int n, lim, cnt[3];
vector<pair<pii, int> > vec;
int getmex(int x, int y) {
	static bool vis[4]; fill0(vis); vis[x] = vis[y] = 1;
	int cur = 0; while (vis[cur]) ++cur; return cur;
}
void insback(int l, int r, int v) {
	if (vec.back().se == v) chkmax(vec[vec.size() - 1].fi.se, r);
	else vec.pb(mp(mp(l, r), v));
}
int dp[MAXN + 5][4];
int main() {
	vec.pb(mp(mp(0, 2), 0));
	vec.pb(mp(mp(3, 3), 1));
	for (int i = 0; i < vec.size(); i++) {
		int p0 = 2 * vec[i].fi.fi, p1 = 2 * vec[i].fi.se + 2;
//		printf("! %d %d\n", p0, p1);
		int pos = upper_bound(vec.begin(), vec.end(), mp(mp(p0 + 1, 0), 0)) - vec.begin() - 1;
		while (pos < vec.size()) {
			int L = vec[pos].fi.fi, R = vec[pos].fi.se;
			chkmax(L, p0); chkmin(R, p1); if (L > R) break;
			int cl = max((L - 1) / 2, vec[i].fi.fi), cr = min(R / 2, vec[i].fi.se);
			int _L = cl + L, _R = cr + R; chkmin(_R, INF);
//			printf("%d %d %d %d\n", cl, cr, L, R);
			chkmax(_L, vec.back().fi.fi + 1);
			if (_L <= _R) insback(_L, _R, getmex(vec[i].se, vec[pos].se));
			++pos;
		}
	}
	scanf("%d%d", &n, &lim);
	for (auto p : vec) {
		if (p.fi.fi <= lim) {
			int l = max(p.fi.fi, 1), r = min(p.fi.se, lim - 1);
			int L = lim - r, R = lim - l;
			cnt[p.se] = (cnt[p.se] + 1ll * (L + R) * (R - L + 1) / 2) % MOD;
		}
	}
//	for (int i = 0; i < 3; i++) printf("%d\n", cnt[i]);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 3; k++)
		dp[i + 1][j ^ k] = (dp[i + 1][j ^ k] + 1ll * dp[i][j] * cnt[k]) % MOD;
	int res = 0;
	for (int i = 1; i < 4; i++) res = (res + dp[n][i]) % MOD;
	printf("%d\n", res);
	return 0;
}