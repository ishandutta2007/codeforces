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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
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
const int MAXN = 1e7;
const int MAXP = 8388608;
int qpow(int x, int e, int mod) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % mod)
		if (e & 1) ret = 1ll * ret * x % mod;
	return ret;
}
int n, m, t, w, qu, b = 1, a[MAXN + 5], lg, hib[MAXP + 5];
int val[MAXP + 5], cnt[MAXP + 5];
struct dat {
	int opt, pos, v;
	dat() {opt = pos = v = 0;}
	dat(int V, int C) {
		if (!C) opt = 1, pos = V, v = 0;
		else opt = 0, pos = 0, v = (C - 1) * w;
	}
	friend dat operator ^ (const dat &X, const dat &Y) { // xor convolution
		dat ret;
		if (X.opt == 2 || Y.opt == 2) ret.opt = 2;
		else if (X.opt == 1 && Y.opt == 1) ret.opt = 1, ret.pos = X.pos ^ Y.pos, ret.v = X.v + Y.v;
		else {
			ret.opt = 0;
			if (!X.opt && !Y.opt) ret.v = X.v + Y.v + w;
			else ret.v = X.v + Y.v;
		}
		return ret;
	}
	friend dat operator * (const dat &X, const dat &Y) { // dot
		dat ret;
		if (X.opt == 2 || Y.opt == 2) ret.opt = 2;
		else if (X.opt == 1 && Y.opt == 1) {
			if (X.pos != Y.pos) ret.opt = 2;
			else ret.opt = 1, ret.pos = X.pos, ret.v = X.v + Y.v;
		}
		else if (X.opt == 0 && Y.opt == 0) ret.opt = 0, ret.v = X.v + Y.v;
		else ret.opt = 1, ret.pos = X.pos + Y.pos, ret.v = X.v + Y.v;
		return ret;
	}
};
int rev[MAXP + 5];
struct node {int l, r; dat v;} s[MAXP * 2 + 5];
void pushup(int k) {
	if (t >> hib[k] & 1) s[k].v = s[k << 1].v * s[k << 1 | 1].v;
	else s[k].v = s[k << 1].v ^ s[k << 1 | 1].v;
}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].v = dat(val[rev[l]], cnt[rev[l]]), void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void modify(int k, int p) {
	if (s[k].l == s[k].r) return s[k].v = dat(val[rev[p]], cnt[rev[p]]), void();
	int mid = s[k].l + s[k].r >> 1;
	if (p <= mid) modify(k << 1, p); else modify(k << 1 | 1, p);
	pushup(k);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	for (int i = 2; i <= MAXP; i++) hib[i] = hib[i >> 1] + 1;
	scanf("%d%d%d%d", &n, &m, &t, &w); int tmp = n;
	while (tmp % 2 == 0) tmp >>= 1, b <<= 1, lg++; memset(a, -1, sizeof(a));
	for (int i = 0; i < b; i++) cnt[i] = n / b, val[i] = 0;
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y); --x; a[x] = y;
		cnt[x & (b - 1)]--; val[x & (b - 1)] ^= y;
	}
	if (t >= b) {
		int sum = 0, ban = 0;
		for (int i = 0; i < b; i++) {
			if (!cnt[i] && val[i]) ban++;
			sum += max(cnt[i] - 1, 0);
		}
		scanf("%d", &qu);
		while (qu--) {
			int x, y, mod; scanf("%d%d%d", &x, &y, &mod); --x;
			if (!cnt[x & (b - 1)] && val[x & (b - 1)]) ban--;
			sum -= max(cnt[x & (b - 1)] - 1, 0);
			if (~a[x]) cnt[x & (b - 1)]++, val[x & (b - 1)] ^= a[x];
			a[x] = y;
			if (~a[x]) cnt[x & (b - 1)]--, val[x & (b - 1)] ^= a[x];
			if (!cnt[x & (b - 1)] && val[x & (b - 1)]) ban++;
			sum += max(cnt[x & (b - 1)] - 1, 0);
			if (ban) puts("0"); else printf("%d\n", qpow(2, w * sum, mod));
		}
	} else {
		for (int i = 0; i < b; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
		// for (int i = 0; i < b; i++) printf("%d ", rev[i]); printf("\n");
		// printf("%d\n", b);
		build(1, 0, b - 1); scanf("%d", &qu);
		while (qu--) {
			int x, y, mod; scanf("%d%d%d", &x, &y, &mod); --x;
			if (~a[x]) cnt[x & (b - 1)]++, val[x & (b - 1)] ^= a[x];
			a[x] = y;
			if (~a[x]) cnt[x & (b - 1)]--, val[x & (b - 1)] ^= a[x];
			modify(1, rev[x & (b - 1)]);
			if (s[1].v.opt == 2) puts("0");
			else printf("%d\n", qpow(2, s[1].v.v + ((s[1].v.opt == 1) ? 0 : w), mod));
		}
	}
	return 0;
}