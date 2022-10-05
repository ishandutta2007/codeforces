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
const int MAXV = 1e6;
const int MAXP = MAXV * 4;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3fll;
int n, m, qu, a[MAXN + 5], b[MAXN + 5];
multiset<int> stA, stB; ll sumA, sumB;
struct node {int ch[2], siz; ll sum;} s[MAXP + 5];
int rt, ncnt;
void insert(int &k, int l, int r, int p, int v) {
	if (!k) k = ++ncnt; s[k].siz += v; s[k].sum += p * v;
	if (l == r) return; int mid = l + r >> 1;
	(p <= mid) ? insert(s[k].ch[0], l, mid, p, v) : insert(s[k].ch[1], mid + 1, r, p, v);
}
pair<int, ll> query(int k, int l, int r, int ql, int qr) {
	if (!k || ql > qr) return mp(0, 0);
	if (ql <= l && r <= qr) return mp(s[k].siz, s[k].sum);
	int mid = l + r >> 1;
	if (qr <= mid) return query(s[k].ch[0], l, mid, ql, qr);
	else if (ql > mid) return query(s[k].ch[1], mid + 1, r, ql, qr);
	else {
		auto pl = query(s[k].ch[0], l, mid, ql, mid);
		auto pr = query(s[k].ch[1], mid + 1, r, mid + 1, qr);
		return mp(pl.fi + pr.fi, pl.se + pr.se);
	}
}
void insA(int v) {sumA += v; stA.insert(v);}
void insB(int v) {sumB += v; stB.insert(v); insert(rt, 0, MAXV, v, 1);}
void delA(int v) {sumA -= v; stA.erase(stA.find(v));}
void delB(int v) {sumB -= v; stB.erase(stB.find(v)); insert(rt, 0, MAXV, v, -1);}
ll ask(int k, int t, int opt) {
	int M = INF;
	if (!stA.empty()) chkmin(M, *stA.begin());
	if (!stB.empty()) chkmin(M, *stB.begin());
	ll res = opt * k + 1ll * (k - t) * (n - m) + sumA - sumB;
//	printf("! ask %d %d %d %lld\n", k, t, M, res);
	res += 1ll * max(t - k - M, 0) * n;
	auto P = query(rt, 0, MAXV, 0, t - k);
	res -= 1ll * (t - k) * P.fi - P.se;
	return res;
}
ll queryA(int k, int t) {delA(t); --n; ll res = ask(k, t, 1); insA(t); ++n; return res;}
ll queryB(int k, int t) {delB(t); --m; ll res = ask(k, t, -1); insB(t); ++m; return res;}
ll query(int k) {
	ll res = -INFll;
	chkmax(res, queryA(k, *stA.begin()));
	if (stB.size() >= 2) {
		int v = (*++stB.rbegin()) + k;
		multiset<int> :: iterator it = stA.lower_bound(v);
		int A = -1, B = -1;
		if (it != stA.end()) A = *it;
		if (it != stA.begin()) B = *--it;
		if (~A) chkmax(res, queryA(k, A));
		if (~B) chkmax(res, queryA(k, B));
	}
	chkmax(res, queryB(k, *stB.begin()));
	chkmax(res, queryB(k, *stB.rbegin()));
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), insA(a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), insB(b[i]);
	while (qu--) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int p, x; scanf("%d%d", &p, &x);
			delA(a[p]); a[p] = x; insA(a[p]);
		} else if (opt == 2) {
			int p, x; scanf("%d%d", &p, &x);
			delB(b[p]); b[p] = x; insB(b[p]);
		} else {
			int k; scanf("%d", &k);
			printf("%lld\n", query(k));
		}
	}
	return 0;
}