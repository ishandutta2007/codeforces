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
const int MAXN = 6e5;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 1;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
bool vis[MAXN + 5], has[MAXN + 5]; vector<int> pt;
int N = 0, a[2][MAXN + 5]; char s[2][MAXN + 5], t[2][MAXN + 5];
void dfs(int x) {
	vis[x] = 1;
	for (int &e = hd[x]; e; e = nxt[e]) if (!has[e >> 1]) {has[e >> 1] = 1; dfs(to[e]);}
	pt.pb(x);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		adde(x, y); adde(y, x); adde(x, y); adde(y, x);
	}
	for (int i = 1; i <= n * 2; i++) if (!vis[i]) {
		pt.clear(); dfs(i); int len = pt.size() >> 1;
		if (pt.size() == 3) return puts("-1"), 0;
		// cerr << pt.size() << endl;
		if (!len) continue;
		for (int j = 0; j + 1 < pt.size(); j++) {
			if (j < len) a[0][N + j + 1] = pt[j];
			else a[1][N + len - (j - len)] = pt[j];
		}
		if (len & 1) {
			s[0][N + 1] = 'U'; s[1][N + 1] = 'D';
			for (int j = N + 2; j <= N + len; j += 2) s[0][j] = s[1][j] = 'L', s[0][j + 1] = s[1][j + 1] = 'R';
			t[0][N + len] = 'U'; t[1][N + len] = 'D';
			for (int j = N + 1; j < N + len; j += 2) t[0][j] = t[1][j] = 'L', t[0][j + 1] = t[1][j + 1] = 'R';
		} else {
			s[0][N + 1] = s[0][N + len] = 'U'; s[1][N + 1] = s[1][N + len] = 'D';
			for (int j = N + 2; j < N + len; j += 2) s[0][j] = s[1][j] = 'L', s[0][j + 1] = s[1][j + 1] = 'R';
			for (int j = N + 1; j < N + len; j += 2) t[0][j] = t[1][j] = 'L', t[0][j + 1] = t[1][j + 1] = 'R';
		}
		N += len;
	}
	printf("2 %d\n\n", n);
	for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) printf("%d%c", a[i][j], " \n"[j == n]);
	printf("\n%s\n%s\n\n%s\n%s\n", s[0] + 1, s[1] + 1, t[0] + 1, t[1] + 1);
	return 0;
}