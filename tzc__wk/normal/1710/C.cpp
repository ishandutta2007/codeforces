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
const int MAXN = 2e5;
const int MOD = 998244353;
void add(int &x, int v) {((x += v) >= MOD) && (x -= MOD);}
char s[MAXN + 5]; int n, dp[MAXN + 5][8][8], res;
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	dp[0][7][0] = 1;
	for (int i = 1; i <= n; i++) for (int j = 0; j < 8; j++) for (int k = 0; k < 8; k++)
		if (dp[i - 1][j][k]) {
			int up = 0;
			for (int l = 0; l < 3; l++) up |= ((j >> l & 1) ? (s[i] - '0') : 1) << l;
//			printf("! %d %d %d %d\n", i, j, k, up);
			for (int l = 0; l < 8; l++) if ((up & l) == l) {
				int nwk = k;
				if (l == 6 || l == 1) nwk |= 1;
				if (l == 5 || l == 2) nwk |= 2;
				if (l == 3 || l == 4) nwk |= 4;
				if (s[i] == '1') add(dp[i][j & l][nwk], dp[i - 1][j][k]);
				else add(dp[i][j][nwk], dp[i - 1][j][k]);
			}
		}
	for (int i = 0; i < 8; i++) add(res, dp[n][i][7]);
	printf("%d\n", res);
	return 0;
}