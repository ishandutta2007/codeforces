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
const int MAXP = 1 << 21;
int h, g, a[MAXP + 5];
int getdep(int x) {
	if (!a[x]) return 0;
	if (a[x << 1] > a[x << 1 | 1]) return getdep(x << 1) + 1;
	else return getdep(x << 1 | 1) + 1;
}
void do_F(int x) {
	if (!a[x << 1] && !a[x << 1 | 1]) a[x] = 0;
	else {
		if (a[x << 1] > a[x << 1 | 1]) a[x] = a[x << 1], do_F(x << 1);
		else a[x] = a[x << 1 | 1], do_F(x << 1 | 1);
	}
}
void solve() {
	scanf("%d%d", &h, &g); ll sum = 0; vector<int> res;
	for (int i = 1; i < (1 << h + 1); i++) a[i] = 0;
	for (int i = 1; i < (1 << h); i++) scanf("%d", &a[i]), sum += a[i];
	priority_queue<pair<int, pii> > q; q.push(mp(a[1], mp(1, 0)));
	for (int i = 1; i <= (1 << h) - (1 << g); i++) {
		while (!q.empty()) {
			pair<int, pii> p = q.top(); q.pop();
			int x = p.se.fi;
//			printf("x = %d\n", x);
			if (getdep(x) + p.se.se > g) {
				sum -= a[x]; res.pb(x); q.push(p);
//				printf("F(%d)\n", x);
				do_F(x); break;
			} else {
//				printf("split %d\n", x);
				if (a[x << 1]) q.push(mp(a[x << 1], mp(x << 1, p.se.se + 1)));
				if (a[x << 1 | 1]) q.push(mp(a[x << 1 | 1], mp(x << 1 | 1, p.se.se + 1)));
			}
		}
	}
	printf("%lld\n", sum);
	for (int x : res) printf("%d ", x);
	printf("\n");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}