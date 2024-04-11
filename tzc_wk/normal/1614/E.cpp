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
const int MAXV = 1e9;
const int MAXP = MAXN << 5;
int n, t[MAXN + 5], lst;
struct node {int ch[2], val;} s[MAXP + 5];
int rt, ncnt;
void insert(int &k, int l, int r, int p, int v) {
	if (!k) k = ++ncnt; s[k].val += v; if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) insert(s[k].ch[0], l, mid, p, v);
	else insert(s[k].ch[1], mid + 1, r, p, v);
}
int query(int k, int l, int r, int ql, int qr) {
	if (!k) return 0; if (ql <= l && r <= qr) return s[k].val;
	int mid = l + r >> 1;
	if (qr <= mid) return query(s[k].ch[0], l, mid, ql, qr);
	else if (ql > mid) return query(s[k].ch[1], mid + 1, r, ql, qr);
	else return query(s[k].ch[0], l, mid, ql, mid) + query(s[k].ch[1], mid + 1, r, mid + 1, qr);
}
int find_rit(int v) {
	int l = -MAXN, r = MAXV + MAXN, p = l - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (query(rt, -MAXN, MAXV + MAXN, -MAXN, mid) + mid <= v) p = mid, l = mid + 1;
		else r = mid - 1;
	}
	return p;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		int pos1 = find_rit(t - i), pos2 = find_rit(t - i + 1);
//		printf("breakpoint %d %d\n", pos1, pos2);
		insert(rt, -MAXN, MAXV + MAXN, pos1 + 1, -1);
		insert(rt, -MAXN, MAXV + MAXN, pos2 + 1, -1);
		int qu; scanf("%d", &qu);
		while (qu--) {
			int x; scanf("%d", &x); x = (x + lst) % (MAXV + 1);
			printf("%d\n", lst = x + query(rt, -MAXN, MAXV + MAXN, -MAXN, x) + i);
		}
	}
	return 0;
}