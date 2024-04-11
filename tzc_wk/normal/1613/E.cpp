#include <bits/stdc++.h>
using namespace std;
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
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1e6;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, sx, sy, cnt[MAXN + 5];
string s[MAXN + 5];
int getid(int x, int y) {return (x - 1) * m + y;}
int hd[MAXN + 5], to[MAXN * 4 + 5], nxt[MAXN * 4 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
bool vis[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) hd[i] = vis[i] = cnt[i] = 0; ec = 0;
	for (int i = 1; i <= n; i++) cin >> s[i], s[i] = " " + s[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		if (s[i][j] == 'L') sx = i, sy = j;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (s[i][j] != '#') {
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d], ny = j + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (s[nx][ny] != '#') cnt[getid(i, j)]++, adde(getid(i, j), getid(nx, ny));
			}
		}
	}
	queue<int> q; vis[getid(sx, sy)] = 1; q.push(getid(sx, sy));
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e];
			if (!vis[y] && (--cnt[y]) <= 1) {
				vis[y] = 1; q.push(y);
			} 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] != '.') putchar(s[i][j]);
			else if (vis[getid(i, j)]) putchar('+');
			else putchar('.');
		}
		putchar('\n');
	}
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}
/*
1
5 5
..L..
.#.#.
...#.
.###.
.....

1
4 5
..L..
.#.#.
..#..
#....

1
5 5
.....
.#.#.
.#.#.
.#.#.
..L..
*/