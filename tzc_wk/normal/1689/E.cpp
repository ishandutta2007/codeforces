// Created time: 2022/6/17 16:40:28
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
int n, a[MAXN + 5], res, f[50];
int find(int x) {return (f[x] == -1) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {x = find(x); y = find(y); if (x != y) f[x] = y;}
bool check() {
	memset(f, -1, sizeof(f)); int OR = 0;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) return 0; vector<int> vec;
		for (int j = 0; j <= 30; j++) if (a[i] >> j & 1) vec.pb(j);
		for (int j = 1; j < vec.size(); j++) merge(vec[j], vec[0]);
		OR |= a[i];
	}
	vector<int> vec;
	for (int j = 0; j <= 30; j++) if (OR >> j & 1) vec.pb(j);
	for (int j = 1; j < vec.size(); j++) if (find(vec[j]) != find(vec[0])) return 0;
	return 1;
}
void solve() {
	scanf("%d", &n); res = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!a[i]) a[i] = 1, res++;
	}
	if (check()) {
		printf("%d\n", res);
		for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
		return;
	}
	for (int x = 1; x <= n; x++) {
		a[x]++;
		if (check()) {
			printf("%d\n", res + 1);
			for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
			return;
		}
		a[x] -= 2;
		if (check()) {
			printf("%d\n", res + 1);
			for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
			return;
		}
		a[x]++;
	}
	int mx = 0, A = 0, B = 0;
	for (int i = 1; i <= n; i++) chkmax(mx, __builtin_ctz(a[i]));
	for (int i = 1; i <= n; i++) if (__builtin_ctz(a[i]) == mx) {
		if (!A) A = i; else if (!B) B = i;
	}
	a[A]++; a[B]--; printf("%d\n", res + 2);
	for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}