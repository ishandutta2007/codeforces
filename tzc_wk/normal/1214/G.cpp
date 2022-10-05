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
const int MAXN = 2000;
int n, m, qu;
bitset<MAXN + 5> E[MAXN + 5], a[MAXN + 5];
int cnt[MAXN + 5];
bool check(int x, int y) {return ((a[x] & a[y]) != a[x] && ((a[x] & a[y]) != a[y]));}
set<pii> st;
set<int> able;
void del(int x) {
	pii pre = *--st.find(mp(cnt[x], x));
	pii nxt = *++st.find(mp(cnt[x], x));
	if (pre.se && able.find(pre.se) != able.end()) able.erase(able.find(pre.se));
	if (nxt.se && able.find(x) != able.end()) able.erase(able.find(x));
	st.erase(st.find(mp(cnt[x], x)));
	if (pre.se && nxt.se && check(pre.se, nxt.se)) able.insert(pre.se);
}
void ins(int x) {
	st.insert(mp(cnt[x], x));
	pii pre = *--st.find(mp(cnt[x], x));
	pii nxt = *++st.find(mp(cnt[x], x));
	if (pre.se && nxt.se && check(pre.se, nxt.se)) able.erase(able.find(pre.se));
	if (pre.se && check(pre.se, x)) able.insert(pre.se);
	if (nxt.se && check(x, nxt.se)) able.insert(x);
}
void work() {
	if (able.empty()) puts("-1");
	else {
		int x = *able.begin();
		int nt = (*++st.find(mp(cnt[x], x))).se;
		int L = (a[x] & (~a[nt]))._Find_first();
		int R = ((~a[x]) & a[nt])._Find_first();
		if (L > R) swap(L, R);
		if (x > nt) swap(x, nt);
		printf("%d %d %d %d\n", x, L, nt, R);
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &qu);
	st.insert(mp(-1, 0)); st.insert(mp(m + 1, 0));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= i; j++)
			E[i].set(j);
	for (int i = 1; i <= n; i++) st.insert(mp(0, i));
	while (qu--) {
		int x, l, r; scanf("%d%d%d", &x, &l, &r);
		del(x); a[x] ^= (E[r] ^ E[l - 1]);
		cnt[x] = a[x].count(); ins(x);
		work();
	}
	return 0;
}