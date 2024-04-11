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
		(*++s) = 0;
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
const int MAXV = 1e6;
int pr[MAXV / 5 + 5], prcnt = 0, vis[MAXV + 5];
void sieve(int n) {
	vis[1] = 2;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1;
			if (i % pr[j] == 0) break;
		}
	}
}
int n, e, a[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &e); ll res = 0;
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[i] = vis[x];
	for (int i = 1; i <= e; i++) {
		int cnt = 0; vector<pii> seg;
		for (int j = i; j <= n; j += e) {
			if (a[j] != 2) seg.pb(mp(cnt, a[j])), cnt = 0;
			else cnt++;
		}
		seg.pb(mp(cnt, 0));
		for (int j = 0; j + 1 < seg.size(); j++) if (seg[j].se == 0)
			res += (1ll * (seg[j].fi + 1) * (seg[j + 1].fi + 1) - 1);
//		printf("i = %d\n", i);
//		for (pii p : seg) printf("%d %d\n", p.fi, p.se);
	}
	printf("%lld\n", res);
}
int main() {
	sieve(MAXV); int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}