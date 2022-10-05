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
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int binom(int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0; int ret = 1;
	for (int i = 1; i <= k; i++) ret = 1ll * ret * (n - i + 1) % MOD * qpow(i, MOD - 2) % MOD;
	return ret;
}
int c[13][13][13], dp[25][13][13][13];
bool check(vector<int> p) {
	if (p.empty()) return 0; int mx = 0;
	for (int i = 0; i + 1 < p.size(); i++) {
		chkmax(mx, p[i]);
		if (mx == i + 1) return 0;
	}
	return 1;
}
void dfs(vector<int> v, int k, int x) {
	// eprintf("dfs {"); for (int x : v) eprintf("%d ", x); eprintf("} %d %d\n", k, x);
	if (k > 11 || x > 11) return;
	if (check(v) && (k || x)) c[v.size()][k][x]++;
	if (v.size() == 12) return;
	for (int i = 1; i <= v.size() + 1; i++) {
		vector<int> tmp = v; tmp.pb(i);
		for (int j = 0; j < v.size(); j++) if (tmp[j] >= i) tmp[j]++;
		int nk = k, nx = x;
		if (v.size() && tmp[tmp.size() - 2] > tmp.back()) nx++;
		for (int j = 0; j < v.size(); j++) nk += (tmp.back() < tmp[j]);
		if (nk > 11 || nx > 11) continue; dfs(tmp, nk, nx);
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	dfs(vector<int>{}, 0, 0);
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= 22; i++) for (int j = 0; j <= 11; j++) for (int k = 0; k <= 11; k++)
		for (int x = 0; x <= 11; x++) if (dp[i][j][k][x])
			for (int jj = 2; jj <= 12 && jj + i <= 22; jj++)
				for (int kk = 0; kk + k <= 11; kk++) for (int xx = 0; xx + x <= 11; xx++)
					dp[i + jj][j + 1][kk + k][xx + x] = (dp[i + jj][j + 1][kk + k][xx + x] + 1ll * dp[i][j][k][x] * c[jj][kk][xx]) % MOD;
	int qu; scanf("%d", &qu);
	while (qu--) {
		int n, k, x, res = 0; scanf("%d%d%d", &n, &k, &x);
		for (int i = 0; i <= min(22, n); i++) for (int j = 0; j <= min(i, 11); j++) if (dp[i][j][k][x]) {
			res = (res + 1ll * dp[i][j][k][x] * binom(n - i + j, j)) % MOD;
		}
		printf("%d\n", res);
	}
	return 0;
}