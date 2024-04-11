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
const int MAXN = 2000;
const int INF = 0x3f3f3f3f;
int n, ans[MAXN + 5], l[MAXN + 5], r[MAXN + 5], pos[MAXN + 5], vis[MAXN + 5];
bool check(int mid) {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) pos[i] = n;
	for (int i = 1; i <= n; i++) {
		static int buc[MAXN + 5]; memset(buc, 0, sizeof(buc));
		for (int j = 1; j <= n; j++) if (!vis[j]) buc[pos[j]]++;
		for (int j = 1; j <= n; j++) buc[j] += buc[j - 1];
		for (int j = 1; j <= n; j++) if (buc[j] > max(j - i + 1, 0)) return 0;
		int nw = 0, nd_lim = n;
		for (int j = n; j >= i; j--) if (buc[j] == j - i + 1) nd_lim = j;
		for (int j = 1; j <= n; j++) if (!vis[j] && r[j] < r[nw] && pos[j] <= nd_lim) nw = j;
		ans[i] = nw; vis[nw] = 1;
//		printf("! %d\n", nw);
		for (int j = 1; j <= n; j++) if (!vis[j] && max(l[j], l[nw]) <= min(r[j], r[nw]))
			chkmin(pos[j], i + mid);
//		for (int j = 1; j <= n; j++) printf("%d%c", pos[j], " \n"[j == n]);
//		for (int j = 1; j <= n; j++) printf("%d%c", vis[j], " \n"[j == n]);
	}
	return 1;
}
int main() {
	scanf("%d", &n); r[0] = INF;
	for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	int L = 0, R = n - 1, p = 0;
//	check(1);
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid)) p = mid, R = mid - 1;
		else L = mid + 1;
	}
//	printf("%d\n", p);
	check(p);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}