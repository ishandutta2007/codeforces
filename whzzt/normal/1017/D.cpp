#include <bits/stdc++.h>

#pragma optimize("no-stack-protector")
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define ALL(a) a.begin(), a.end()
#define lowbit(x) ((x) & -(x))

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> VI;

namespace io {
	const int L = (1 << 21) + 1;
	char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, L, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
	inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	template <class I> inline void gi (I & x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	template <class I> inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0', x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline char read () {
		for (c = gc(); c < 'a' || c > 'z'; c = gc());
		return c;
	}
	inline void gs (char *s) {
		int l;
		for (c = gc(); c < '0' || c > '9'; c = gc());
		for (l = 0; c <= '9' && c >= '0'; c = gc()) s[l] = c, ++l;
		s[l] = 0;
	}
	inline void ps (const char *s) {
		int l = strlen(s), i;
		for (i = 0; i < l; i ++) putc(s[i]);
	}
	struct IOC { ~ IOC () { flush (); } } _ioc_;
	inline double readld(){
		double x = 0, y = 1;
		for (c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') y = -1;
		assert(c != '.');
		for (c = gc(); c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
		x *= y;
		assert(c != 'e');
		if (c == '.') for (c = gc(); c <= '9' && c >= '0'; c = gc()) y *= 0.1, x += y * (c & 15);
		return x;
	}
	inline void printld(double x, int digit){
		print((ll)x), putc('.');
		for (x -= (ll)x; digit; --digit) x = x * 10, putc((int)x + '0'), x -= (int)x;
	}
} ;
using io::gi;
using io::gs;
using io::ps;
using io::putc;
using io::read;
using io::print;

inline int ctz(int a){ return __builtin_ctz(a); }
inline int ctz(uint a){ return __builtin_ctz(a); }
inline int ctz(ll a){ return __builtin_ctzll(a); }
inline int ctz(ull a){ return __builtin_ctzll(a); }
template <class T> inline T gcd(T a, T b){
	int shift = ctz(a | b);
	for (b >>= ctz(b), a >>= ctz(a); a; a -= b, a >>= ctz(a)) if (a < b) swap(a, b);
	return b << shift;
}
template <class T> void exgcd(T a, T b, T &x, T &y){
	if (!b) return (void)(x = 1, y = 0);
	exgcd(b, a % b, y, x), y -= a / b * x;
}
int inv(int a, int p){
	int x, y;
	exgcd(a, p, x, y);
	return (x % p + p) % p;
}
int fpow(int a, int t, int p){
	static int r;
	for (r = 1; t; a = (ll)a * a % p, t >>= 1) if (t & 1) r = (ll)r * a % p;
	return r;
}

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<class A> string to_string(A v) {
	bool first = true; string res = "{";
	for (const auto &x : v) {
		if (!first) res += ", ";
		first = false, res += to_string(x);
	}
	res += "}";
	return res;
}
void debug_out() { cerr << endl; }
template<class A, class...B> void debug_out(A H, B... T) { cerr << " " << to_string(H), debug_out(T...); }
void scan(){}
template<class A, class...B> void scan(A &a, B &... b) { gi(a), scan(b...); }

template <class T> inline bool chkmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }

const int N = 4105, M = 105;

int n, m, q, w[N], u, sw[N];
int cnt[N][M], bas[N];

int readint(){
	using namespace io;
	int res = 0;
	for (c = gc(); c < '0' || c > '1'; c = gc());
	for (int i = 0; i < n; i ++) res |= (c - '0') << i, c = gc();
	return res;
}

int main(){
	int i, j, S, v, k;
	scan(n, m, q);
	for (i = 0; i < n; i ++) scan(w[i]);
	u = (1 << n) - 1;
	for (i = 0; i <= u; i ++) {
		for (j = 0; j < n; j ++) if (i >> j & 1) {
			sw[i] += w[j];
		}
	}
	for (i = 0; i < m; i ++) ++bas[readint()];
	for (i = 0; i <= u; i ++) {
		for (j = 0; j <= u; j ++) {
			v = i ^ j ^ u;
			if (sw[v] <= 100) cnt[i][sw[v]] += bas[j];
		}
		for (j = 1; j <= 100; j ++) cnt[i][j] += cnt[i][j - 1];
	}
	for (i = 0; i < q; i ++) {
		v = readint(), scan(k);
		print(cnt[v][k]), putc('\n');
	}
}