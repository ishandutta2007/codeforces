// Created time: 2022/6/6 20:12:47
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
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
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
const int MAXN = 1e6;
const int MAXV = 1e7;
int n, a[MAXN + 5], buc[MAXV + 5];
ll pre[MAXV + 5], nxt[MAXV + 5], mn = 1e18;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), buc[a[i]] = 1;
	for (int i = 1; i <= MAXV; i++) pre[i] = (buc[i]) ? i : pre[i - 1];
	nxt[MAXV + 1] = 1e15;
	for (int i = MAXV; i; i--) nxt[i] = (buc[i]) ? i : nxt[i + 1];
	for (int i = 1; i <= 2000000; i++) { //  sqrt(a[1] + k) = i
		if (1ll * i * i + i < a[1]) continue;
		ll L = max((ll)a[1], 1ll * i * i), R = 1ll * i * i + i;
		vector<pair<ll, ll> > vec; vec.pb(mp(L, R));
		// vec  a[1] 
		for (int stp = i, sum = 0; sum <= 3e6; sum += 2 * stp + 1, ++stp) {
			if (vec.empty()) break;
			vector<pair<ll, ll> > tmp = vec; vec.clear();
			ll delta = 1ll * (stp + 1) * (stp + 1) - 1 + a[1];
			for (pair<ll, ll> p : tmp) {
				//  a[1] + k = v floor(sqrt(x + k)) = stp  x 
				// [stp * stp - (v - a[1]), (stp + 1) * (stp + 1) - 1 - (v - a[1])]
				ll _L = delta - p.se, _R = delta - p.fi;
				if (_L > MAXV) {vec.pb(p); continue;}
				// i - pre[i] >= stp
				for (ll x = max(pre[_L] + stp, _L); x <= _R;) {
					if (x - pre[x] >= stp) {
						ll nt = min(nxt[x], _R + 1);
						vec.pb(mp(delta - (nt - 1), delta - x));
						x = nt + stp;
					} else x = pre[x] + stp;
				}
			}
		}
		if (!vec.empty()) for (pair<ll, ll> p : vec) chkmin(mn, p.fi - a[1]);
	}
	printf("%lld\n", mn);
	return 0;
}