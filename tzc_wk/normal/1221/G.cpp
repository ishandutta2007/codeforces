// Created time: 2022/4/27 8:33:31
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
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
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
const int MAXN = 40;
const int MAXM = 780;
const int MAXP = 1048576;
int n, m, deg[MAXN + 5], lim; pii e[MAXM + 5];
int hd[MAXN + 5], to[MAXM * 2 + 5], nxt[MAXM * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int msk1[MAXN + 5], msk2[MAXN + 5], msk3[MAXN + 5];
ll calc0() {
	for (int i = 1; i <= m; i++) {
		if (e[i].fi <= lim && e[i].se <= lim) {
			msk1[e[i].fi] |= (1 << e[i].se - 1);
			msk1[e[i].se] |= (1 << e[i].fi - 1);
		} else if (e[i].fi > lim && e[i].se > lim) {
			msk2[e[i].fi] |= (1 << e[i].se - lim - 1);
			msk2[e[i].se] |= (1 << e[i].fi - lim - 1);
		} else msk3[e[i].fi] |= (1 << e[i].se - 1);
	}
	static int F[MAXP + 5];
	for (int i = 0; i < (1 << lim); i++) {
		bool flg = 1;
		for (int j = 1; j <= lim; j++) if (~i >> (j - 1) & 1)
			flg &= ((~i) & msk1[j]) == 0;
		F[i] = flg;
	}
	for (int i = 1; i <= lim; i++) for (int j = 0; j < (1 << lim); j++)
		if (~j >> (i - 1) & 1) F[j] += F[j ^ (1 << i - 1)];
	ll res = 0;
	for (int i = 0; i < (1 << n - lim); i++) {
		bool flg = 1; int msk = 0;
		for (int j = lim + 1; j <= n; j++) if (~i >> (j - lim - 1) & 1)
			flg &= (msk2[j] & (~i)) == 0, msk |= msk3[j];
		if (flg) res += F[msk];
	}
	return res;
}
ll calc1() {
	static int f[MAXN + 5]; int cmp = n;
	function<int(int)> find = [&](int x) {return (!f[x]) ? x : f[x] = find(f[x]);};
	function<void(int, int)> merge = [&](int x, int y) {x = find(x); y = find(y); if (x ^ y) f[x] = y, cmp--;};
	for (int i = 1; i <= m; i++) merge(e[i].fi, e[i].se);
	return 1ll << cmp;
}
ll calc01() {
	ll prd = 1;
	for (int i = 1; i <= n; i++) if (!deg[i]) prd <<= 1;
	return prd;
}
ll calc02() {
	ll prd = 1; bool flg = 1;
	static int col[MAXN + 5];
	function<void(int, int)> dye = [&](int x, int c) {
		if (~col[x]) {
			if (col[x] != c) flg = 0;
			return;
		}
		col[x] = c;
		for (int e = hd[x]; e; e = nxt[e]) dye(to[e], c ^ 1);
	};
	memset(col, -1, sizeof(col));
	for (int i = 1; i <= n; i++) if (!~col[i]) dye(i, 0), prd <<= 1;
	return (flg) ? prd : 0;
}
ll calc012() {return (!m) ? (1ll << n) : 0;}
int main() {
	scanf("%d%d", &n, &m); lim = n >> 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &e[i].fi, &e[i].se);
		adde(e[i].fi, e[i].se); adde(e[i].se, e[i].fi);
		deg[e[i].fi]++; deg[e[i].se]++;
		if (e[i].fi < e[i].se) swap(e[i].fi, e[i].se);
	}
	ll res = 1ll << n;
	res -= calc0() * 2; res -= calc1();
	res += calc01() * 2; res += calc02();
	res -= calc012();
	printf("%lld\n", res);
	return 0;
}