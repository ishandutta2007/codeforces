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
using namespace fastio;
const int MAXN = 3e5;
const int LOG_N = 19;
int n, qu, k, a[MAXN + 5] ,L[MAXN + 5], R[MAXN + 5];
pii st[LOG_N + 2][MAXN + 5]; vector<int> qv[MAXN + 5];
pii query_st(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return min(st[k][l], st[k][r - (1 << k) + 1]);
}
ll res[MAXN + 5];
int query(int l, int r, int x) {
	int posl = l / k * k + x;
	if (posl < l) posl += k;
	int posr = r / k * k + x;
	if (posr > r) posr -= k;
	if (posl > posr) return 0;
	return (posr - posl) / k + 1;
}
int main() {
	read(n); read(qu); read(k);
	for (int i = 1; i <= n; i++) read(a[i]), st[0][i] = mp(a[i], i);
	for (int i = 1; i <= qu; i++) read(L[i]), read(R[i]), qv[L[i]].pb(i);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	for (int i = 1; i <= k; i++) {
		vector<int> vec;
		for (int j = i; j <= n; j += k) {
			if (k != 1 && j - k >= 1)
				vec.pb(query_st(j - k + 1, j - 1).se);
			vec.pb(j);
		}
		static int stk[MAXN + 5];
		static ll sum[MAXN + 5];
		int tp = 0;
		for (int j = (int)(vec.size()) - 1; ~j; j--) {
			int p = vec[j];
			while (tp && a[stk[tp]] >= a[p]) tp--; stk[++tp] = p;
			sum[tp] = sum[tp - 1] + 1ll * a[p] * query(p, stk[tp - 1] - 1, i % k);
			if ((p - i) % k == 0) {
				for (int id : qv[p]) {
					int pos = (R[id] - L[id]) / k * k + L[id];
					int l = 1, r = tp, pp = 0;
					while (l <= r) {
						int mid = l + r >> 1;
						if (stk[mid] <= pos) pp = mid, r = mid - 1;
						else l = mid + 1;
					}
					res[id] = sum[tp] - sum[pp] + 1ll * a[stk[pp]] * query(stk[pp], pos, i % k);
				}
			}
		}
	}
	for (int i = 1; i <= qu; i++) print(res[i], '\n');
	print_final();
	return 0;
}