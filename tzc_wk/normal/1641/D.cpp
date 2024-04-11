#define FASTIO
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
const int MAXN = 1e5;
const u64 BS = 1004535809;
int n, m, a[MAXN + 5][6], w[MAXN + 5], ord[MAXN + 5], cnt[33];
unordered_map<u64, int> id;
int idcnt = 0, idv[MAXN + 5][33], occ[MAXN * 32 + 5];
bool check(int mid) {
	memset(occ, 0, sizeof(occ));
	for (int i = n, j = 1; i; i--) {
		while (j <= n && w[ord[i]] + w[ord[j]] <= mid) {
			for (int k = 0; k < (1 << m); k++) occ[idv[ord[j]][k]]++;
			j++;
		}
		int ss = 0;
		for (int k = 0; k < (1 << m); k++) {
			if (cnt[k]) ss -= occ[idv[ord[i]][k]];
			else ss += occ[idv[ord[i]][k]];
		}
		if (ss) return 1;
	}
	return 0;
}
int main() {
	read(n); read(m);
	for (int i = 1; i <= 31; i++) cnt[i] = cnt[i & (i - 1)] ^ 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) read(a[i][j]);
		read(w[i]); ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, [&](int x, int y) {return w[x] < w[y];});
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++) {
			vector<int> vec; u64 HS = 0;
			for (int k = 1; k <= m; k++) if (j >> (k - 1) & 1)
				vec.pb(a[i][k]);
			sort(vec.begin(), vec.end());
			for (int k = 0; k < vec.size(); k++) HS = HS * BS + vec[k];
			if (!id[HS]) id[HS] = ++idcnt;
			idv[i][j] = id[HS];
		}
	}
	ll L = 1, R = 2e9; int p = -1;
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid)) p = mid, R = mid - 1;
		else L = mid + 1;
	}
	printf("%d\n", p);
	return 0;
}