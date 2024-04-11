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
int n, m;
char s[22][22];
bool can(int x, int y) {
	for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++)
		if (s[x + i][y + j] == '1') return 0;
	return 1;
}
void solve() {
	scanf("%d%d", &n, &m);
	memset(s, 0, sizeof(s));
	s[1][1] = '1';
	int cx = 1, cy = 2;
	while (cx != 1 || cy != 1) {
		if (can(cx, cy)) s[cx][cy] = '1';
		if (cx == 1) {
			if (cy == m) cx++;
			else cy++;
		} else if (cx == n) {
			if (cy == 1) cx--;
			else cy--;
		} else {
			if (cy == 1) cx--;
			else cx++;
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		if (!s[i][j]) s[i][j] = '0';
	for (int i = 1; i <= n; i++) printf("%s\n", s[i] + 1);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}