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
const int MAXN = 1e4;
const ll INF = 1e18;
int n; ll h[MAXN + 5], mx_pre[MAXN + 5], mx_suf[MAXN + 5], res = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
	for (int i = 1; i <= n; i++) {
		ll mn = INF;
		for (int j = i; j <= n; j++) {
			chkmin(mn, h[j]);
			chkmax(mx_pre[j], 1ll * mn * (j - i + 1));
			chkmax(mx_suf[i], 1ll * mn * (j - i + 1));
		}
	}
	for (int i = 1; i <= n; i++) chkmax(mx_pre[i], mx_pre[i - 1]);
	for (int i = n; i; i--) chkmax(mx_suf[i], mx_suf[i + 1]);
	for (int i = 0; i <= n; i++) chkmax(res, mx_pre[i] + mx_suf[i + 1]);
	for (int i = 1; i <= n; i++) {
		int L = 0, R = n + 1;
		for (int j = i - 1; j; j--) if (h[j] < h[i]) {L = j; break;}
		for (int j = i + 1; j <= n; j++) if (h[j] < h[i]) {R = j; break;}
		static ll sufmx[MAXN + 5], mn1[MAXN + 5], mn2[MAXN + 5];
		memset(mn1, 63, sizeof(mn1)); memset(mn2, 63, sizeof(mn2));
		for (int j = L; j; j--) mn1[j] = min(mn1[j + 1], h[j]);
		for (int j = R; j <= n; j++) mn2[j] = min(mn2[j - 1], h[j]);
		for (int j = n; j >= R; j--) sufmx[j] = max(sufmx[j + 1], 1ll * mn2[j] * (j - L));
		for (int j = 1, k = R; j <= L; j++) {
			while (k <= n && mn1[j] + mn2[k] >= h[i]) ++k;
			chkmax(res, 1ll * mn1[j] * (R - j) + 1ll * (h[i] - mn1[j]) * (k - L - 1));
			chkmax(res, 1ll * mn1[j] * (R - j) + sufmx[k]);
		}
		for (int k = n, j = L; k >= R; k--) {
			while (j && mn2[k] + mn1[j] >= h[i]) --j;
			chkmax(res, 1ll * mn2[k] * (k - L) + 1ll * (h[i] - mn2[k]) * (R - j - 1));
		}
		for (int j = L, k = R; j; j--) {
			while (k <= n && mn1[j] <= mn2[k]) ++k;
			chkmax(res, 1ll * mn1[j] * (k - j) + 1ll * (h[i] - mn1[j]) * (R - L - 1));
		}
		for (int k = R, j = L; k <= n; k++) {
			while (j && mn2[k] <= mn1[j]) --j;
			chkmax(res, 1ll * mn2[k] * (k - j) + 1ll * (h[i] - mn2[k]) * (R - L - 1));
		}
	}
	printf("%lld\n", res);
	return 0;
}