// Created time: 2022/7/1 16:21:48
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
const int MAXN = 4e5;
const int MAXV = MAXN * 6;
const int MAXE = MAXN * 30;
int A, B, m, n, l[MAXN + 5], r[MAXN + 5], ncnt;
// A: at least one
// B: at most one
vector<int> ql[MAXN + 5], qr[MAXN + 5];
int pre_r_i[MAXN + 5], pre_r_in[MAXN + 5];
int suf_l_i[MAXN + 5], suf_l_in[MAXN + 5];
int hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dfn[MAXV + 5], low[MAXV + 5], tim;
int stk[MAXV + 5], tp, bel[MAXV + 5], cmp, vis[MAXV + 5];
void tarjan(int x) {
	dfn[x] = low[x] = ++tim; stk[++tp] = x; vis[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (!dfn[y]) tarjan(y), chkmin(low[x], low[y]);
		else if (vis[y]) chkmin(low[x], dfn[y]);
	}
	if (low[x] == dfn[x]) {
		cmp++; int o; do {
			o = stk[tp--]; vis[o] = 0;
			bel[o] = cmp;
		} while (o ^ x);
	}
}
int main() {
	scanf("%d%d%d%d", &A, &n, &m, &B); ncnt = 2 * n;
	while (A--) {
		int x, y; scanf("%d%d", &x, &y);
		adde(x + n, y); adde(y + n, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		ql[l[i]].pb(i); qr[r[i]].pb(i);
	}
	while (B--) {
		int x, y; scanf("%d%d", &x, &y);
		adde(x, y + n); adde(y, x + n);
	}
	for (int i = 1; i <= m; i++) {
		pre_r_i[i] = ++ncnt;
		if (i != 1) adde(pre_r_i[i], pre_r_i[i - 1]);
		for (int id : qr[i]) adde(pre_r_i[i], id);
	}
	for (int i = 1; i <= m; i++) {
		pre_r_in[i] = ++ncnt;
		if (i != 1) adde(pre_r_in[i], pre_r_in[i - 1]);
		for (int id : qr[i]) adde(pre_r_in[i], id + n);
	}
	for (int i = m; i; i--) {
		suf_l_i[i] = ++ncnt;
		if (i != m) adde(suf_l_i[i], suf_l_i[i + 1]);
		for (int id : ql[i]) adde(suf_l_i[i], id);
	}
	for (int i = m; i; i--) {
		suf_l_in[i] = ++ncnt;
		if (i != m) adde(suf_l_in[i], suf_l_in[i + 1]);
		for (int id : ql[i]) adde(suf_l_in[i], id + n);
	}
	for (int i = 1; i <= n; i++) {
		if (l[i] != 1) adde(i, pre_r_in[l[i] - 1]);
		if (r[i] != m) adde(i, suf_l_in[r[i] + 1]);
	}
	for (int i = 1; i <= ncnt; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) if (bel[i] == bel[i + n])
		return puts("-1"), 0;
	vector<int> vec;
	for (int i = 1; i <= n; i++) if (bel[i] < bel[i + n]) vec.pb(i);
	int mx = 1;
	for (int x : vec) chkmax(mx, l[x]);
	printf("%d %d\n", vec.size(), mx);
	for (int x : vec) printf("%d ", x);
	return 0;
}