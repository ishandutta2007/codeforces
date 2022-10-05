// Created time: 2022/5/5 15:01:42
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
const int MAXN = 1e3;
const int MAXM = 2e3;
int n, m, a[MAXN + 5], b[MAXN + 5];
int hd[MAXN + 5], to[MAXM * 2 + 5], nxt[MAXM * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
bool vis[MAXN + 5], rch[MAXN + 5]; ll cur;
bool calc(int x, int f) {
	if (vis[x] || rch[x]) return 1;
	if (cur <= a[x]) return 0;
	cur += b[x]; vis[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		if (calc(y, x)) {vis[x] = 0; rch[x] = 1; return 1;}
	}
	cur -= b[x]; vis[x] = 0;
	return 0;
}
bool check(int mid) {
	memset(vis, 0, sizeof(vis)); memset(rch, 0, sizeof(rch));
	rch[1] = 1; cur = mid;
	while (1) {
		bool flg = 0;
		for (int i = 1; i <= n; i++) if (rch[i]) {
			for (int e = hd[i]; e; e = nxt[e]) if (!rch[to[e]]) {
				if (calc(to[e], i)) {flg = 1; break;}
			}
			if (flg) break;
		}
		if (!flg) return 0; int sum = 0;
		for (int i = 1; i <= n; i++) sum += rch[i];
		if (sum == n) return 1;
	}
}
void solve() {
	scanf("%d%d", &n, &m); memset(hd, 0, sizeof(hd)); ec = 0;
	for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	int l = 0, r = 1e9 + 1, p = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", p);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();	
	return 0;
}