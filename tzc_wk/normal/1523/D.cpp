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
const int MAXM = 60;
int n, m, p; ll msk[MAXN + 5];
int Rand() {return rand() << 15 | rand();}
int main() {
	scanf("%d%d%d", &n, &m, &p); srand(1004535809);
	for (int i = 1; i <= n; i++) {
		static char str[MAXM + 5]; scanf("%s", str + 1);
		for (int j = 1; j <= m; j++) if (str[j] == '1') msk[i] |= 1ull << (j - 1);
	}
	int T = 20;
	pair<int, ll> res = mp(0, 0);
	while (T--) {
		int x = Rand() % n + 1;
		map<ll, int> id; map<int, ll> rid;
		int cur = (1 << __builtin_popcountll(msk[x]));
		int cc = __builtin_popcountll(msk[x]);
		for (ll S = msk[x]; ; --S &= msk[x]) {
			id[S] = --cur; rid[cur] = S;
			if (!S) break;
		}
		static int cnt[32777]; fill0(cnt);
		for (int i = 1; i <= n; i++) ++cnt[id[msk[i] & msk[x]]];
		for (int i = 0; i < cc; i++) for (int j = 0; j < (1 << cc); j++)
			if (~j >> i & 1) cnt[j] += cnt[j ^ (1 << i)];
		for (int j = 0; j < (1 << cc); j++) if (cnt[j] >= (n + 1 >> 1))
			chkmax(res, mp(__builtin_popcount(j), rid[j]));
	}
	for (int j = 0; j < m; j++) printf("%d", res.se >> j & 1);
	return 0;
}