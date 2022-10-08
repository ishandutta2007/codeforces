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

const int N = 400005;

int n, L, a[N], b[N], lp[N], rp[N], qu[N], ql, qr, vl[N], vr[N];

bool chk (int mid) {
	int i;
	for (i = 0; i < n + n; i ++) {
		lp[i] = lower_bound (a, a + n + n, b[i] - mid) - a;
		rp[i] = upper_bound (a, a + n + n, b[i] + mid) - a - 1;
//		printf ("%d %d\n", lp[i], rp[i]);
	}
//	puts ("");
	for (i = 0; i < n + n; i ++) lp[i] -= i, rp[i] -= i;
	ql = 1, qr = 0;
	for (i = 0; i < n + n; i ++) {
		while (ql <= qr && qu[ql] <= i - n) qu[ql ++] = 0;
		while (ql <= qr && lp[qu[qr]] <= lp[i]) qu[qr --] = 0;
		qu[++ qr] = i;
		if (i >= n - 1) vl[i] = lp[qu[ql]];
	}
	ql = 1, qr = 0;
	for (i = 0; i < n + n; i ++) {
		while (ql <= qr && qu[ql] <= i - n) qu[ql ++] = 0;
		while (ql <= qr && rp[qu[qr]] >= rp[i]) qu[qr --] = 0;
		qu[++ qr] = i;
		if (i >= n - 1) vr[i] = rp[qu[ql]];
	}
	for (i = n - 1; i < n + n; i ++) if (vl[i] <= vr[i]) return true;
	return false;
}

int main () {
	int i, l, r, mid;
	scanf ("%d%d", &n, &L);
	for (i = 0; i < n; i ++) scanf ("%d", &a[i]);
	for (i = 0; i < n; i ++) scanf ("%d", &b[i]);
	sort (a, a + n), sort (b, b + n);
	for (i = n; i < n + n; i ++) a[i] = a[i - n] + L, b[i] = b[i - n] + L;
	l = 0, r = L, mid = (l + r) >> 1;
	while (l < r) {
		if (chk (mid)) r = mid; else l = mid + 1;
		mid = (l + r) >> 1;
	}
	printf ("%d\n", mid);
	return 0;
}