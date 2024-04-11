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
const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int n; char s[MAXN + 5], t[MAXN + 5];
int ch[MAXN + 5][26], fail[MAXN + 5], len[MAXN + 5];
int curS[MAXN + 5], slen = 0, ncnt, cur = 0, slink[MAXN + 5], dif[MAXN + 5];
void init() {curS[0] = -1; len[1] = -1; fail[0] = 1; ncnt = 1; cur = 0;}
int f[MAXN + 5], g[MAXN + 5][2];
void insert(int c) {
	int p = cur; curS[++slen] = c;
	while (curS[slen - len[p] - 1] != c) p = fail[p];
	if (ch[p][c]) cur = ch[p][c];
	else {
		len[++ncnt] = len[p] + 2; cur = ncnt;
		int fa = fail[p]; while (curS[slen - len[fa] - 1] != c) fa = fail[fa];
		fail[cur] = ch[fa][c]; ch[p][c] = ncnt;
		dif[cur] = len[cur] - len[fail[cur]];
		slink[cur] = (dif[cur] == dif[fail[cur]]) ? slink[fail[cur]] : fail[cur];
//		printf("ins %d %d %d %d %d\n", cur, len[cur], fail[cur], dif[cur], slink[cur]);
	}
}
int main() {
	scanf("%s", s + 1); n = strlen(s + 1); int l = 1, r = n; init();
	for (int i = 1; i <= n; i++) {if (i & 1) t[i] = s[l++]; else t[i] = s[r--];}
	f[0] = 1;
//	printf("%s\n", t + 1);
	for (int i = 1; i <= n; i++) {
		insert(t[i] - 'a');
		for (int j = cur; j; j = slink[j]) {
			int dlt = len[slink[j]] + dif[j];
			g[j][0] = g[j][1] = 0;
			g[j][dlt & 1] = f[i - dlt];
			if (slink[j] != fail[j]) {
				for (int k = 0; k < 2; k++)
					g[j][k] = (g[j][k] + g[fail[j]][k ^ (dif[j] & 1)]) % MOD;
			}
			f[i] = (f[i] + g[j][0]) % MOD;
		}
//		printf("%d %d\n", i, f[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}