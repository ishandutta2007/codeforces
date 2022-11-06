#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;

ll a, b, c, d;
ll q, r;

ll calc(ll x) {
	ll ans = -a * x + b * c * x;
	ans -= b * ((q + 1) * r + q * (q + 1) / 2 * d);
	if (x <= q) {
		ll cnt = q + 1 - x;
		ans += b * (cnt * r + cnt * (cnt - 1) / 2 * d);
	}
	return ans;
}

void solve(){
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	if (a > c * b) {
		printf("-1\n");
		return;
	}
	if (d > c) {
		printf("%lld\n", a);
		return;
	}
	r = c % d;
	q = c / d;
	ll lo = 1, hi = 2e6 + 55;
	/*if (calc(hi) > calc(hi + 1)) {
		printf("-1\n");
		return;
	}*/
	while(lo + 5 < hi) {
		ll lo1 = (2 * lo + hi) / 3;
		ll hi1 = (lo + 2 * hi) / 3;
		ll vlo = calc(lo1);
		ll vhi = calc(hi1);
		if (vlo <= vhi) {
			hi = hi1;
		} else {
			lo = lo1;
		}
	}
	ll ans = 0;
	REPN(i, lo, hi) {
		ans = min(ans, calc(i));
	}
	printf("%lld\n", -ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}