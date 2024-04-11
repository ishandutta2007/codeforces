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
const int MAXN = 50;
const int MOD = 998244353;
const ll INF = 1e18;
int n, m, a[MAXN + 5], b[MAXN + 5], res;
ll sum[MAXN + 5], mx = 0;
struct mat {
	int v[MAXN + 5][MAXN + 5];
	mat() {memset(v, 0, sizeof(v));}
	mat operator * (const mat &rhs) {
		mat res;
		for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) for (int k = 1; k <= m; k++)
			res.v[i][j] = (res.v[i][j] + 1ll * v[i][k] * rhs.v[k][j]) % MOD;
		return res;
	}
};
int calc(int l, int r) {
//	printf("calc %d %d\n", l, r);
	m = r - l + 1;
	static ll key[MAXN * 2 + 5], uni[MAXN * 2 + 5];
	int cnt = 0, num = 0;
	for (int i = l + 1; i <= r; i++) {
		ll L = sum[i - 1] + ((a[i] > 0) ? 1 : -1), R = sum[i];
		if (L > R) swap(L, R);
		if (L - 1 >= sum[l]) key[++cnt] = L - 1;
		key[++cnt] = R;
	}
	sort(key + 1, key + cnt + 1); key[0] = -INF;
	for (int i = 1; i <= cnt; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	mat prd;
	for (int i = l; i <= r; i++) if (sum[i] == sum[l]) prd.v[1][i - l + 1] = 1;
	for (int i = 2; i <= num; i++) {
		mat trs; vector<int> vec;
		for (int j = l + 1; j <= r; j++) {
			ll L = sum[j - 1] + ((a[j] > 0) ? 1 : -1), R = sum[j];
			if (L > R) swap(L, R);
			if (L <= uni[i] && uni[i] <= R) vec.pb(j);
		}
		for (int id : vec) for (int j = l; j < id; j++)
			trs.v[j - l + 1][id - l + 1] = 1;
		for (int id : vec) if (a[id] > 0) trs.v[id - l + 1][id - l + 1] = 1;
//		printf("itvl %d [%lld, %lld]\n", i, uni[i - 1] + 1, uni[i]);
//		for (int j = 1; j <= m; j++) for (int k = 1; k <= m; k++)
//			printf("%d%c", trs.v[j][k], " \n"[k == m]);
		ll len = uni[i] - uni[i - 1];
		for (; len; len >>= 1, trs = trs * trs) if (len & 1) prd = prd * trs;
//		printf("curdp: ");
//		for (int j = 1; j <= m; j++) printf("%d%c", prd.v[1][j], " \n"[j == m]);
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) sum = (sum + prd.v[1][i]) % MOD;
	return sum;
}
int main() {
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int ed = n, i = (n = 0) + 1; i <= ed; i++) if (a[i]) b[++n] = a[i];
	swap(a, b);
	if (!n) return puts("1 1"), 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	bool flg = 1;
	for (int i = 1; i <= n; i++) flg &= (a[i] < 0);
	if (flg) return printf("1 %d\n", (-sum[n] + 1) % MOD), 0;
	for (int i = 0; i <= n; i++) for (int j = i + 1; j <= n; j++)
		chkmax(mx, sum[j] - sum[i]);
	for (int i = 0; i <= n;) {
		int pos = -1;
		for (int j = i + 1; j <= n; j++) if (sum[j] - sum[i] == mx)
			pos = j;
		if (~pos) res = (res + calc(i, pos)) % MOD, i = pos + 1;
		else i++;
	}
	printf("%lld %d\n", mx + 1, res);
	return 0;
}