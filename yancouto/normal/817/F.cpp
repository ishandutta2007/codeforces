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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
#define set set_

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
const int M = 2123456;

int tr[M], lset[M], lswp[M];
void build(int i, int l, int r) {
	tr[i] = 1;
	if(l == r) return;
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
}

void unlaze(int i, int l, int r) {
	if(lset[i]) {
		tr[i] = lset[i];
		if(l != r)
			lset[2 * i] = lset[2 * i + 1] = lset[i],
			lswp[2 * i] = lswp[2 * i + 1] = false;
		lset[i] = 0;
	}
	if(lswp[i]) {
		if(tr[i] == 1) tr[i] = 2;
		else if(tr[i] == 2) tr[i] = 1;
		if(l != r)
			lswp[2 * i] = !lswp[2 * i],
			lswp[2 * i + 1] = !lswp[2 * i + 1];
		lswp[i] = false;
	}
}

void set(int i, int l, int r, int ql, int qr, int x) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		if(x <= 1) lset[i] = (1 << x);
		else lswp[i] = true;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	set(2 * i, l, m, ql, qr, x);
	set(2 * i + 1, m + 1, r, ql, qr, x);
	tr[i] = (tr[2 * i] | tr[2 * i + 1]);
}

int mex(int i, int l, int r) {
	unlaze(i, l, r);
	assert(tr[i] != 2);
	if(tr[i] == 1) return l;
	int m = (l + r) / 2;
	unlaze(2 * i, l, m);
	if(tr[2 * i] & 1) return mex(2 * i, l, m);
	else return mex(2 * i + 1, m + 1, r);
}


const int Q = 112345;
int t[Q]; ll l[Q], r[Q];

int main() {
	int i, j;
	rd(n);
	vector<ll> c;
	for(i = 0; i < n; i++) {
		rd(t[i]); rd(l[i]); rd(r[i]);
		c.pb(l[i]); c.pb(r[i]);
		c.pb(r[i] + 1ll);
	}
	c.pb(1ll);
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	int cn = int(c.size()) - 1;
	build(1, 0, cn);
	for(i = 0; i < n; i++) {
		int t = ::t[i];
		int l = lower_bound(c.begin(), c.end(), ::l[i]) - c.begin();
		int r = lower_bound(c.begin(), c.end(), ::r[i]) - c.begin();
		if(t == 1)
			set(1, 0, cn, l, r, 1);
		else if(t == 2)
			set(1, 0, cn, l, r, 0);
		else
			set(1, 0, cn, l, r, 2);
		printf("%lld\n", c[mex(1, 0, cn)]);
	}
}