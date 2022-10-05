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
const int MAXN = 5e5;
const int INF = 0x3f3f3f3f;
int n, a[MAXN + 5], sum[MAXN + 5], bel[MAXN + 5];
int posl[MAXN + 5], posr[MAXN + 5];
struct node {int l, r, mn, lz;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].mn = min(s[k << 1].mn, s[k << 1 | 1].mn);}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; s[k].lz = 0;
	if (l == r) return s[k].mn = sum[n] - sum[l - 1], void();
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void pushdown(int k) {
	if (s[k].lz) {
		s[k << 1].mn += s[k].lz; s[k << 1].lz += s[k].lz;
		s[k << 1 | 1].mn += s[k].lz; s[k << 1 | 1].lz += s[k].lz;
		s[k].lz = 0;
	}
}
void modify(int k, int l, int r, int v) {
	if (l <= s[k].l && s[k].r <= r) return s[k].lz += v, s[k].mn += v, void();
	pushdown(k); int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) modify(k << 1, l, r, v);
	else if (l > mid) modify(k << 1 | 1, l, r, v);
	else modify(k << 1, l, mid, v), modify(k << 1 | 1, mid + 1, r, v);
	pushup(k);
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (!a[i]);
	int lim = sum[n] / 2;
	for (int i = 1; i <= n; i++) bel[i] = (sum[i] > lim);
	for (int i = 1; i <= n; i++) posl[i] = posr[i] = 0;
	for (int i = 1; i <= n; i++) if (!bel[i] && a[i]) posl[a[i]] = i;
	for (int i = n; i; i--) if (bel[i] && a[i]) posr[a[i]] = i;
	int pos = 1;
	for (int i = 1; i <= n; i++) if (bel[i]) {pos = i; break;}
	build(1, pos, n + 1);
	for (int i = 1; i <= n; i++) if (posl[i] || posr[i]) {
		if (posl[i]) modify(1, pos, n + 1, 1);
		else modify(1, posr[i] + 1, n + 1, 1);
	}
	int res = s[1].mn;
	for (int i = 1; i <= n && !bel[i]; i++) {
		if (posl[a[i]] == i) {
			if (!posr[a[i]]) modify(1, pos, n + 1, -1);
			else modify(1, pos, posr[a[i]], -1);
			chkmin(res, s[1].mn + sum[i]);
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d%c", bel[i], " \n"[i == n]);
//	for (int i = 1; i <= n; i++) printf("%d %d\n", posl[i], posr[i]);
	printf("%d\n", min(res, lim));
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}
/*
1
12
0 1 0 2 2 2 0 0 3 3 4 0

1
15
0 1 0 0 1 2 0 3 0 0 2 0 4 5 0
*/