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
const int MAXN = 3e5;
int n, c[MAXN + 5]; char str[MAXN + 5];
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
struct node {
	int ch[26], sz, is_ed;
	node() {fill0(ch); sz = is_ed = 0;}
} s[MAXN * 4 + 5];
int rt[MAXN + 5], ncnt;
void pushup(int k) {
	s[k].sz = s[k].is_ed;
	for (int i = 0; i < 26; i++) s[k].sz += s[s[k].ch[i]].sz;
}
int merge(int x, int y) {
	if (!x || !y) return x + y; int z = ++ncnt;
	for (int i = 0; i < 26; i++) s[z].ch[i] = merge(s[x].ch[i], s[y].ch[i]);
	s[z].is_ed = s[x].is_ed | s[y].is_ed; return pushup(z), z;
}
int mx = -1, cnt = 0;
void dfs(int x, int f) {
	rt[x] = ++ncnt;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue; dfs(y, x);
		rt[x] = merge(rt[x], rt[y]);
	}
	int nw = ++ncnt; s[rt[x]].is_ed = 1; pushup(rt[x]);
	s[nw].ch[str[x] - 'a'] = rt[x]; rt[x] = nw; pushup(rt[x]);
	if (s[rt[x]].sz + c[x] > mx) mx = s[rt[x]].sz + c[x], cnt = 1;
	else if (s[rt[x]].sz + c[x] == mx) cnt++;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]); scanf("%s", str + 1);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs(1, 0); printf("%d\n%d\n", mx, cnt);
	return 0;
}