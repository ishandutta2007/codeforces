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
const int MAXN = 2e5;
int n, l[MAXN + 5], r[MAXN + 5], lft[MAXN + 5], rit[MAXN + 5];
int posl[MAXN + 5], idl[MAXN + 5];
int t[MAXN + 5];
void add(int x, int v) {for (int i = x; i <= n * 2; i += (i & (-i))) t[i] += v;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		if (l[i] > r[i]) swap(l[i], r[i]);
		posl[l[i]] = r[i]; idl[l[i]] = i;
	}
	for (int i = 1; i <= n * 2; i++) if (idl[i])
		lft[idl[i]] = query(n * 2) - query(posl[i]) + query(i - 1), add(posl[i], 1);
	memset(t, 0, sizeof(t));
	for (int i = n * 2; i; i--) if (idl[i])
		rit[idl[i]] = query(posl[i]), add(posl[i], 1);
	memset(t, 0, sizeof(t));
	for (int i = n * 2; i; i--) if (idl[i])
		lft[idl[i]] += query(n * 2) - query(posl[i]), add(i, 1);
//	for (int i = 1; i <= n; i++) printf("%d %d\n", lft[i], rit[i]);
	ll sum = 1ll * n * (n - 1) * (n - 2) / 6, ss = 0;
	for (int i = 1; i <= n; i++) sum -= 1ll * lft[i] * rit[i];
	for (int i = 1; i <= n; i++) ss += 1ll * (lft[i] + rit[i]) * (n - 1 - lft[i] - rit[i]);
	sum -= ss / 2; printf("%lld\n", sum);
	return 0;
}