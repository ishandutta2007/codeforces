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
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
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
int n;
ll query(int l, int r) {
	if (l > r) return 0;
	printf("? %d %d\n", l, r); fflush(stdout);
	ll x; scanf("%lld", &x); return x;
}
void solve() {
	scanf("%d", &n);
	int l = 1, r = n, P = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (query(1, mid)) P = mid, r = mid - 1;
		else l = mid + 1;
	}
	P--;
	int dif = query(P, n) - query(P + 1, n);
	int Q = P + dif + 1;
	ll t = query(Q, n);
	l = 1, r = n; int len = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (1ll * mid * (mid - 1) / 2 <= t) len = mid, l = mid + 1;
		else r = mid - 1;
	}
	int R = Q + len - 1;
	printf("! %d %d %d\n", P, Q, R); fflush(stdout);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}