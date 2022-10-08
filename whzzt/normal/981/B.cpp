#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> PI;
typedef vector <int> VI;

namespace io {
	const int L = (1 << 21) + 1;
	char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, qu[55]; int f, qr;
#ifdef whzzt
	#define gc() getchar()
#else
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, L, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
#endif
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
	inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	template <class I>
	inline void gi (I & x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0', x /= 10;
		while (qr) putc (qu[qr --]);
	}
	struct IOC { ~ IOC () { flush (); } } _ioc_;
};
using io :: gi;
using io :: putc;
using io :: print;

map <int, int> w;
ll ret;
int n;

int main () {
	int i, x, y;
	scanf ("%d", &n);
	for (i = 0; i < n; i ++) {
		scanf ("%d%d", &x, &y), w[x] = max (w[x], y);
	}
	scanf ("%d", &n);
	for (i = 0; i < n; i ++) {
		scanf ("%d%d", &x, &y), w[x] = max (w[x], y);
	}
	for (auto t : w) ret += t.se;
	printf ("%lld\n", ret);
	return 0;
}