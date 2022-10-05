// Created time: 2022/7/13 8:27:46
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
const u64 BS = 131;
const int MOD = 1e9 + 7;
void add(int &x, int y) {((x += y) >= MOD) && (x -= MOD);}
char s[2][MAXN + 5], t[MAXN + 5]; int n, m;
u64 hss[2][MAXN + 5], hss_rv[2][MAXN + 5], hst[MAXN + 5], pw[MAXN + 5];
u64 gethash_s(int x, int l, int r) {return hss[x][r] - hss[x][l - 1] * pw[r - l + 1];}
u64 gethash_srv(int x, int l, int r) {return hss_rv[x][l] - hss_rv[x][r + 1] * pw[r - l + 1];}
u64 gethash_t(int l, int r) {return hst[r] - hst[l - 1] * pw[r - l + 1];}
int dp[2][MAXN + 5][MAXN + 5];
int solve() {
	for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) hss[i][j] = hss[i][j - 1] * BS + s[i][j];
	for (int i = 0; i < 2; i++) for (int j = n; j; j--) hss_rv[i][j] = hss_rv[i][j + 1] * BS + s[i][j];
	memset(dp, 0, sizeof(dp));
	for (int x = 0; x < 2; x++) for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) if (j * 2 + 1 <= m) {
			if (j == 1) continue;
			u64 HS = gethash_srv(x ^ 1, i - j, i - 1) * pw[j + 1] + gethash_s(x, i - j, i);
			if (HS == gethash_t(1, j * 2 + 1)) dp[x][i][j * 2 + 1] = 1;
		}
	}
	for (int j = 1; j < n; j++) for (int i = 0; i < 2; i++) for (int k = 1; k < m; k++) {
		if (s[i][j + 1] == t[k + 1]) add(dp[i][j + 1][k + 1], dp[i][j][k]);
		if (s[i ^ 1][j] == t[k + 1] && s[i ^ 1][j + 1] == t[k + 2]) add(dp[i ^ 1][j + 1][k + 2], dp[i][j][k]);
	}
	int res = 0;
	for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) {
		add(res, dp[i][j][m]);
		for (int l = 0; j + l <= n; l++) if (l * 2 + 1 <= m) {
			u64 HS = gethash_s(i, j + 1, j + l) * pw[l + 1] + gethash_srv(i ^ 1, j, j + l);
			if (HS == gethash_t(m - l * 2, m)) add(res, dp[i][j][m - l * 2 - 1]);
		}
	}
//	printf("%d\n", res);
	return res;
}
int main() {
	for (int i = 0; i < 2; i++) scanf("%s", s[i] + 1); scanf("%s", t + 1);
	n = strlen(s[0] + 1); m = strlen(t + 1);
	if (m == 1) {
		int res = 0;
		for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) res += (s[i][j] == t[1]);
		printf("%d\n", res); return 0;
	} if (m == 2) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += (s[0][i] == t[1] && s[1][i] == t[2]);
			res += (s[0][i] == t[2] && s[1][i] == t[1]);
		}
		for (int i = 0; i < 2; i++) for (int j = 1; j < n; j++) {
			res += (s[i][j] == t[1] && s[i][j + 1] == t[2]);
			res += (s[i][j] == t[2] && s[i][j + 1] == t[1]);
		}
		printf("%d\n", res); return 0;
	}
	for (int i = (pw[0] = 1); i <= MAXN; i++) pw[i] = pw[i - 1] * BS;
	for (int i = 1; i <= m; i++) hst[i] = hst[i - 1] * BS + t[i];
	int res = solve();
	for (int i = 0; i < 2; i++) reverse(s[i] + 1, s[i] + n + 1);
	res = (res + solve()) % MOD;
	printf("%d\n", res);
	return 0;
}
/*
wwwwwwwwwwwwwwwwwwww
wwwwwwwwwwwwwwwwwwww

wwwwwwwwwwwwwwww
*/