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
const int MAXP = 2e4;
const int MOD = 998244353;
const int INV2 = 499122177;
const int MAXC = 5e6;
const int LOG_V = 60;
const ll LIM = (1ll << 60) - 1;
struct solver {
	struct node {int ch[2], lz, f, dep; ll l, r;} s[MAXP + 5];
	int rt = 0, ncnt = 0;
	vector<pair<ll, ll> > vecp[LOG_V + 2], vecf[LOG_V + 2];
	void insert(int &k, ll l, ll r, ll ql, ll qr, int pre) {
		if (!k) {
			k = ++ncnt; s[k].l = l; s[k].r = r;
			s[k].f = pre, s[k].dep = s[s[k].f].dep + 1;
		}
		if (s[k].lz) return;
		vecf[s[k].dep].pb(mp(ql, qr));
		if (ql <= l && r <= qr) return s[k].lz = 1, void();
		ll mid = l + r >> 1;
		if (qr <= mid) insert(s[k].ch[0], l, mid, ql, qr, k);
		else if (ql > mid) insert(s[k].ch[1], mid + 1, r, ql, qr, k);
		else {
			insert(s[k].ch[0], l, mid, ql, mid, k);
			insert(s[k].ch[1], mid + 1, r, mid + 1, qr, k);
		}
	}
	void read() {
		int num; scanf("%d", &num);
		while (num--) {
			ll l, r; scanf("%lld%lld", &l, &r);
			insert(rt, 0, LIM, l, r, 0);
		}
		for (int i = 1; i <= ncnt; i++) if (s[i].lz) vecp[s[i].dep].pb(mp(s[i].l, s[i].r));
	}
} A, B;
pair<ll, ll> p[MAXC + 5];
int pc = 0;
int main() {
	A.read(); B.read();
	for (int i = 1; i <= 61; i++) {
		for (auto p1 : A.vecf[i]) for (auto p2 : B.vecp[i]) {
			ll lim = (1ll << (61 - i)) - 1;
			ll L = (p1.fi ^ p2.fi) & (~lim), R = L + lim;
//			printf("[%lld, %lld] [%lld, %lld]\n", p1.fi, p1.se, p2.fi, p2.se);
			p[++pc] = mp(L, R);
		}
		for (auto p1 : A.vecp[i]) for (auto p2 : B.vecf[i]) {
			ll lim = (1ll << (61 - i)) - 1;
			ll L = (p1.fi ^ p2.fi) & (~lim), R = L + lim;
//			printf("[%lld, %lld] [%lld, %lld]\n", p1.fi, p1.se, p2.fi, p2.se);
			p[++pc] = mp(L, R);
		}
	}
	sort(p + 1, p + pc + 1); int res = 0;
	for (int l = 1, r; l <= pc; l = r) {
		r = l; ll mx = p[l].se; while (r <= pc && p[r].fi <= mx) chkmax(mx, p[r].se), r++;
//		printf("[%lld, %lld]\n", p[l].fi, mx);
		res = (res + 1ll * (p[l].fi + mx) % MOD * ((mx - p[l].fi + 1) % MOD) % MOD * INV2) % MOD;
	}
	printf("%d\n", res);
	return 0;
}