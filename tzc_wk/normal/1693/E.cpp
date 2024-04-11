// Created time: 2022/6/29 10:13:27
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
const int MAXN = 2e5;
int n, a[MAXN + 5], state[MAXN + 5];
struct dat {
	int a[3], b[3];
	dat() {memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));}
	dat(int A0, int A1, int A2, int B0, int B1, int B2) {
		a[0] = A0; a[1] = A1; a[2] = A2;
		b[0] = B0; b[1] = B1; b[2] = B2;
	}
	friend dat operator + (const dat &X, const dat &Y) {
		dat res;
		for (int i = 0; i < 3; i++) {
			res.a[i] = X.a[Y.a[i]];
			res.b[i] = Y.b[i] + X.b[Y.a[i]];
		}
		return res;
	}
} E[4];
struct node {int l, r; dat v;} s[MAXN * 4 + 5];
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return s[k].v = E[0], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	s[k].v = s[k << 1].v + s[k << 1 | 1].v;
}
void upd(int k, int p, int v) {
	if (s[k].l == s[k].r) return s[k].v = E[state[p] += v], void();
	int mid = s[k].l + s[k].r >> 1;
	if (p <= mid) upd(k << 1, p, v); else upd(k << 1 | 1, p, v);
	s[k].v = s[k << 1].v + s[k << 1 | 1].v;
}
dat query(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return s[k].v;
	int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) return query(k << 1, l, r);
	else if (l > mid) return query(k << 1 | 1, l, r);
	else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
}
int cnt[2][MAXN + 5]; ll res = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	E[0] = dat(0, 1, 2, 0, 0, 0); E[1] = dat(1, 1, 0, 0, 0, 1);
	E[2] = dat(2, 0, 2, 0, 1, 0); E[3] = dat(0, 0, 0, 1, 1, 1);
	build(1, 0, n); upd(1, 0, 3); state[0] = 3;
	for (int i = 1; i <= n; i++) cnt[1][a[i]]++;
	for (int i = 1; i <= n; i++) if (cnt[1][i]) upd(1, i, 2);
	for (int i = 1; i <= n; i++) {
		cnt[1][a[i]]--; if (!cnt[1][a[i]] && a[i]) upd(1, a[i], -2);
		if (a[i]) res += query(1, 0, a[i] - 1).b[0];
		cnt[0][a[i]]++; if (cnt[0][a[i]] == 1 && a[i]) upd(1, a[i], 1);
	}
	printf("%lld\n", res);
	return 0;
}