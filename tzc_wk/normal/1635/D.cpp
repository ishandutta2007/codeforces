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
int n, p, a[MAXN + 5], fib[MAXN + 5], sum_fib[MAXN + 5];
bool ban[MAXN + 5];
int main() {
	scanf("%d%d", &n, &p); fib[0] = fib[1] = 1; unordered_map<int, int> has;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), has[a[i]] = 1;
	for (int i = 2; i <= p; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	sum_fib[0] = 1;
	for (int i = 1; i <= p; i++) sum_fib[i] = (sum_fib[i - 1] + fib[i]) % MOD;
	for (int i = 1; i <= n; i++) {
		vector<int> vec; int tmp = a[i];
		while (tmp) vec.pb(tmp & 1), tmp >>= 1;
		reverse(vec.begin(), vec.end());
		for (int j = 0, sum = 0; j + 1 < vec.size(); j++) {
			sum = sum << 1 | vec[j];
			if (has[sum]) {
				bool flg = 1;
				for (int l = j + 1, r; l < vec.size(); l = r) {
					r = l; while (r < vec.size() && vec[r] == vec[l]) ++r;
					if (!vec[l]) flg &= (r - l) % 2 == 0;
				}
				if (flg) ban[i] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) if (!ban[i]) {
		int dig = 32 - __builtin_clz(a[i]);
//		printf("%d\n", dig);
		if (dig <= p) res = (res + sum_fib[p - dig]) % MOD;
	}
	printf("%d\n", res);
	return 0;
}