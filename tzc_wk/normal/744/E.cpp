// Created time: 2022/6/21 20:18:50
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
const int MAXN = 30;
const int MAXM = 1e5;
const int MAXV = MAXM * 2;
const int MAXE = 1e7;
const int BS1 = 191;
const int BS2 = 193;
const int MOD1 = 993244853;
const int MOD2 = 1004535809;
int n, res, len[MAXN + 5]; char s[MAXN + 5][MAXM + 5];
int hs1[MAXN + 5][MAXM + 5], pw1[MAXM + 5];
int hs2[MAXN + 5][MAXM + 5], pw2[MAXM + 5];
u64 gethash(int x, int l, int r) {
	int HS1 = (hs1[x][r] - 1ll * pw1[r - l + 1] * hs1[x][l - 1] % MOD1 + MOD1) % MOD1;
	int HS2 = (hs2[x][r] - 1ll * pw2[r - l + 1] * hs2[x][l - 1] % MOD2 + MOD2) % MOD2;
	return (1ull * HS1) << 32 | HS2;
}
int hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
unordered_map<u64, int> id[2]; int ncnt, EQUAL;
namespace Tarjan {
	int dfn[MAXV + 5], low[MAXV + 5], tim, stk[MAXV + 5], tp, bel[MAXV + 5], vis[MAXV + 5], cmp;
	void init() {
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		tim = cmp = tp = 0;
	}
	void tarjan(int x) {
		dfn[x] = low[x] = ++tim; stk[++tp] = x; vis[x] = 1;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			if (!dfn[y]) tarjan(y), chkmin(low[x], low[y]);
			else if (vis[y]) chkmin(low[x], dfn[y]);
		}
		if (dfn[x] == low[x]) {
			++cmp; int o;
			do {
				o = stk[tp--];
				vis[o] = 0; bel[o] = cmp;
			} while (o ^ x);
		} 
	}
	void work() {for (int i = 1; i <= ncnt; i++) if (!dfn[i]) tarjan(i);}
}
void init() {
	Tarjan :: init();
	memset(hd, 0, sizeof(hd)); ec = 0;
	for (int i = 0; i < 2; i++) id[i].clear();
	ncnt = EQUAL = 0;
}
bool check(int l, int r) {
	init();
	for (int i = l; i <= r; i++) {
		for (int j = 1; j <= len[i]; j++) {
			u64 hs = gethash(i, j, len[i]);
			if (!id[0][hs]) id[0][hs] = ++ncnt;
			if (!id[1][hs]) id[1][hs] = ++ncnt;
		}
	}
	EQUAL = ++ncnt;
	for (int i = l; i <= r; i++) for (int j = 1; j <= len[i]; j++)
		for (int k = l; k <= r; k++) {
			for (int x = 0; x < 2; x++) {
				int A = len[i] - j + 1, B = len[k];
				if (A > B) {
					if (gethash(i, j, j + B - 1) != gethash(k, 1, B)) continue;
					adde(id[x][gethash(i, j, len[i])], id[x][gethash(i, j + B, len[i])]);
				} else if (A == B) {
					if (gethash(i, j, len[i]) != gethash(k, 1, B)) continue;
					adde(id[x][gethash(i, j, len[i])], EQUAL);
				} else {
					if (gethash(i, j, len[i]) != gethash(k, 1, A)) continue;
					adde(id[x][gethash(i, j, len[i])], id[x ^ 1][gethash(k, A + 1, B)]);
				}
			}
		}
	for (int i = l; i <= r; i++) {
		adde(EQUAL, id[0][gethash(i, 1, len[i])]);
		adde(EQUAL, id[1][gethash(i, 1, len[i])]);
	}
	Tarjan :: work();
	for (int i = l; i <= r; i++) {
		for (int j = 1; j < len[i]; j++) {
			if (!id[0].count(gethash(i, 1, j))) continue;
			int X = id[0][gethash(i, 1, j)], Y = id[1][gethash(i, j + 1, len[i])];
			if (Tarjan :: bel[X] == Tarjan :: bel[Y]) return 0;
		}
	}
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = (pw1[0] = pw2[0] = 1); i <= MAXM; i++) {
		pw1[i] = 1ll * pw1[i - 1] * BS1 % MOD1;
		pw2[i] = 1ll * pw2[i - 1] * BS2 % MOD2;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1); len[i] = strlen(s[i] + 1);
		for (int j = 1; j <= len[i]; j++) hs1[i][j] = (1ll * hs1[i][j - 1] * BS1 + s[i][j]) % MOD1;
		for (int j = 1; j <= len[i]; j++) hs2[i][j] = (1ll * hs2[i][j - 1] * BS2 + s[i][j]) % MOD2;
	}
	for (int l = 1, r = 1; l <= n; l++) {
		while (r <= n && check(l, r)) ++r;
		res += r - l;
	}
	printf("%d\n", res);
	return 0;
}