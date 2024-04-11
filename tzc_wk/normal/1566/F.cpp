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
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3fll;
int n, m, a[MAXN + 5];
pii p[MAXN + 5], pp[MAXN + 5];
ll dp[MAXN + 5][2];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[n + 1] = INF; sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) scanf("%d%d", &p[i].fi, &p[i].se);
	sort(p + 1, p + m + 1, [&](pii lhs, pii rhs) {
		return (lhs.fi ^ rhs.fi) ? (lhs.fi < rhs.fi) : (lhs.se > rhs.se);
	});
	int mn = INF, tmp = m; m = 0;
	for (int i = tmp; i; i--) {
		int nt = lower_bound(a + 1, a + n + 1, p[i].fi) - a;
		if (p[i].fi <= a[nt] && a[nt] <= p[i].se) continue;
		if (p[i].se >= mn) continue;
		pp[++m] = p[i]; chkmin(mn, p[i].se);
	}
	if (!m) return puts("0"), void();
	reverse(pp + 1, pp + m + 1);
//	for (int i = 1; i <= m; i++) printf("[%d, %d]\n", pp[i].fi, pp[i].se);
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = INFll;
	ll disL, disR; int l = 1, r = 1;
	disL = (pp[1].se < a[1]) ? (a[1] - pp[1].se) : 0;
	dp[1][0] = disL * 2; dp[1][1] = disL;
	while (r <= m && pp[r].se < a[1]) ++r;
	l = r;
	for (int i = 2; i <= n; i++, l = r) {
		r = l; while (r <= m && pp[r].se < a[i]) ++r;
		for (int j = l; j <= r; j++) {
			disL = (j == l) ? 0 : (pp[j - 1].fi - a[i - 1]);
			disR = (j == r) ? 0 : (a[i] - pp[j].se);
			chkmin(dp[i][0], dp[i - 1][0] + disL + disR * 2);
			chkmin(dp[i][0], dp[i - 1][1] + disL * 2 + disR * 2);
			chkmin(dp[i][1], dp[i - 1][0] + disL + disR);
			chkmin(dp[i][1], dp[i - 1][1] + disL * 2 + disR);
		}
//		printf("DP %d %lld %lld\n", i, dp[i][0], dp[i][1]);
	}
	disR = (pp[m].fi > a[n]) ? (pp[m].fi - a[n]) : 0;
	printf("%lld\n", min(dp[n][0] + disR, dp[n][1] + disR * 2));
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}