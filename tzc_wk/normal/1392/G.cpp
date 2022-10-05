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
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
using namespace fastio;
const int MAXN = 1e6;
const int MAXK = 20;
const int MAXP = 1 << 20;
int m, n, k, a[MAXN + 5], b[MAXN + 5], mn[MAXP + 5], mx[MAXP + 5];
char s[MAXK + 3], t[MAXK + 3]; int A[MAXN + 5], B[MAXN + 5];
struct perm {
	int p[MAXK + 5];
	void init() {for (int i = 1; i <= k; i++) p[i] = i;}
	perm operator + (const perm &rhs) const {
		perm res; res.init();
		for (int i = 1; i <= k; i++) res.p[i] = rhs.p[p[i]];
		return res;
	}
} suf[MAXN + 5];
int main() {
	scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	for (int i = 1; i <= n + 1; i++) suf[i].init(), swap(suf[i].p[a[i]], suf[i].p[b[i]]);
	for (int i = n; i; i--) suf[i] = suf[i] + suf[i + 1];
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= k; j++) A[i] |= (s[j] - '0') << (suf[i].p[j] - 1);
		for (int j = 1; j <= k; j++) B[i] |= (t[j] - '0') << (suf[i].p[j] - 1);
	}
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= k; i++) c1 += (s[i] == '1'), c2 += (t[i] == '1');
	memset(mn, 63, sizeof(mn)); pii res = mp(-1, 0);
	for (int i = 1; i <= n + 1; i++) chkmin(mn[A[i]], i);
	for (int i = 1; i <= n + 1; i++) chkmax(mx[B[i]], i);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < (1 << k); j++)
			if (~j >> i & 1) {
				chkmin(mn[j], mn[j ^ (1 << i)]);
				chkmax(mx[j], mx[j ^ (1 << i)]);
			}
	}
	for (int i = 0; i < (1 << k); i++) {
		if (mx[i] - mn[i] >= m)
			chkmax(res, mp(__builtin_popcount(i), i));
	}
	printf("%d\n%d %d\n", k - c1 - c2 + 2 * res.fi, mn[res.se], mx[res.se] - 1);
	return 0;
}