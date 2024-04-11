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

const int N = 112345;
ll sum[N << 2];
int mx[N << 2];

void set_(int i, int l, int r, int p, ll x) {
	if(l == r) return (void) (sum[i] = mx[i] = x);
	int m = (l + r) / 2;
	if(p <= m) set_(2 * i, l, m, p, x);
	else set_(2 * i + 1, m + 1, r, p, x);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
	mx[i] = max(mx[2 * i], mx[2 * i + 1]);
}

void go(int i, int l, int r, int ql, int qr, ll x) {
	if(l > qr || r < ql || mx[i] < x) return;
	if(l == r) return (void) (sum[i] = mx[i] = (sum[i] % x));
	int m = (l + r) / 2;
	go(2 * i, l, m, ql, qr, x);
	go(2 * i + 1, m + 1, r, ql, qr, x);
	sum[i] = sum[2 * i] + sum[2 * i + 1];
	mx[i] = max(mx[2 * i], mx[2 * i + 1]);
}

ll get(int i, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return 0;
	if(l >= ql && r <= qr) return sum[i];
	int m = (l + r) / 2;
	return get(2 * i, l, m, ql, qr) + get(2 * i + 1, m + 1, r, ql, qr);
}


int main() {
	int n, m;
	int i, j, k, l, r, x;
	rd(n); rd(m);
	for(i = 0; i < n; i++) {
		rd(x);
		set_(1, 0, n - 1, i, x);
	}
	while(m--) {
		int t;
		rd(t);
		if(t == 1) {
			rd(l); rd(r); l--; r--;
			printf("%lld\n", get(1, 0, n - 1, l, r));
		} else if(t == 2) {
			rd(l); rd(r); rd(x); l--; r--;
			go(1, 0, n - 1, l, r, x);
		} else {
			rd(k); rd(x); k--;
			set_(1, 0, n - 1, k, x);
		}
	}
}