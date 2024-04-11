// Created time: 2022/6/30 18:10:36
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
typedef __int128_t i128;
const int MAXN = 35;
char s[MAXN + 5]; int fst = 0, n, m; i128 v;
i128 getmul(i128 x, i128 y) {
	i128 ret = 0;
	for (int i = 0; i < m; i++) if (y >> i & 1) ret ^= (x << i);
	for (int i = m + m - 2; i >= m; i--) if (ret >> i & 1) ret ^= (v << (i - m));
	return ret;
}
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) if (s[i] == '1') {
		fst = i;
		for (int j = i; j <= n; j++) if (s[j] == '1') m = j - i, v |= 1ll << (j - i);
		break;
	}
	if (!fst) return puts("-1"), 0;
	if (!m) return printf("%d %d\n", fst, fst + 1), 0;
	ll cur = 1, pw; map<i128, int> vis;
	for (int i = 0; i < (1 << 18); i++) {
//		printf("%lld\n", cur);
		vis[cur] = i; cur = getmul(cur, 2);
	}
	pw = cur; cur = 1;
	for (int i = 1; i < (1 << 18); i++) {
		cur = getmul(cur, pw);
		if (vis.count(cur)) return printf("%d %lld\n", fst, fst + ((1ll * i) << 18) - vis[cur]), 0;
	}
	return 0;
}