// Created time: 2022/7/17 15:32:47
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
const int MAXN = 2000;
int n, mod, res[MAXN + 5], hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dp[MAXN + 5][MAXN + 5], sum[MAXN + 5][MAXN + 5], c[MAXN + 5][MAXN + 5];
void dfs(int x, int f) {
	vector<int> son; son.pb(0);
	static int pre[MAXN + 5][MAXN + 5], suf[MAXN + 5][MAXN + 5], ss[MAXN + 5][MAXN + 5];
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		son.pb(y); dfs(y, x);
	}
	int soncnt = son.size() - 1;
	for (int i = 0; i <= n; i++) {
		pre[i][0] = suf[i][soncnt + 1] = 1;
		for (int j = 1; j <= soncnt; j++) pre[i][j] = 1ll * pre[i][j - 1] * sum[son[j]][i] % mod;
		for (int j = soncnt; j; j--) suf[i][j] = 1ll * suf[i][j + 1] * sum[son[j]][i] % mod;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= soncnt; j++)
		ss[i][j] = (ss[i - 1][j] + 1ll * pre[i][j - 1] * suf[i][j + 1]) % mod;
	if (x != 1) {
		for (int i = 1; i <= n; i++) for (int k = 1; k <= soncnt; k++) {
			dp[x][i] = (dp[x][i] + 1ll * pre[i - 1][k - 1] * suf[i][k + 1] % mod * dp[son[k]][i]) % mod;
			dp[x][i] = (dp[x][i] + 1ll * ss[i - 1][k] * dp[son[k]][i]) % mod;
		}
	}
	for (int i = 1; i <= n; i++) dp[x][i] = (dp[x][i] + pre[i - 1][soncnt]) % mod;
	for (int i = 1; i <= n; i++) sum[x][i] = (sum[x][i - 1] + dp[x][i]) % mod;
//	for (int i = 1; i <= n; i++) printf("dp[%d][%d] = %d\n", x, i, dp[x][i]);
}
int main() {
	scanf("%d%d", &n, &mod);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	for (int i = 0; i < n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	dfs(1, 0); for (int i = 1; i < n; i++) res[i] = dp[1][i + 1];
	for (int i = 1; i < n; i++) for (int j = 1; j < i; j++)
		res[i] = (res[i] - 1ll * res[j] * c[i][j] % mod + mod) % mod;
	for (int i = 1; i < n; i++) printf("%d ", res[i]);
	return 0;
}