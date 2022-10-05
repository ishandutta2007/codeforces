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
const int MAXN = 1000;
const int MAXV = 5e5;
int n, m, a[MAXN + 5], b[MAXN + 5], sa, sb;
bitset<MAXV + 5> ca[MAXN + 5], cb[MAXN + 5];
vector<int> X, Y;
void solve() {
	scanf("%d", &n); sa = sb = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sa += a[i];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), sb += b[i];
	if (n != m || (sa & 1) || (sb & 1)) return puts("No"), void();
	ca[0][0] = cb[0][0] = 1;
	for (int i = 1; i <= n; i++) ca[i] = ca[i - 1] | (ca[i - 1] << a[i]);
	for (int i = 1; i <= m; i++) cb[i] = cb[i - 1] | (cb[i - 1] << b[i]);
	if (!ca[n][sa / 2] || !cb[n][sb / 2]) return puts("No"), void();
	int cur = sa / 2; X.clear(); Y.clear();
	for (int i = n; i; i--) {
		if (cur >= a[i] && ca[i - 1][cur - a[i]]) X.pb(a[i]), cur -= a[i];
		else X.pb(-a[i]);
	}
	cur = sb / 2;
	for (int i = m; i; i--) {
		if (cur >= b[i] && cb[i - 1][cur - b[i]]) Y.pb(b[i]), cur -= b[i];
		else Y.pb(-b[i]);
	}
	vector<int> X1, X2, Y1, Y2;
	for (int x : X) {
		if (x > 0) X1.pb(x);
		else X2.pb(x);
	}
	for (int x : Y) {
		if (x > 0) Y1.pb(x);
		else Y2.pb(x);
	}
	bool swp = 0;
	if (X1.size() > Y1.size()) swap(X1, Y1), swap(X2, Y2), swp = 1;
	sort(X1.begin(), X1.end(), greater<int>());
	sort(Y1.begin(), Y1.end());
	sort(X2.begin(), X2.end());
	sort(Y2.begin(), Y2.end(), greater<int>());
	int cx = 0, cy = 0; puts("Yes");
	for (int i = 0; i < X.size(); i++) {
		(swp) ? printf("%d %d\n", cy, cx) : printf("%d %d\n", cx, cy);
		cx += (i < X1.size()) ? X1[i] : X2[i - X1.size()];
		(swp) ? printf("%d %d\n", cy, cx) : printf("%d %d\n", cx, cy);
		cy += (i < Y1.size()) ? Y1[i] : Y2[i - Y1.size()];
	}
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}