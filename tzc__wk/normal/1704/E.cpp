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
const int MAXN = 1000;
const int MOD = 998244353;
int n, m, a[MAXN + 5];
int hd[MAXN + 5], nxt[MAXN + 5], to[MAXN + 5], ec = 0, deg[MAXN + 5], dp[MAXN + 5];
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void solve() {
	cin >> n >> m; bool flg = 0;
	memset(hd, 0, sizeof(hd)); memset(deg, 0, sizeof(deg));
	memset(dp, 0, sizeof(dp)); ec = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], flg |= (a[i] > 0);
	for (int i = 1, u, v; i <= m; i++) cin >> u >> v, deg[u]++, adde(v, u);
	if (!flg) return puts("0"), void();
	for (int i = 1; i <= m; i++) {
		static int b[MAXN + 5];
		for (int j = 1; j <= n; j++) b[j] = a[j];
		for (int j = 1; j <= n; j++) if (b[j] > 0) b[j]--;
		for (int j = 1; j <= n; j++) for (int e = hd[j]; e; e = nxt[e]) b[j] += (a[to[e]] > 0);
		for (int j = 1; j <= n; j++) a[j] = b[j];
		bool flg = 0;
		for (int j = 1; j <= n; j++) flg |= (a[j] > 0);
		if (!flg) return printf("%d\n", i), void();
	}
	int R = 0;
	for (int i = 1; i <= n; i++) if (!deg[i]) R = i;
	dp[R] = 1; queue<int> q; q.push(R);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			dp[y] = (dp[y] + dp[x]) % MOD;
			if (!--deg[y]) q.push(y);
		}
	}
	int res = m;
	for (int i = 1; i <= n; i++) res = (res + 1ll * a[i] * dp[i]) % MOD;
	printf("%d\n", res);
}
int main() {
	int qu; cin >> qu; while (qu--) solve();
	return 0;
}