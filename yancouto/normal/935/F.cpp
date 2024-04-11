#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
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

ll a[N];

struct dat {
	ll mn, mx, sum;
};

inline dat join(dat a, dat b) {
	return {min(a.mn, b.mn), max(a.mx, b.mx), a.sum + b.sum};
}

dat tr[N << 2];

void build(int i, int l, int r) {
	if(l == r) {
		tr[i].mn = tr[i].mx = a[l + 1] - a[l];
		tr[i].sum = abs(a[l + 1] - a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	tr[i] = join(tr[2 * i], tr[2 * i + 1]);
}

dat get(int i, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return {LLONG_MAX, LLONG_MIN, 0};
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	dat A = get(2 * i, l, m, ql, qr);
	dat B = get(2 * i + 1, m + 1, r, ql, qr);
	return join(A, B);
}

void add(int i, int l, int r, int p, ll x) {
	if(l == r) { tr[i].mn += x; tr[i].mx += x; tr[i].sum = abs(tr[i].mn); return; }
	int m = (l + r) / 2;
	if(p <= m)
		add(2 * i, l, m, p, x);
	else
		add(2 * i + 1, m + 1, r, p, x);
	tr[i] = join(tr[2 * i], tr[2 * i + 1]);
}

int geq0(int i, int l, int r, int ql) {
	if(r < ql || tr[i].mx < 0) return n;
	if(l == r) return l;
	int m = (l + r) / 2;
	int j;
	if((j = geq0(2 * i, l, m, ql)) != n)
		return j;
	return geq0(2 * i + 1, m + 1, r, ql);
}

int leq0(int i, int l, int r, int ql) {
	if(r < ql || tr[i].mn > 0) return n;
	if(l == r) return l;
	int m = (l + r) / 2;
	int j;
	if((j = leq0(2 * i, l, m, ql)) != n)
		return j;
	return leq0(2 * i + 1, m + 1, r, ql);
}

ll bit[N];
void add(int i, ll x) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += x;
}

ll get(int i) {
	ll sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]), add(i, a[i]), add(i + 1, -a[i]);
	build(1, 0, n - 2);
	int q;
	rd(q);
	while(q--) {
		int t, l, r; ll x;
		rd(t); rd(l); rd(r); rd(x); l--; r--;
		if(t == 2) {
			if(l)
				add(1, 0, n - 2, l - 1, x);
			if(r != n - 1)
				add(1, 0, n - 2, r, -x);
			//add(l, x);
			//add(r + 1, -x);
		} else {
			// talvez l == r corner
			ll ans = get(1, 0, n - 2, 0, n - 2).sum;
			//printf("base %lld\n", ans);
			int g0 = geq0(1, 0, n - 2, l - 1);
			int l0 = n;
			if(g0 < r)
				l0 = leq0(1, 0, n - 2, g0 + 1);
			ll best = LLONG_MIN;
			if(l0 <= r) {
				best = 2 * x;
			} else {
				if(g0 <= r && g0 > l - 1) {
					ll xg0 = get(1, 0, n - 2, g0, g0).mn;
					ll pg0 = get(1, 0, n - 2, g0 - 1, g0 - 1).mn;
					best = max(best, abs(xg0 - x) + abs(pg0 + x) - abs(xg0) - abs(pg0));
				}
				if(g0 > l) {
					ll m = get(1, 0, n - 2, l - 1, min(g0 - 2, r - 1)).mx;
					assert(m <= 0);
					best = max(best, x + abs(m + x) - abs(m));
				}
				if(g0 < r) {
					ll m = get(1, 0, n - 2, g0 + 1, r).mn;
					assert(m >= 0);
					best = max(best, x + abs(m - x) - abs(m));
				}
			}
			//printf("best %lld\n", best);
			printf("%lld\n", ans + best);
		}
	}

}