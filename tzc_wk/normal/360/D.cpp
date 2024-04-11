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
const int MAXN = 1e5;
int n, m, mod, a[MAXN + 5], b[MAXN + 5], d, g, c[MAXN + 5];
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % mod)
		if (e & 1) ret = 1ll * ret * x % mod;
	return ret;
}
vector<int> pr;
bool check(int x) {
	for (int p : pr) if (qpow(x, (mod - 1) / p) == 1) return 0;
	return 1;
}
int hd[16777777], nxt[1111111], val[1111111], key[1111111], item_n = 0;
void ins(int x, int v) {
	val[++item_n] = v; key[item_n] = x;
	nxt[item_n] = hd[x & 16777215]; hd[x & 16777215] = item_n;
}
int query(int x) {
	for (int e = hd[x & 16777215]; e; e = nxt[e]) if (key[e] == x) return val[e];
	return -1;
}
int main() {
	scanf("%d%d%d", &n, &m, &mod); d = mod - 1;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), d = __gcd(b[i], d);
	for (int i = 1; i <= n; i++) a[i] = qpow(a[i], d);
	int tmp = mod - 1;
	for (int i = 2; i * i <= tmp; i++) if (tmp % i == 0) {
		pr.pb(i);
		while (tmp % i == 0) tmp /= i;
	}
	if (tmp > 1) pr.pb(tmp);
	for (int i = 1; i <= min(500, mod - 1); i++) if (check(i)) {g = i; break;}
	int pw = 1, lim = min(1000000, mod - 1);
	for (int i = 0; i < lim; i++) ins(pw, i), pw = 1ll * pw * g % mod;
	for (int i = 1; i <= n; i++) {
		int ipw = qpow(pw, mod - 2), ppw = a[i];
		for (int j = 0; j < 1000; j++) {
			int p = query(ppw);
			if (~p) {
				c[i] = j * lim + p;
				break;
			}
			ppw = 1ll * ppw * ipw % mod;
		}
		c[i] = __gcd(c[i], mod - 1);
	}
	vector<int> fac;
	for (int i = 1; i * i <= mod - 1; i++) if ((mod - 1) % i == 0) {
		fac.pb(i);
		if ((mod - 1) / i != i) fac.pb((mod - 1) / i);
	}
	sort(fac.begin(), fac.end()); map<int, int> occ, cnt, has;
	for (int i = 1; i <= n; i++) occ[c[i]] = 1;
	for (pii p : occ) for (int j : fac) if (j % p.fi == 0) has[j] = 1;
	int res = 0;
	for (int j : fac) cnt[j] = (mod - 1) / j;
	for (int i = (int)(fac.size()) - 1; ~i; i--) {
		for (int j = i + 1; j < fac.size(); j++) if (fac[j] % fac[i] == 0) {
			cnt[fac[i]] -= cnt[fac[j]];
		}
	}
	for (pii p : has) res += cnt[p.fi];
	printf("%d\n", res);
	return 0;
}
/*
126 1 892371481
454064832 417570397 807650026 466892263 791344450 336924589 1944729 579965567 597532886 242884248 571201658 854252534 421251558 532865386 378268553 626243819 52655615 200538225 876249837 49382562 240030741 620587222 436393590 638009495 733238502 388289028 247259968 686579911 441669632 779962142 14713099 335151186 762271979 143469455 314598656 425836835 393234728 76558278 37681984 705123315 467409058 679552102 887234913 597098940 656080544 514409337 297942107 386863076 572681110 462982810 702355212 489867353 708204254 421873458 432787970 340529638 263956558 554893764 332152577 429576245 499254755 808916354 221523897 237603643 533279729 582300328 720434258 880524706 580775256 389508352 798343273 828515504 223160304 498268147 347717041 530130911 305412761 61678154 425081992 94690688 41647458 314689990 806098130 227769244 654240625 430235365 877551724 726687649 336637644 620085895 209835456 135659961 393357172 109025884 844121397 420061468 514991440 348027753 480616426 41993598 796546736 282041658 30961000 816644732 550127122 604405967 7475731 47513393 457741151 298634431 197223503 210065831 580653127 229891936 743203760 802277727 259142393 632894836 657867426 287851541 174610825 139623734 88981046 643076502 804691267 485717206
1
*/