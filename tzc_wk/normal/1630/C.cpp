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
const int MAXN = 2e5;
int n, m, k, a[MAXN + 5]; pii p[MAXN + 5], pp[MAXN + 5];
vector<int> pos[MAXN + 5];
int dp[MAXN + 5];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[a[i]].pb(i);
	for (int i = 1; i <= n; i++) if (pos[i].size() >= 2) p[++m] = mp(pos[i][0], pos[i].back());
	sort(p + 1, p + m + 1); int mx = 0;
	for (int i = 1; i <= m; i++) {
		if (p[i].se > mx) pp[++k] = p[i];
		chkmax(mx, p[i].se);
	}
//	for (int i = 1; i <= k; i++) printf("%d %d\n", pp[i].fi, pp[i].se);
	mx = 0; multiset<int> st;
	for (int i = 1, j = 1; i <= k; i++) {
		while (j <= k && pp[j].se < pp[i].fi) {
			st.erase(st.find(dp[j] - pp[j].se));
			chkmax(mx, dp[j]); j++;
		}
		dp[i] = mx + pp[i].se - pp[i].fi - 1;
		if (!st.empty()) chkmax(dp[i], (*st.rbegin()) + pp[i].se - 1);
		st.insert(dp[i] - pp[i].se);
	}
	int res = 0;
	for (int i = 1; i <= k; i++) chkmax(res, dp[i]);
	printf("%d\n", res);
	return 0;
}