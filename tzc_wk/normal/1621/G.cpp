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
const int MOD = 1e9 + 7;
int n, a[MAXN + 5], p[MAXN + 5], num, pos[MAXN + 5];
pii key[MAXN + 5], uni[MAXN + 5];
int t[MAXN + 5];
void clear() {for (int i = 1; i <= n; i++) t[i] = 0;}
void add(int x, int v) {for (int i = x; i <= n; i += (i & (-i))) t[i] = (t[i] + v) % MOD;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret = (ret + t[i]) % MOD; return ret;}
int dp_pre[MAXN + 5], dp_suf[MAXN + 5];
int suf_mx[MAXN + 5], mxcnt = 0;
void solve() {
	scanf("%d", &n); mxcnt = num = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), key[i] = mp(a[i], -i);
	sort(key + 1, key + n + 1);
	for (int i = 1; i <= n; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	for (int i = 1; i <= n; i++) p[i] = lower_bound(uni + 1, uni + num + 1, mp(a[i], -i)) - uni;
	for (int i = 1; i <= n; i++) pos[p[i]] = i;
//	printf("p: "); for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
	clear(); for (int i = 1; i <= n; i++) dp_pre[i] = (query(p[i]) + 1) % MOD, add(p[i], dp_pre[i]);
	clear(); for (int i = n; i; i--) dp_suf[i] = (query(n - p[i] + 1) + 1) % MOD, add(n - p[i] + 1, dp_suf[i]);
	clear();
	int cmx = 0, res = 0;
	for (int i = n; i; i--) {
		if (p[i] > cmx) cmx = p[i], suf_mx[++mxcnt] = p[i];
		else res = (res + 1ll * dp_pre[i] * dp_suf[i] % MOD) % MOD;
	}
//	printf("%d\n", res);
	for (int i = 0; i < mxcnt; i++) {
		static int tmp[MAXN + 5];
		for (int j = suf_mx[i + 1] - 1; j > suf_mx[i]; j--) {
			tmp[j] = (query(n - pos[j] + 1) + 1) % MOD;
			res = (res - 1ll * dp_pre[pos[j]] * tmp[j] % MOD + MOD) % MOD;
			add(n - pos[j] + 1, tmp[j]);
		}
		for (int j = suf_mx[i + 1] - 1; j > suf_mx[i]; j--)
			add(n - pos[j] + 1, MOD - tmp[j]);
	}
	printf("%d\n", res);
}
int main() {int qu; scanf("%d", &qu); while (qu--) solve(); return 0;}