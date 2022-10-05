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
#ifdef FASTIO
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
using namespace fastio;
#endif
const int MAXN = 1e5;
const int LOG_N = 18;
const int MOD = 1e9 + 9;
const int INF = 0x3f3f3f3f;
int n, k, A, B, C, D; pii p[MAXN + 5];
int key[MAXN + 5]; pii st[LOG_N + 2][MAXN + 5];
pii query_st(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}
struct dat {
	int v0, v1;
	dat() {v0 = v1 = -INF;}
	dat(int _v0, int _v1) {v0 = _v0; v1 = _v1;}
	dat operator + (const dat &rhs) {
		if (rhs.v0 == -INF) return dat(max(v0, v1), v0 + 1);
		if (v0 == -INF) return dat(max(rhs.v0, rhs.v1), rhs.v0 + 1);
		return dat(max(v0, v1) + max(rhs.v0, rhs.v1), max(v0 + max(rhs.v0, rhs.v1), max(v0, v1) + rhs.v0) + 1);
	}
};
struct node {int ch[2], l, r, p; dat v;} s[MAXN * 2 + 5];
int ncnt = 0, rt = 0;
void build(int &k, int l, int r) {
	if (l > r) return; k = ++ncnt; s[k].l = l; s[k].r = r;
	pii pp = query_st(l, r); s[k].p = pp.se;
	build(s[k].ch[0], l, pp.se - 1); build(s[k].ch[1], pp.se + 1, r);
	if (l != r) s[k].v = s[s[k].ch[0]].v + s[s[k].ch[1]].v;
	else s[k].v = dat(0, -INF);
//	printf("build [%d, %d] %d %d\n", l, r, s[k].v.v0, s[k].v.v1);
}
dat query(int k, int l, int r) {
	if (l > r) return dat();
	if (l <= s[k].l && s[k].r <= r) return s[k].v;
	if (r < s[k].p) return query(s[k].ch[0], l, r);
	else if (l > s[k].p) return query(s[k].ch[1], l, r);
	else {
		if (l == r) return dat(0, -INF);
		else return query(s[k].ch[0], l, s[k].p - 1) + query(s[k].ch[1], s[k].p + 1, r);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) scanf("%d%d", &p[i].fi, &p[i].se);
	scanf("%d%d%d%d", &A, &B, &C, &D);
	for (int i = k + 1; i <= n; i++) {
		p[i].fi = (1ll * A * p[i - 1].fi + B) % MOD;
		p[i].se = (1ll * C * p[i - 1].se + D) % MOD;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++) key[i] = p[i].fi;
	for (int i = 1; i <= n; i++) st[0][i] = mp(p[i].se, i);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	build(rt, 1, n); int qu; scanf("%d", &qu);
	while (qu--) {
		int l, r; scanf("%d%d", &l, &r);
		l = lower_bound(key + 1, key + n + 1, l) - key;
		r = upper_bound(key + 1, key + n + 1, r) - key - 1;
		dat res = query(rt, l, r);
		if (l > r) puts("0");
		else printf("%d\n", max(res.v0, res.v1));
	}
	return 0;
}