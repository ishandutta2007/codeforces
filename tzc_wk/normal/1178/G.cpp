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
const int BLK = 777;
const ll INFll = 0x3f3f3f3f3f3f3f3fll;
int n, qu, a[MAXN + 5], b[MAXN + 5];
int hd[MAXN + 5], to[MAXN + 5], nxt[MAXN + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int suma[MAXN + 5], sumb[MAXN + 5];
int bgt[MAXN + 5], edt[MAXN + 5], tim = 0, rid[MAXN + 5];
void dfs0(int x) {
	rid[bgt[x] = ++tim] = x;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		suma[y] = suma[x] + a[y];
		sumb[y] = sumb[x] + b[y];
		dfs0(y);
	}
	edt[x] = tim;
}
struct solver {
	ll v[MAXN + 5], a[MAXN + 5];
	int bel[MAXN + 5], L[BLK + 5], R[BLK + 5];
	int tag[BLK + 5];
	vector<pair<ll, ll> > lns[BLK + 5];
	vector<ld> itr[BLK + 5];
	ld inter(ll k1, ll b1, ll k2, ll b2) {return (ld)1.0 * (b1 - b2) / (k2 - k1);}
	void rebuild(int b) {
		vector<pair<ll, ll> > vec; lns[b].clear(); itr[b].clear();
		for (int i = L[b]; i <= R[b]; i++) vec.pb(mp(a[i], v[i]));
		sort(vec.begin(), vec.end());
		for (int l = 0, r; l < vec.size(); l = r) {
			r = l; ll mx = -INFll;
			while (r < vec.size() && vec[l].fi == vec[r].fi) chkmax(mx, vec[r].se), ++r;
			while (lns[b].size() > 1 && itr[b].back() > inter(lns[b].back().fi, lns[b].back().se, vec[l].fi, mx))
				lns[b].ppb(), itr[b].ppb();
			if (!lns[b].empty()) itr[b].pb(inter(lns[b].back().fi, lns[b].back().se, vec[l].fi, mx));
			lns[b].pb(mp(vec[l].fi, mx));
		}
	}
	void init() {
		int blk_sz = 333;
		int blk_cnt = (n - 1) / blk_sz + 1;
		for (int i = 1; i <= blk_cnt; i++) {
			L[i] = (i - 1) * blk_sz + 1; R[i] = min(i * blk_sz, n);
			for (int j = L[i]; j <= R[i]; j++) bel[j] = i;
		}
		for (int i = 1; i <= blk_cnt; i++) rebuild(i);
	}
	void add(int l, int r, int x) {
		if (bel[l] == bel[r]) {
			for (int i = l; i <= r; i++) v[i] += 1ll * a[i] * x;
			rebuild(bel[l]);
		} else {
			for (int i = l; i <= R[bel[l]]; i++) v[i] += 1ll * a[i] * x;
			for (int i = L[bel[r]]; i <= r; i++) v[i] += 1ll * a[i] * x;
			rebuild(bel[l]); rebuild(bel[r]);
			for (int i = bel[l] + 1; i < bel[r]; i++) tag[i] += x;
		}
//		for (int i = 1; i <= n; i++) printf("y = %lld x + %lld\n", a[i], v[i]);
	}
	ll calc(int id, int x) {
		int l = 0, r = (int)(itr[id].size()) - 1, p = itr[id].size();
		while (l <= r) {
			int mid = l + r >> 1;
			if (x <= itr[id][mid]) p = mid, r = mid - 1;
			else l = mid + 1;
		}
		return 1ll * x * lns[id][p].fi + lns[id][p].se;
	}
	ll query(int l, int r) {
		if (bel[l] == bel[r]) {
			ll res = 0;
			for (int i = l; i <= r; i++) chkmax(res, 1ll * a[i] * tag[bel[i]] + v[i]);
			return res;
		} else {
			ll res = 0;
			for (int i = l; i <= R[bel[l]]; i++) chkmax(res, 1ll * a[i] * tag[bel[i]] + v[i]);
			for (int i = L[bel[r]]; i <= r; i++) chkmax(res, 1ll * a[i] * tag[bel[i]] + v[i]);
			for (int i = bel[l] + 1; i < bel[r]; i++) chkmax(res, calc(i, tag[i]));
			return res;
		}
	}
} S[2];
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 2, fa; i <= n; i++) {scanf("%d", &fa); adde(fa, i);}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	suma[1] = a[1]; sumb[1] = b[1]; dfs0(1);
	for (int i = 1; i <= n; i++) {
		S[0].v[i] = 1ll * suma[rid[i]] * abs(sumb[rid[i]]);
		S[0].a[i] = abs(sumb[rid[i]]);
		S[1].v[i] = -1ll * suma[rid[i]] * abs(sumb[rid[i]]);
		S[1].a[i] = -abs(sumb[rid[i]]);
	}
	S[0].init(); S[1].init();
	while (qu--) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int x, v; scanf("%d%d", &x, &v);
			S[0].add(bgt[x], edt[x], v);
			S[1].add(bgt[x], edt[x], v);
		} else {
			int x; scanf("%d", &x);
			printf("%lld\n", max(S[0].query(bgt[x], edt[x]), S[1].query(bgt[x], edt[x])));
		}
	}
	return 0;
}