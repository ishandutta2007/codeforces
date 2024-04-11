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
const int MAXN = 2e5;
int n, a[MAXN + 5], b[MAXN + 5];
ll cx[MAXN + 5], cv[MAXN + 5], ax[MAXN + 5], av[MAXN + 5];
pair<double, int> pts[MAXN + 5];
pair<ll, ll> operator + (pair<ll, ll> lhs, pair<ll, ll> rhs) {
	return mp(lhs.fi + rhs.fi, lhs.se + rhs.se);
}
ll get(pair<ll, ll> p, int x) {return x * p.fi + p.se;}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	swap(a[1], b[1]); ax[1] = cx[1] = 1;
	for (int i = 2; i <= n; i++) av[i] = a[i];
	for (int i = 1; i <= n; i++) {//a[i] = ax[i] * x + av[i]
		cx[i] = -ax[i], cv[i] = b[i] - av[i];
		for (int j = i + i; j <= n; j += i) {
			ax[j] += cx[i]; av[j] += cv[i];
		}
	}
//	for (int i = 1; i <= n; i++) printf("%dx+%d\n", cx[i], cv[i]);
	ll sum = 0;
	vector<pair<double, int> > neg, pos;
	for (int i = 1; i <= n; i++) if (!cx[i]) sum += abs(cv[i]);
	for (int i = 1; i <= n; i++) {
		if (cx[i] < 0) neg.pb(mp(-1.0 * cv[i] / cx[i], i));
		if (cx[i] > 0) pos.pb(mp(-1.0 * cv[i] / cx[i], i));
	}
	vector<pair<ll, ll> > ng_pre, ng_suf, ps_pre, ps_suf;
	ng_pre.resize(neg.size() + 1, mp(0, 0));
	ng_suf.resize(neg.size() + 2, mp(0, 0));
	ps_pre.resize(pos.size() + 1, mp(0, 0));
	ps_suf.resize(pos.size() + 2, mp(0, 0));
	sort(neg.begin(), neg.end()); sort(pos.begin(), pos.end());
	for (int i = 1; i <= neg.size(); i++) ng_pre[i] = ng_pre[i - 1] + mp(cx[neg[i - 1].se], cv[neg[i - 1].se]);
	for (int i = 1; i <= pos.size(); i++) ps_pre[i] = ps_pre[i - 1] + mp(cx[pos[i - 1].se], cv[pos[i - 1].se]);
	for (int i = neg.size(); i; i--) ng_suf[i] = ng_suf[i + 1] + mp(cx[neg[i - 1].se], cv[neg[i - 1].se]);
	for (int i = pos.size(); i; i--) ps_suf[i] = ps_suf[i + 1] + mp(cx[pos[i - 1].se], cv[pos[i - 1].se]);
	int qu; scanf("%d", &qu);
	while (qu--) {
		int x; scanf("%d", &x); x = 2 * b[1] - x;
		int pps = lower_bound(pos.begin(), pos.end(), mp(1.0 * x, 0)) - pos.begin();
		int png = lower_bound(neg.begin(), neg.end(), mp(1.0 * x, 0)) - neg.begin();
		ll res = sum;
		res -= get(ng_pre[png], x);
		res += get(ng_suf[png + 1], x);
		res += get(ps_pre[pps], x);
		res -= get(ps_suf[pps + 1], x);
		printf("%lld\n", res);
	}
	return 0;
}