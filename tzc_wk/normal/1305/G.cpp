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
#ifdef FASTIO
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
using namespace fastio;
#endif
const int MAXN = 2e5;
const int MAXP = 262144;
int n, a[MAXN + 5], f[MAXN + 5], mxv, lg = 0; ll res = 0;
int find(int x) {return (x == -1 || !f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {int fx = find(x), fy = find(y); if (fx ^ fy) res += a[x] + a[y], f[fx] = fy;}
tuple<int, int, int> nw_edge[MAXN + 5];
pair<pii, pii> mx[MAXP + 5];
pair<pii, pii> merge(pair<pii, pii> A, pair<pii, pii> B) {
	pii mx = max(A.fi, B.fi), smx = mp(-1, -1);
	if (find(A.fi.se) != find(mx.se)) chkmax(smx, A.fi);
	if (find(A.se.se) != find(mx.se)) chkmax(smx, A.se);
	if (find(B.fi.se) != find(mx.se)) chkmax(smx, B.fi);
	if (find(B.se.se) != find(mx.se)) chkmax(smx, B.se);
	return mp(mx, smx);
}
void upd(tuple<int, int, int> &A, pii B, int C) {
	if (B.fi == -1) return;
	if (find(B.se) == find(C)) return;
	chkmax(A, mt(a[B.se] + a[C], B.se, C));
}
int main() {
	scanf("%d", &n); ++n;
	for (int i = 1; i < n; i++) scanf("%d", &a[i]), chkmax(mxv, a[i]);
	while ((1 << lg) <= mxv) ++lg;
	while (1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (find(i) == i);
		if (cnt == 1) break;
		for (int i = 1; i <= n; i++) nw_edge[i] = mt(-1, -1, -1);
		for (int i = 0; i < (1 << lg); i++) mx[i] = mp(mp(-1, -1), mp(-1, -1));
		for (int i = 1; i <= n; i++) mx[a[i]] = merge(mx[a[i]], mp(mp(a[i], i), mp(-1, -1)));
		for (int i = 0; i < lg; i++) for (int j = 0; j < (1 << lg); j++)
			if (j >> i & 1) mx[j] = merge(mx[j], mx[j ^ (1 << i)]);
		for (int i = 1; i <= n; i++) {
			upd(nw_edge[find(i)], mx[((1 << lg) - 1) ^ a[i]].fi, i);
			upd(nw_edge[find(i)], mx[((1 << lg) - 1) ^ a[i]].se, i);
		}
		vector<pii> ed;
		for (int i = 1; i <= n; i++) if (find(i) == i && get<0>(nw_edge[i]) != -1)
			ed.pb(mp(get<1>(nw_edge[i]), get<2>(nw_edge[i])));
		sort(ed.begin(), ed.end(), [&](pii X, pii Y) {return a[X.fi] + a[X.se] > a[Y.fi] + a[Y.se];});
//		printf("new round:\n");
//		for (pii p : ed) printf("(%d, %d)\n", p.fi, p.se);
		for (pii p : ed) merge(p.fi, p.se);
	}
	for (int i = 1; i <= n; i++) res -= a[i];
	printf("%lld\n", res);
	return 0;
}
/*
6
3 3 4 4 5 5
*/