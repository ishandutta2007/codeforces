// Created time: 2022/6/16 14:16:21
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
const int MAXV = 5e5;
const int MAXE = 1e7;
int n, m, k, hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], ec = 0, lim;
void adde(int u, int v) {
//	printf("adde %d %d\n", u, v);
	to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;
}
int getid(int x, int y) {return (x - 1) * (k + 1) + y + 1;}
int dfn[MAXV + 5], low[MAXV + 5], tim;
int bel[MAXV + 5], cmp, vis[MAXV + 5], stk[MAXV + 5], tp = 0;
void tarjan(int x) {
	dfn[x] = low[x] = ++tim; stk[++tp] = x; vis[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (!dfn[y]) tarjan(y), chkmin(low[x], low[y]);
		else if (vis[y]) chkmin(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		cmp++; int o; do {
			o = stk[tp--]; vis[o] = 0;
			bel[o] = cmp;
		} while (o ^ x);
	}
}
void clear() {
	for (int i = 1; i <= lim * 2; i++) hd[i] = dfn[i] = low[i] = bel[i] = 0;
	ec = cmp = tp = tim = 0;
}
void solve() {
	scanf("%d%d%d", &n, &m, &k); lim = n * (k + 1); clear();
	for (int i = 1; i <= n; i++) {
		adde(getid(i, 0), getid(i, 0) + lim);
		adde(getid(i, k) + lim, getid(i, k));
		for (int j = 0; j < k; j++) {
			adde(getid(i, j), getid(i, j + 1));
			adde(getid(i, j + 1) + lim, getid(i, j) + lim);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			adde(getid(i + 1, j), getid(i, j));
			adde(getid(i, j) + lim, getid(i + 1, j) + lim);
		}
	}
	while (m--) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int id, x; scanf("%d%d", &id, &x);
			adde(getid(id, x), getid(id, x - 1));
			adde(getid(id, x - 1) + lim, getid(id, x) + lim);
		} else if (opt == 2) {
			int p, q, x; scanf("%d%d%d", &p, &q, &x);
			for (int i = 0; i < k; i++) {
				int mx = x - i - 1;
				if (mx <= 0) {
					adde(getid(p, i) + lim, getid(p, i));
					adde(getid(q, i) + lim, getid(q, i));
				} else if (mx <= k) {
					adde(getid(p, i) + lim, getid(q, mx));
					adde(getid(q, i) + lim, getid(p, mx));
				}
			}
		} else {
			int p, q, x; scanf("%d%d%d", &p, &q, &x);
			for (int i = 1; i <= k; i++) {
				int mn = x - i;
				if (mn > k) {
					adde(getid(p, i), getid(p, i) + lim);
					adde(getid(q, i), getid(q, i) + lim);
				} else if (mn > 0) {
					adde(getid(p, i), getid(q, mn - 1) + lim);
					adde(getid(q, i), getid(p, mn - 1) + lim);
				}
			}
		}
	}
	for (int i = 1; i <= lim * 2; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= lim; i++) if (bel[i] == bel[i + lim])
		return puts("-1"), void();
//	for (int i = 1; i <= n; i++) for (int j = 1; j <= k; j++)
//		printf("%d%c", bel[getid(i, j)] < bel[getid(i, j) + lim], " \n"[j == k]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (bel[getid(i, j)] < bel[getid(i, j) + lim] && bel[getid(i, j - 1)] > bel[getid(i, j - 1) + lim]) {
				printf("%d ", j); break;
			}
		}
	}
	printf("\n");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}