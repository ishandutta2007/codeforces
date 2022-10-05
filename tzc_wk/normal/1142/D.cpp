// Created time: 2022/4/29 16:26:05
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
const int MAXN = 1e5;
int rnk[10005], cnt = 9, trs[12][12];
int n, dp[MAXN + 5][12]; char s[MAXN + 5];
int main() {
	memset(trs, -1, sizeof(trs));
	for (int i = 1; i <= 9; i++) rnk[i] = i;
	for (int i = 10; i <= 10000; i++) {
		if (!rnk[i / 10]) continue;
		if (i % 10 >= rnk[i / 10] % 11) continue;
		rnk[i] = ++cnt;
		if (trs[rnk[i / 10] % 11][i % 10] == -1) trs[rnk[i / 10] % 11][i % 10] = rnk[i] % 11;
		else assert(trs[rnk[i / 10] % 11][i % 10] == rnk[i] % 11);
	}
	scanf("%s", s + 1); n = strlen(s + 1); ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 11; j++) if (~trs[j][s[i] - '0'])
			dp[i][trs[j][s[i] - '0']] += dp[i - 1][j];
		dp[i][s[i] - '0']++;
		for (int j = 0; j < 11; j++) res += dp[i][j];
		if (s[i] == '0') res--;
	}
	printf("%lld\n", res);
	return 0;
}