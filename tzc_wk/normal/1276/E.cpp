// Created time: 2022/6/22 20:13:17
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
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
ll a[5], b[5], D, _D, rem;
pair<vector<pair<ll, ll> >, pair<ll, ll> > shrink4(vector<ll> vec) {
	vector<pair<ll, ll> > ret;
	while (1) {
		sort(vec.begin(), vec.end());
		if (vec[3] - vec[0] <= 2 * D) break;
		if (vec[1] - vec[0] > vec[3] - vec[1]) {
			ret.pb(mp(vec[1], vec[3]));
			vec[3] = 2 * vec[1] - vec[3];
		} else if (vec[3] - vec[2] > vec[2] - vec[0]) {
			ret.pb(mp(vec[2], vec[0]));
			vec[0] = 2 * vec[2] - vec[0];
		} else if (vec[1] - vec[0] > vec[3] - vec[2]) {
			if ((vec[1] - vec[0]) * 2 >= vec[2] - vec[1]) {
				ret.pb(mp(vec[1], vec[0]));
				vec[0] = vec[1] * 2 - vec[0];
			} else {
				ret.pb(mp(vec[1], vec[2]));
				vec[2] = 2 * vec[1] - vec[2];
				ret.pb(mp(vec[0], vec[2]));
				vec[2] = 2 * vec[0] - vec[2];
			}
		} else {
			if ((vec[3] - vec[2]) * 2 >= vec[2] - vec[1]) {
				ret.pb(mp(vec[2], vec[3]));
				vec[3] = vec[2] * 2 - vec[3];
			} else {
				ret.pb(mp(vec[2], vec[1]));
				vec[1] = 2 * vec[2] - vec[1];
				ret.pb(mp(vec[3], vec[1]));
				vec[1] = 2 * vec[3] - vec[1];
			}
		}
	}
	if (vec[3] - vec[0] == D) {
		if (vec[1] == vec[3]) {
			ret.pb(mp(vec[0], vec[3]));
			vec[3] = 2 * vec[0] - vec[3];
		} else {
			ret.pb(mp(vec[3], vec[0]));
			vec[0] = 2 * vec[3] - vec[0];
		}
	}
	sort(vec.begin(), vec.end());
	assert(vec[3] - vec[0] == 2 * D);
	ll A = 0;
	for (int i = 1; i <= 3; i++) if (vec[i] == vec[i - 1]) A = vec[i];
	return mp(ret, mp(vec[0], A));
}
vector<pair<ll, ll> > move(ll x, ll y, ll A, ll B) {
	bool rev = 0;
	if (x > y) rev = 1, swap(x, y), swap(A, B);
	vector<pair<ll, ll> > ret;
	static pair<ll, int> c[4];
	c[0].fi = x; c[1].fi = x + D; c[2].fi = x + D * 2;
	c[0].se = 1 + (A == x);
	c[1].se = 1 + (A == x + D);
	c[2].se = 1 + (A == x + D * 2);
	function<void(int, int)> deal = [&](int A, int B) {
		for (int i = 1; i <= c[B].se; i++)
			ret.pb(mp(c[A].fi, c[B].fi));
		c[B].fi = 2 * c[A].fi - c[B].fi;
		sort(c, c + 3);
	};
	while (c[2].fi * 2 - c[0].fi <= y) deal(2, 0);
	while (abs(y - c[2].fi) > 10 * D) {
		while (c[2].fi * 2 - c[1].fi > y) {
			ll D1 = c[1].fi - c[0].fi, D2 = c[2].fi - c[1].fi;
			if (D1 <= D2) deal(1, 0);
			else {deal(1, 0); deal(1, 2);}
		}
		deal(2, 1);
	}
	while (1) {
		if (c[0].fi >= c[2].fi - 2 * D) break;
		ll D1 = c[1].fi - c[0].fi, D2 = c[2].fi - c[1].fi;
		if (D1 <= D2) deal(1, 0);
		else {deal(1, 0); deal(1, 2);}
	}
	if (c[2].fi - c[0].fi == D) {
		if (c[1].fi == c[2].fi) deal(0, 1);
		else deal(1, 2), deal(0, 1);
	}
	while (c[0].fi < y) {deal(1, 0); deal(1, 0); deal(2, 0);}
	int pos = 0;
	for (int i = 0; i < 3; i++) if (c[i].se == 2) pos = i;
	if (c[pos].fi != B) ret.pb(mp(c[1].fi, c[pos].fi));
	if (!rev) return ret;
	else {
		vector<pair<ll, ll> > nret;
		for (int i = (int)(ret.size()) - 1; ~i; i--)
			nret.pb(mp(ret[i].fi, 2 * ret[i].fi - ret[i].se));
		return nret;
	}
}
int main() {
	for (int i = 0; i < 4; i++) scanf("%lld", &a[i]);
	for (int i = 0; i < 4; i++) scanf("%lld", &b[i]);
	sort(a, a + 4); sort(b, b + 4);
	if (a[0] == a[3]) {
		if (b[0] != a[0] || b[3] != a[3]) return puts("-1"), 0;
		puts("0"); return 0;
	}
	for (int i = 1; i <= 3; i++) D = __gcd(D, a[i] - a[i - 1]);
	for (int i = 1; i <= 3; i++) _D = __gcd(_D, b[i] - b[i - 1]);
	if (D != _D) return puts("-1"), 0;
	rem = (a[0] % D + D) % D;
	for (int i = 0; i < 4; i++) if ((b[i] % D + D) % D != rem)
		return puts("-1"), 0;
	ll suma = 0, sumb = 0;
	for (int i = 0; i < 4; i++) suma += (((a[i] - rem) / D) % 2 == 0);
	for (int i = 0; i < 4; i++) sumb += (((b[i] - rem) / D) % 2 == 0);
	if (suma != sumb) return puts("-1"), 0;
	vector<pair<ll, ll> > xA, xB;
	auto ap = shrink4(vector<ll>{a[0], a[1], a[2], a[3]});
	auto bp = shrink4(vector<ll>{b[0], b[1], b[2], b[3]});
	vector<pair<ll, ll> > P, res;
	if (((bp.se.fi - ap.se.fi) / D) % 2 == 0)
		P = move(ap.se.fi, bp.se.fi, ap.se.se, bp.se.se);
	else {
		P = move(ap.se.fi, bp.se.fi + D, ap.se.se, bp.se.se + D);
		P.pb(mp(bp.se.fi + D * 2, bp.se.fi + D * 3));
		P.pb(mp(bp.se.fi + D, bp.se.fi + D * 2));
	}
	for (pair<ll, ll> p : xA) if (p.fi != p.se) res.pb(p);
	for (pair<ll, ll> p : ap.fi) if (p.fi != p.se) res.pb(p);
	for (pair<ll, ll> p : P) if (p.fi != p.se) res.pb(p);
	for (int i = (int)(bp.fi.size()) - 1; ~i; i--)
		if (bp.fi[i].fi != bp.fi[i].se)
			res.pb(mp(bp.fi[i].fi, bp.fi[i].fi * 2 - bp.fi[i].se));
	for (int i = (int)(xB.size()) - 1; ~i; i--)
		if (xB[i].fi != xB[i].se)
			res.pb(mp(xB[i].fi, xB[i].fi * 2 - xB[i].se));
	printf("%d\n", (int)(res.size()));
	for (pair<ll, ll> p : res) printf("%lld %lld\n", p.se, p.fi);
	return 0;
}