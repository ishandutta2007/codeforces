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
const int MAXN = 500;
int n, k, a[MAXN + 5][MAXN + 5];
bool check(int x) {
	// printf("check %d\n", x);
	static int buc[MAXN * MAXN + 5];
	for (int i = 1; i <= n; i++) {
		memset(buc, 0, sizeof(buc)); int c = 0;
		auto ins = [&](int col) {if (!buc[col]) ++c; buc[col]++;};
		auto del = [&](int col) {buc[col]--; if (!buc[col]) --c;};
		for (int x = 1; x <= n; x++) for (int y = 1; y <= n; y++) ins(a[x][y]);
		int cur = n - i + 1;
		for (int j = 1; j + i - 1 <= n; j++) {
			for (int k = 1; k <= j; k++) del(a[i + j - 1][k]);
			for (int k = 1; k < j; k++) del(a[i + k - 1][j]);
			if (c == x) return 1;
			if (c < x) {cur = j; break;}
		}
		// printf("! %d %d %d %d\n", i, 1, cur, c);
		for (int j = 2; j <= n; j++) {
			if (cur) {
				for (int k = 1; k <= cur; k++) ins(a[i + cur - 1][j + k - 2]);
				for (int k = 1; k < cur; k++) ins(a[i + k - 1][j - 1]);
				--cur;
			}
			if (c == x) return 1;
			// for (int k = 1; k <= n * n; k++) printf("%d%c", buc[k], " \n"[k == n * n]);
			while (cur < n - max(i, j) + 1) {
				++cur;
				for (int k = 1; k <= cur; k++) del(a[i + cur - 1][j + k - 1]);
				for (int k = 1; k < cur; k++) del(a[i + k - 1][j + cur - 1]);
				if (c == x) return 1; if (c < x) break;
			}
			// printf("! %d %d %d %d\n", i, j, cur, c);
		}
	}
	return 0;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k); set<int> st;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]), st.insert(a[i][j]);
	if (st.size() == k) return puts("0"), 0;
	if (st.size() < k) return printf("%d\n", abs(k - (int)(st.size()))), 0;
	if (check(k)) return puts("1"), 0;
	if (st.size() != n * n && check(k - 1)) return puts("1"), 0;
	puts("2");
	return 0;
}