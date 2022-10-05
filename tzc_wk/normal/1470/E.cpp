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
typedef __int128_t i128;
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
const int MAXN = 5e5;
int n, k, qu, p[MAXN + 5]; bool typ[MAXN + 5][6];
i128 dp[MAXN + 5][6], sum_dec[MAXN + 5][6], sum_inc[MAXN + 5][6];
// dp[i][j]: number of ways to select some itvls in an itvl of length i, with cost <= j
// sum_dec[i][j]: number of ways to select itvls, with the first itvl's left side <= i, and the first itvl is type 0, and total cost <= j
// sum_inc[i][j]: number of ways to select itvls, with the first itvl's left side <= i, and the first itvl is type 1, and total cost <= j
vector<int> rnk[MAXN + 5];
void clear() {
	memset(dp, 0, sizeof(dp));
	memset(sum_dec, 0, sizeof(sum_dec)); memset(sum_inc, 0, sizeof(sum_inc));
	memset(typ, 0, sizeof(typ));
}
void solve() {
	scanf("%d%d%d", &n, &k, &qu); clear();
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++)
		for (int l = 1; j + l - 1 <= k; l++)
			dp[i + l][j + l - 1] += dp[i][j];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++)
		dp[i][j] += dp[i][j - 1];
//	printf("%d\n", (int)dp[n][k]);
	for (int i = 1; i <= n; i++) {
		for (int j = 2; i + j - 1 <= n && j <= k + 1; j++) {
			vector<int> ori, nw;
			for (int l = i; l <= i + j - 1; l++) ori.pb(p[l]);
			for (int l = i + j - 1; l >= i; l--) nw.pb(p[l]);
			typ[i][j] = (nw > ori);
		}
		vector<pair<vector<int>, int> > vecs;
		for (int j = 2; i + j - 1 <= n && j <= k + 1; j++) {
			vector<int> tmp;
			for (int l = i + j - 1; l >= i; l--) tmp.pb(p[l]);
			for (int l = i + j; l <= min(i + k, n); l++) tmp.pb(p[l]);
			vecs.pb(mp(tmp, j));
		}
		rnk[i].clear(); sort(vecs.begin(), vecs.end());
		for (int j = 0; j < vecs.size(); j++) rnk[i].pb(vecs[j].se);
	}
	for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++)
		for (int l = 2; i + l - 1 <= n && l - 1 <= j; l++) {
			if (!typ[i][l]) sum_dec[i][j] += dp[n - (i + l - 1)][j - (l - 1)];
			else sum_inc[i][j] += dp[n - (i + l - 1)][j - (l - 1)];
		}
	for (int j = 0; j <= k; j++) for (int i = 1; i <= n; i++)
		sum_dec[i][j] += sum_dec[i - 1][j], sum_inc[i][j] += sum_inc[i - 1][j];
	while (qu--) {
		ll x; int y; scanf("%d%lld", &y, &x);
		if (dp[n][k] < x) {puts("-1"); continue;}
		int pre = 0, cst = k; vector<pii> vec;
		while (cst) {
			int l = pre + 1, r = n, p = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (sum_dec[mid][cst] - sum_dec[pre][cst] >= x) p = mid, r = mid - 1;
				else l = mid + 1;
			}
			if (p) {
				x -= sum_dec[p - 1][cst] - sum_dec[pre][cst];
				for (int j = 0; j < rnk[p].size(); j++) if (!typ[p][rnk[p][j]]) {
					if (rnk[p][j] - 1 <= cst) {
						if (x > dp[n - (p + rnk[p][j] - 1)][cst - rnk[p][j] + 1])
							x -= dp[n - (p + rnk[p][j] - 1)][cst - rnk[p][j] + 1];
						else {
							vec.pb(mp(p, p + rnk[p][j] - 1));
							cst -= rnk[p][j] - 1; pre = p + rnk[p][j] - 1;
							break;
						}
					}
				}
				continue;
			}
			x -= sum_dec[n][cst] - sum_dec[pre][cst];
			if (x == 1) break; --x;
			l = pre + 1, r = n, p = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (sum_inc[n][cst] - sum_inc[mid - 1][cst] >= x) p = mid, l = mid + 1;
				else r = mid - 1;
			}
			x -= sum_inc[n][cst] - sum_inc[p][cst];
			for (int j = 0; j < rnk[p].size(); j++) if (typ[p][rnk[p][j]]) {
				if (rnk[p][j] - 1 <= cst) {
					if (x > dp[n - (p + rnk[p][j] - 1)][cst - rnk[p][j] + 1])
						x -= dp[n - (p + rnk[p][j] - 1)][cst - rnk[p][j] + 1];
					else {
						vec.pb(mp(p, p + rnk[p][j] - 1));
						cst -= rnk[p][j] - 1; pre = p + rnk[p][j] - 1;
						break;
					}
				}
			}
		}
//		printf("!\n");
//		for (pii pp : vec) printf("%d %d\n", pp.fi, pp.se);
		bool flg = 0;
		for (pii pp : vec) {
			if (pp.fi <= y && y <= pp.se) {
				printf("%d\n", p[pp.se - (y - pp.fi)]);
				flg = 1; break;
			}
		}
		if (!flg) printf("%d\n", p[y]);
	}
}
int main() {
//	freopen("is.in", "r", stdin);
//	freopen("is.out", "w", stdout);
	int T_T; scanf("%d", &T_T);
	while (T_T--) solve();
	return 0;
}
/*
100 2 1
56 74 52 85 33 67 30 57 61 8 27 19 3 12 90 13 48 11 26 22 50 35 71 59 70 88 49 100 66 25 44 37 77 82 72 32 40 96 31 95 9 75 84 24 78 36 92 55 54 81 1 6 87 23 29 14 91 47 68 34 20 21 99 58 16 53 64 41 42 43 39 79 28 17 45 63 7 46 97 38 51 93 76 62 60 65 15 2 18 69 80 5 86 4 73 89 83 10 98 94
451 51
*/