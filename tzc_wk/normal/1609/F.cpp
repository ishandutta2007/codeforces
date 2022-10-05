#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
		x = 0; char c = getc();
		while (!isdigit(c)) c = getc();
		while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
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
using namespace fastio;
const int MAXN = 1e6;
const int LOG_V = 62;
int n, c[MAXN + 5], cnt[LOG_V + 2]; ll a[MAXN + 5];
struct node {int l, r, mx, mxc, lz;} s[MAXN * 4 + 5];
void pushup(int k) {
	s[k].mx = max(s[k << 1].mx, s[k << 1 | 1].mx); s[k].mxc = 0;
	if (s[k].mx == s[k << 1].mx) s[k].mxc += s[k << 1].mxc;
	if (s[k].mx == s[k << 1 | 1].mx) s[k].mxc += s[k << 1 | 1].mxc;
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].mx = s[k].lz = 0; s[k].mxc = r - l + 1;
	if (l == r) return; int mid = l + r >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void tag(int k, int v) {s[k].mx += v; s[k].lz += v;}
void pushdown(int k) {
	if (s[k].lz) tag(k << 1, s[k].lz), tag(k << 1 | 1, s[k].lz), s[k].lz = 0;
}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return tag(k, v), void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
struct opt {int p, l, r, v;};
vector<opt> qv[LOG_V + 2];
int main() {
	read(n); ll res = 0;
	for (int i = 1; i <= n; i++) {
		read(a[i]), c[i] = __builtin_popcountll(a[i]);
		cnt[c[i]]++;
	}
	static int stk_mn[MAXN + 5], stk_mx[MAXN + 5];
	int mn_tp = 1, mx_tp = 1;
	for (int j = 1; j <= n; j++) {
		while (mn_tp > 1 && a[stk_mn[mn_tp]] > a[j]) {
			int p = stk_mn[mn_tp--];
			qv[c[p]].pb({j, stk_mn[mn_tp] + 1, p, -1});
		}
		qv[c[j]].pb({j, stk_mn[mn_tp] + 1, j, 1});
		while (mx_tp > 1 && a[stk_mx[mx_tp]] <= a[j]) {
			int p = stk_mx[mx_tp--];
			qv[c[p]].pb({j, stk_mx[mx_tp] + 1, p, -1});
		}
		qv[c[j]].pb({j, stk_mx[mx_tp] + 1, j, 1});
		stk_mx[++mx_tp] = j; stk_mn[++mn_tp] = j;
	}
	for (int i = 0; i <= LOG_V; i++) {
		if (!cnt[i]) continue; build(1, 1, n);
		for (int j = 1, cur = 0; j <= n; j++) {
			while (cur < qv[i].size() && qv[i][cur].p <= j) {
				modify(1, qv[i][cur].l, qv[i][cur].r, qv[i][cur].v);
				cur++;
			}
			if (s[1].mx == 2) res += s[1].mxc;
		}
	}
	printf("%lld\n", res);
	return 0;
}//