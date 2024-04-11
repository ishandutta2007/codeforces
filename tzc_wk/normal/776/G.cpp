// Created time: 2022/4/28 15:27:57
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
ll dp[17][2][2][2];
ll calc(ll p) {
	if (p < 0) return 0; ll res = 0;
	for (int i = 0; i < 16; i++) {
		memset(dp, 0, sizeof(dp)); dp[16][1][1][0] = 1;
		for (int j = 16; j; j--) {
			for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++) {
				for (int c = 0; c < 2; c++) if (dp[j][k][l][c]) {
					int lim = (k) ? (p >> (j - 1 << 2) & 15) : 15;
					for (int v = 0; v <= lim; v++) {
						if (v > i) continue;
						if ((j - 1) * 4 <= i && i < j * 4 && ((v >> (i & 3) & 1) == 0)) continue;
						dp[j - 1][k && (v == lim)][l && (v == 0)][c | (v == i && (!(l && v == 0)))] += dp[j][k][l][c];
					} 
				}
			}
		}
		res += dp[0][0][0][1] + dp[0][1][0][1];
	}
	return res;
}
void solve() {
	ll l, r; cin >> hex >> l >> r;
	cout << calc(r) - calc(l - 1) << endl;
}
int main() {
	int qu; cin >> qu; while (qu--) solve();	
	return 0;
}