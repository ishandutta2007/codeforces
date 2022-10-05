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
const int MAXN = 2e5;
int n, x, p[MAXN + 5], deg[MAXN + 5], vis[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &x); for (int i = 1; i <= n; i++) deg[i] = 0;
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), deg[u]++, deg[v]++;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	int R = -1; for (int i = 1; i <= n; i++) if (deg[i] == n - 1) R = i;
	if (R == -1) puts("Alice");
	else {
		bool flg = 1;
		for (int i = 1; i <= n; i++) flg &= (p[i] == i);
		if (flg) return puts("Alice"), void();
		if (x == R && p[x] != x) puts("Bob");
		else {
			if (p[R] != R && x == p[R]) puts("Bob");
			else {
				int sum = 0;
				for (int i = 1; i <= n; i++) vis[i] = 0;
				for (int i = 1; i <= n; i++) if (!vis[i]) {
					int sz = 0;
					for (int j = i; !vis[j]; j = p[j]) vis[j] = 1, ++sz;
					sum += sz - 1;
				}
				if (sum == 1) {
					for (int i = 1; i <= n; i++) if (p[i] != i && i != x && p[i] != x)
						return puts("Alice"), void();
				}
				sum += (x != R);
				printf("%s\n", (sum & 1) ? "Alice" : "Bob");
			}
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}