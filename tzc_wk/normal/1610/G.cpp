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
#ifdef FASTIO
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
using namespace fastio;
#endif
const int MAXN = 3e5;
const int DLT = MAXN + 3;
const int LOG_N = 19;
const u64 BS = 19491001;
char s[MAXN + 5]; int n, fa[MAXN * 2 + 5][LOG_N + 2];
u64 hs[MAXN * 2 + 5][LOG_N + 2], pw[524300];
int sum[MAXN + 5], st[LOG_N + 2][MAXN + 5], pvec[MAXN + 5], hib[524300];
vector<int> pos[MAXN * 2 + 10];
int query_st(int l, int r) {
	int k = hib[r - l + 1];
	return min(st[k][l], st[k][r - (1 << k) + 1]);
}
int nxt[MAXN + 5], nd[MAXN + 5], ncnt;
int append(int f, char c) {
	int id = ++ncnt; fa[id][0] = f; hs[id][0] = c;
	for (int i = 1; i <= LOG_N; i++) {
		hs[id][i] = hs[id][i - 1] + hs[fa[id][i - 1]][i - 1] * pw[1 << i - 1];
		fa[id][i] = fa[fa[id][i - 1]][i - 1];
	}
//	printf("append %d %c %d\n", f, c, id);
	return ncnt;
}
int getcmp(int x, int y) {// returns 1 if x is lexicographically larger than y
	for (int i = LOG_N; ~i; i--) if (fa[x][i] && fa[y][i] && hs[x][i] == hs[y][i])
		x = fa[x][i], y = fa[y][i];
//	printf("%d %d %c %c\n", x, y, hs[x][0], hs[y][0]);
	return hs[x][0] > hs[y][0];
}
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= 19; i++) hib[1 << i] = 1;
	for (int i = 1; i <= 524288; i++) hib[i] += hib[i - 1];
	for (int i = (pw[0] = 1); i <= 524288; i++) pw[i] = pw[i - 1] * BS;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + ((s[i] == '(') ? 1 : -1);
	for (int i = 0; i <= n; i++) pvec[i] = pos[sum[i] + DLT].size(), pos[sum[i] + DLT].pb(i);
	for (int i = 1; i <= n; i++) st[0][i] = sum[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	for (int i = 1; i <= n; i++) {
		nxt[i] = (pvec[i - 1] == ((int)pos[sum[i - 1] + DLT].size()) - 1 || query_st(i, pos[sum[i - 1] + DLT][pvec[i - 1] + 1]) < sum[i - 1])
		? i : (pos[sum[i - 1] + DLT][pvec[i - 1] + 1] + 1);
	}
//	for (int i = 1; i <= n; i++) printf("%d%c", nxt[i], " \n"[i == n]);
	nd[n + 1] = ncnt = 1;
	for (int i = n; i; i--) {
		if (nxt[i] == i) nd[i] = append(nd[i + 1], s[i]);
		else {
			int X = append(nd[i + 1], s[i]), Y = nd[nxt[i]];
			nd[i] = getcmp(X, Y) ? Y : X;
//			if (i == 14) printf("! %d %d %d\n", X, Y, nd[i]);
		}
	}
	for (int i = nd[1]; i ^ 1; i = fa[i][0]) putchar(char(hs[i][0]));
	putchar('\n');
	return 0;
}