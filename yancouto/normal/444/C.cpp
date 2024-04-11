#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

const int N = 112345;
ll mn[N << 2], mx[N << 2], sum[N << 2];
ll lz[N << 2], lzs[N << 2];

inline void unlaze(int i, int l, int r) {
	if(!lz[i]) return;
	assert(mx[i] == mn[i]);
	sum[i] += lzs[i] * ll(r - l + 1);
	mn[i] = mx[i] = lz[i];
	if(l != r) {
		lz[2 * i] = lz[2 * i + 1] = lz[i];
		lzs[2 * i] += lzs[i];
		lzs[2 * i + 1] += lzs[i];
	}
	lz[i] = lzs[i] = 0;
}

inline void upd(int i) {
	mn[i] = min(mn[2 * i], mn[2 * i + 1]);
	mx[i] = max(mx[2 * i], mx[2 * i + 1]);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
}

void build(int i, int l, int r) {
	if(l == r) return (void) (mn[i] = mx[i] = l);
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	upd(i);
}

void go(int i, int l, int r, int ql, int qr, ll x) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr && mn[i] == mx[i]) {
		lz[i] = x;
		lzs[i] = abs(x - mx[i]);
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	go(2 * i, l, m, ql, qr, x);
	go(2 * i + 1, m + 1, r, ql, qr, x);
	upd(i);
}

ll get(int i, int l, int r, int ql, int qr) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return 0;
	if(l >= ql && r <= qr) return sum[i];
	int m = (l + r) / 2;
	return get(2 * i, l, m, ql, qr) + get(2 * i + 1, m + 1, r, ql, qr);
}

int main() {
	int i, j;
	int m; ll x;
	rd(n); rd(m);
	build(1, 1, n);
	while(m--) {
		int t, l, r;
		rd(t);
		if(t == 1) {
			rd(l); rd(r); rd(x);
			go(1, 1, n, l, r, x);
		} else {
			rd(l); rd(r);
			printf("%lld\n", get(1, 1, n, l, r));
		}
	}

}