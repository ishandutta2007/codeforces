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
const int MAXN = 1e5;
int n, a[MAXN + 5], b[MAXN + 5]; ll k;
ll Delta(ll x, ll y) {return a[x] - 3ll * y * y + 3ll * y - 1;}
int fndgeq(int x, ll y) {
	int l = 1, r = a[x], p = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Delta(x, mid) >= y) p = mid, l = mid + 1;
		else r = mid - 1;
	} return p;
}
bool check(ll x) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += (b[i] = fndgeq(i, x));
	return sum <= k;
}
int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ll l = -4e18, r = 4e18, p = 0;
	while (l <= r) {
		ll mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
	check(p);
	for (int i = 1; i <= n; i++) k -= b[i];
	priority_queue<pair<ll, int> > q;
	for (int i = 1; i <= n; i++) if (b[i] < a[i]) q.push(mp(Delta(i, b[i] + 1), i));
	while (k--) {
		pair<ll, int> p = q.top(); q.pop(); int id = p.se; b[id]++;
		if (b[id] < a[id]) q.push(mp(Delta(id, b[id] + 1), id));
	}
	for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
	return 0;
}