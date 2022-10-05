#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
		if (x < 0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 500;
const int MAXV = 2.5e5;
const int MAXE = 2e6;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m; char s[MAXN + 5][MAXN + 5];
int hd[MAXV + 5], to[MAXE + 5], nxt[MAXE + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int getid(int x, int y) {return (x - 1) * m + y;}
int col[MAXV + 5];
void dye(int x, int c) {
	if (~col[x]) {
		if (col[x] != c) exit(puts("NO") & 0);
		return;
	}
	col[x] = c;
	for (int e = hd[x]; e; e = nxt[e]) {int y = to[e]; dye(y, c ^ 1);}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j] == 'X') {
		int cnt = 0;
		for (int d = 0; d < 4; d++) {
			int x = i + dx[d], y = j + dy[d];
			if (s[x][y] == '.') cnt++;
		}
		if (cnt & 1) return puts("NO"), 0;
		if (cnt == 2) {
			int U = 0, V = 0;
			for (int d = 0; d < 4; d++) {
				int x = i + dx[d], y = j + dy[d];
				if (s[x][y] == '.') {
					if (!U) U = getid(x, y);
					else V = getid(x, y);
				}
			}
			adde(U, V); adde(V, U);
		}
		if (cnt == 4) {
			for (int d = 0; d < 4; d++) {
				adde(getid(i + dx[d], j + dy[d]), getid(i + dx[d + 1 & 3], j + dy[d + 1 & 3]));
				adde(getid(i + dx[d + 1 & 3], j + dy[d + 1 & 3]), getid(i + dx[d], j + dy[d]));
			}
		}
	}
	memset(col, -1, sizeof(col));
	for (int i = 1; i <= n * m; i++) if (!~col[i]) dye(i, 0);
	puts("YES");
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		int X;
		if (s[i][j] == '.') X = (col[getid(i, j)] ? 1 : 4);
		else {
			X = 0;
			for (int d = 0; d < 4; d++) {
				int x = i + dx[d], y = j + dy[d];
				if (s[x][y] == '.') X += (col[getid(x, y)] ? 1 : 4);
			}
		}
		printf("%d%c", X, " \n"[j == m]);
	}
	return 0;
}