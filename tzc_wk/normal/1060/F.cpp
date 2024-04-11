// Created time: 2022/4/27 16:42:19
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
const int MAXN = 50;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int siz[MAXN + 5];
ld dp[MAXN + 5][MAXN + 5], C[MAXN + 5][MAXN + 5];
void dfs(int x, int f) {
	siz[x] = 1; dp[x][0] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs(y, x); static ld tmp[MAXN + 5];
		for (int i = 0; i <= MAXN; i++) tmp[i] = 0;
		for (int i = 0; i < siz[x]; i++) for (int j = 0; j <= siz[y]; j++)
			tmp[i + j] += dp[x][i] * dp[y][j] * C[i + j][i] * C[siz[x] - 1 - i + siz[y] - j][siz[y] - j];
		siz[x] += siz[y];
		for (int i = 0; i < siz[x]; i++) dp[x][i] = tmp[i];
	}
	if (f != 0) {
		static ld tmp[MAXN + 5];
		for (int j = 0; j <= MAXN; j++) tmp[j] = 0;
		for (int j = 0; j <= siz[x]; j++) {
			tmp[j] = dp[x][j] * (siz[x] - j);
			for (int k = 0; k < j; k++) tmp[j] += dp[x][k] * 0.5;
		}
		for (int j = 0; j <= siz[x]; j++) dp[x][j] = tmp[j];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	for (int i = 0; i <= MAXN; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0); ld res = dp[i][n - 1];
		for (int j = 1; j < n; j++) res /= j;
		printf("%.10Lf\n", res);
	}
	return 0;
}