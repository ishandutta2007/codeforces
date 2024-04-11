#define FASTIO
// Created time: 2022/4/29 15:24:16
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
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
const int MAXN = 1e6;
const int MAXP = 2048;
const int MAXC = 11;
int n, N, c[MAXN + 5]; ll k, a[MAXN + 5], D;
vector<ll> pr; map<ll, vector<int> > qv;
vector<int> trs[MAXP + 5];
bool cmp(int x, int y) {return c[x] < c[y];}
void work(ll X, vector<int> vec) {
	sort(vec.begin(), vec.end(), cmp);
	int lim = min((int)vec.size(), N);
	static ll pw[MAXC + 2], F[MAXP + 5];
	for (int i = 0; i < N; i++) {
		ll tmp = X; pw[i] = 1;
		while (tmp % pr[i] == 0) tmp /= pr[i], pw[i] *= pr[i];
	}
	F[0] = 1;
	for (int i = 1; i < (1 << N); i++) {
		int id = 31 - __builtin_clz(i & (-i));
		F[i] = F[i & (i - 1)] * pw[id];
	}
	for (int i = 1; i < (1 << N); i++) if (F[i] <= k)
		for (int j = 0; j < lim; j++) trs[i].pb(vec[j]);
}
ll dp[MAXP + 5][MAXC + 5], prv[MAXP + 5][MAXC + 5];
vector<pii> used;
int main() {
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i]), D = __gcd(D, a[i]);
	for (int i = 1; i <= n; i++) read(c[i]);
	if (D == 1) return puts("0"), 0;
	for (int i = 2; 1ll * i * i <= D; i++) if (D % i == 0) {
		pr.pb(i);
		while (D % i == 0) D /= i;
	}
	if (D > 1) pr.pb(D);
	N = pr.size();
//	for (ll p : pr) printf("%lld ", p); printf("\n");
	for (int i = 1; i <= n; i++) {
		ll tmp = a[i], prd = 1;
		for (ll p : pr) while (tmp % p == 0) tmp /= p, prd *= p;
		qv[prd].pb(i);
	}
	for (auto p : qv) work(p.fi, p.se);
	vector<pii> tot;
	for (int i = 0; i < (1 << N); i++) {
		sort(trs[i].begin(), trs[i].end(), cmp);
		int lim = min((int)trs[i].size(), N);
		for (int j = 0; j < lim; j++) tot.pb(mp(trs[i][j], i));
	}
	int prv_id = 0; sort(tot.begin(), tot.end());
	memset(dp, 63, sizeof(dp)); memset(prv, 63, sizeof(prv));
	dp[0][0] = prv[0][0] = 0;
	for (int i = 0; i < tot.size(); i++) {
		pii pp = tot[i]; int msk = pp.se, id = pp.fi;
		if (id != prv_id) {
			prv_id = id;
			for (pii v : used) prv[v.fi][v.se] = dp[v.fi][v.se];
			used.clear();
		}
		int rst = (1 << N) - 1 - msk;
		for (int j = 0; j < N; j++) {
			for (int S = rst; ; --S &= rst) {
				if (dp[S | msk][j + 1] > prv[S][j] + c[id]) {
					dp[S | msk][j + 1] = prv[S][j] + c[id];
					used.pb(mp(S | msk, j + 1));
				}
				if (!S) break;
			}
		}
	}
	ll mn = 1e18;
	for (int i = 1; i <= N; i++) if (dp[(1 << N) - 1][i] < 1e18)
		chkmin(mn, dp[(1 << N) - 1][i] * i);
	if (mn != 1e18) printf("%lld\n", mn);
	else puts("-1");
	return 0;
}