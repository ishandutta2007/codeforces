// Created time: 2022/5/3 13:32:36
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
const int MAXN = 1.5e5;
int n, m, ok[MAXN + 5], nt[MAXN + 5];
int hd[MAXN + 5], to[MAXN * 3 + 5], nxt[MAXN * 3 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dp[MAXN + 5][2];
void clear() {
	memset(ok, 0, sizeof(ok)); memset(nxt, 0, sizeof(nxt));
	memset(hd, 0, sizeof(hd)); ec = 0; memset(dp, 0, sizeof(dp));
}
void solve() {
	scanf("%d%d", &n, &m); clear();
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		if (v == u + 1) ok[u] = 1;
		else adde(v, u);
	}
	for (int i = 1; i < n; i++) adde(n + 1, i);
	for (int i = 2; i <= n; i++) adde(i, 0);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) if (!ok[i]) R = i + 1;
	for (int i = n; i; i--) if (!ok[i]) L = i;
	if (L == n) return printf("%lld\n", 1ll * n * (n - 1) / 2), void();
	for (int i = n; i; i--) nt[i] = (ok[i]) ? nt[i + 1] : i;
	dp[L + 1][0] = 1; dp[L + 1][1] = 2;
	for (int i = L + 2; i <= n + 1; i++) {
		for (int e = hd[i]; e; e = nxt[e]) {
			int j = to[e];
			for (int o = 0; o < 2; o++) if (nt[j + 1] >= i - 1)
				dp[i][o] |= dp[j + 1][o ^ 1];
		}
	}
	for (int i = L + 1; i; i--) {
		for (int e = hd[i]; e; e = nxt[e]) {
			int j = to[e];
			for (int o = 0; o < 2; o++) if (nt[j + 1] >= i - 1)
				dp[j + 1][o ^ 1] |= dp[i][o];
		}
	}
	static int c1[4], c2[4];
	memset(c1, 0, sizeof(c1)); memset(c2, 0, sizeof(c2));
	for (int i = 1; i <= L + 1; i++) c1[dp[i][0]]++;
	for (int i = R; i <= n + 1; i++) c2[dp[i][0]]++;
	ll res = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
		if (i & j) res += 1ll * c1[i] * c2[j];
	if (L + 1 == R) res--;
	printf("%lld\n", res);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}