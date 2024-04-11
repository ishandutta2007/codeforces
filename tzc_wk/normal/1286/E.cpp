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
typedef __int128_t i128;
typedef __uint128_t u128;
void _print(i128 x) {if (x) _print(x / 10), putchar(x % 10 + '0');}
void print(i128 x) {
	if (!x) printf("0\n");
	else {_print(x); putchar('\n');}
}
const int MAXN = 6e5;
const int LOG_N = 19;
int n, hib[MAXN + 5];
i128 ans = 0, sum = 0; map<int, int> cnt;
int s[MAXN + 5], st[LOG_N + 2][MAXN + 5];
int query(int l, int r) {
	int k = hib[r - l + 1];
	return min(st[k][r], st[k][l + (1 << k) - 1]);
}
int kmp[MAXN + 5], prv[MAXN + 5][26];
int main() {
	for (int i = 0; i <= 19; i++) hib[1 << i] = 1;
	hib[0] = -1;
	for (int i = 1; i <= MAXN; i++) hib[i] += hib[i - 1];
	scanf("%d", &n); int cl = 0;
	for (int i = 1; i <= n; i++) {
		static char buf[3]; int w; scanf("%s %d", buf + 1, &w);
		s[i] = (buf[1] - 'a' + ans % 26) % 26; w = w ^ (ans & 1073741823);
//		printf("s[%d] = %d\n", i, s[i]);
//		printf("w[%d] = %d\n", i, w);
		st[0][i] = w;
		for (int j = 1; (1 << j) <= i; j++) st[j][i] = min(st[j - 1][i], st[j - 1][i - (1 << j - 1)]);
		if (i == 1) {ans = w; print(ans); continue;}
		for (int j = 0; j < 26; j++) if (s[i] != j) {
			for (int k = prv[i - 1][j]; k; k = prv[k][j]) {
				int v = query(i - k, i - 1); cnt[v]--; sum -= v;
//				printf("%d died, %d\n", k, v);
			}
		}
		while (cl && s[cl + 1] != s[i]) cl = kmp[cl];
		if (s[cl + 1] == s[i]) ++cl;
		for (int j = 0; j < 26; j++) prv[i][j] = prv[cl][j];
		if (cl) prv[i][s[cl + 1]] = cl;
		kmp[i] = cl;
		if (s[1] == s[i]) sum += w, cnt[w]++;
		while (1) {
			map<int, int> :: iterator it = cnt.upper_bound(w);
			if (it == cnt.end()) break;
			int v = it -> fi, c = it -> se;
			sum -= 1ll * v * c; sum += 1ll * w * c;
			cnt.erase(it); cnt[w] += c;
		}
//		printf("occurences:\n");
//		for (auto p : cnt) printf("number %d occurs %d times\n", p.fi, p.se);
//		printf("! "); print(sum);
		ans += sum + query(1, i); print(ans);
	}
	return 0;
}