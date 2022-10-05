// Created time: 2022/7/1 21:00:48
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
int n, a, b, c; ll t;
int lx, rx, ly, ry;
int getdis(int x1, int y1, int x2, int y2) {return abs(x1 - x2) + abs(y1 - y2);}
ll gsum(int A, int B) {
	if (A < B) A++; else if (A == B) return 0; else A--;
	return 1ll * (abs(A - B) + 1) * (A + B) / 2;
}
#define pA lx, ly
#define pB rx, ly
#define pC lx, ry
#define pD rx, ry
bool check(int x, int y, ll A, ll B, ll C, ll D) { // (lx, ly), (rx, ly), (lx, ry), (rx, ry)
	if (x == n && y == n) return (A >= 0 && B >= 0 && C >= 0 && D >= 0);
	if (A < 0 || B < 0 || C < 0 || D < 0) return 0;
	if (x < lx) {
		ll nA = gsum(getdis(x, y, pA), getdis(lx, y, pA));
		ll nB = gsum(getdis(x, y, pB), getdis(lx, y, pB));
		ll nC = gsum(getdis(x, y, pC), getdis(lx, y, pC));
		ll nD = gsum(getdis(x, y, pD), getdis(lx, y, pD));
		return check(lx, y, A - nA, B - nB, C - nC, D - nD);
	} else if (y < ly) {
		ll nA = gsum(getdis(x, y, pA), getdis(x, ly, pA));
		ll nB = gsum(getdis(x, y, pB), getdis(x, ly, pB));
		ll nC = gsum(getdis(x, y, pC), getdis(x, ly, pC));
		ll nD = gsum(getdis(x, y, pD), getdis(x, ly, pD));
		return check(x, ly, A - nA, B - nB, C - nC, D - nD);
	} else if (x >= rx && y != n) {
		if (y > ry) {
			ll nA = gsum(getdis(x, y, pA), getdis(x, n, pA));
			ll nB = gsum(getdis(x, y, pB), getdis(x, n, pB));
			ll nC = gsum(getdis(x, y, pC), getdis(x, n, pC));
			ll nD = gsum(getdis(x, y, pD), getdis(x, n, pD));
			return check(x, n, A - nA, B - nB, C - nC, D - nD);
		} else {
			ll nA = gsum(getdis(x, y, pA), getdis(x, ry, pA)) + gsum(getdis(x, ry, pA), getdis(x, n, pA));
			ll nB = gsum(getdis(x, y, pB), getdis(x, ry, pB)) + gsum(getdis(x, ry, pB), getdis(x, n, pB));
			ll nC = gsum(getdis(x, y, pC), getdis(x, ry, pC)) + gsum(getdis(x, ry, pC), getdis(x, n, pC));
			ll nD = gsum(getdis(x, y, pD), getdis(x, ry, pD)) + gsum(getdis(x, ry, pD), getdis(x, n, pD));
			return check(x, n, A - nA, B - nB, C - nC, D - nD);
		}
	} else if (y >= ry && x != n) {
		if (x > rx) {
			ll nA = gsum(getdis(x, y, pA), getdis(n, y, pA));
			ll nB = gsum(getdis(x, y, pB), getdis(n, y, pB));
			ll nC = gsum(getdis(x, y, pC), getdis(n, y, pC));
			ll nD = gsum(getdis(x, y, pD), getdis(n, y, pD));
			return check(n, y, A - nA, B - nB, C - nC, D - nD);
		} else {
			ll nA = gsum(getdis(x, y, pA), getdis(rx, y, pA)) + gsum(getdis(rx, y, pA), getdis(n, y, pA));
			ll nB = gsum(getdis(x, y, pB), getdis(rx, y, pB)) + gsum(getdis(rx, y, pB), getdis(n, y, pB));
			ll nC = gsum(getdis(x, y, pC), getdis(rx, y, pC)) + gsum(getdis(rx, y, pC), getdis(n, y, pC));
			ll nD = gsum(getdis(x, y, pD), getdis(rx, y, pD)) + gsum(getdis(rx, y, pD), getdis(n, y, pD));
			return check(n, y, A - nA, B - nB, C - nC, D - nD);
		}
	} else {
		ll nA = gsum(getdis(x, y, pA), getdis(rx, y, pA)) + gsum(getdis(rx, y, pA), getdis(rx, ry, pA))
		      + gsum(getdis(rx, ry, pA), getdis(rx, n, pA)) + gsum(getdis(rx, n, pA), getdis(n, n, pA));
		ll nD = gsum(getdis(x, y, pD), getdis(rx, y, pD)) + gsum(getdis(rx, y, pD), getdis(rx, ry, pD))
		      + gsum(getdis(rx, ry, pD), getdis(rx, n, pD)) + gsum(getdis(rx, n, pD), getdis(n, n, pD));
		if (nA > A || nD > D) return 0;
		ll nB1 = gsum(getdis(x, y, pB), getdis(rx, y, pB)) + gsum(getdis(rx, y, pB), getdis(rx, ry, pB))
		       + gsum(getdis(rx, ry, pB), getdis(rx, n, pB)) + gsum(getdis(rx, n, pB), getdis(n, n, pB));
		ll nC1 = gsum(getdis(x, y, pC), getdis(rx, y, pC)) + gsum(getdis(rx, y, pC), getdis(rx, ry, pC))
		       + gsum(getdis(rx, ry, pC), getdis(rx, n, pC)) + gsum(getdis(rx, n, pC), getdis(n, n, pC));
		ll nB2 = gsum(getdis(x, y, pB), getdis(x, ry, pB)) + gsum(getdis(x, ry, pB), getdis(rx, ry, pB))
		       + gsum(getdis(rx, ry, pB), getdis(rx, n, pB)) + gsum(getdis(rx, n, pB), getdis(n, n, pB));
		ll nC2 = gsum(getdis(x, y, pC), getdis(x, ry, pC)) + gsum(getdis(x, ry, pC), getdis(rx, ry, pC))
		       + gsum(getdis(rx, ry, pC), getdis(rx, n, pC)) + gsum(getdis(rx, n, pC), getdis(n, n, pC));
		if (min(nB1, nB2) > B || min(nC1, nC2) > C ||
		C < nB1 + nC1 - min(B, max(nB1, nB2)) ||
		B < nB1 + nC1 - min(C, max(nC1, nC2)))
			return 0;
		return 1;
	}
}
int main() {
	scanf("%d%lld%d%d%d", &n, &t, &a, &b, &c);
	lx = a; rx = a + c - 1; ly = b; ry = b + c - 1;
	if (!check(1, 1, t, t, t, t)) return puts("Impossible"), 0;
	int x = 1, y = 1; ll A = t, B = t, C = t, D = t;
	while (x != n || y != n) {
		#define C_right check(x + 1, y, A - getdis(x + 1, y, lx, ly), B - getdis(x + 1, y, rx, ly), C - getdis(x + 1, y, lx, ry), D - getdis(x + 1, y, rx, ry))
		#define C_up check(x, y + 1, A - getdis(x, y + 1, lx, ly), B - getdis(x, y + 1, rx, ly), C - getdis(x, y + 1, lx, ry), D - getdis(x, y + 1, rx, ry))
		if (x < n && C_right) putchar('R'), x++;
		else putchar('U'), y++;
		A -= getdis(x, y, lx, ly); B -= getdis(x, y, rx, ly);
		C -= getdis(x, y, lx, ry); D -= getdis(x, y, rx, ry);
	}
	return 0;
}