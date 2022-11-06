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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e18 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 1e6 + 5;

const int LCM = 360360;

ll a, b;
int k;

ll dp_a[MAXN];
ll dp_b[MAXN];
ll dp_lcm[LCM + 1];

void calc_dp_b() {
	REP(i, 1, MAXN) {
		dp_b[i] = dp_b[i - 1] + 1;
		REPN(j, 2, k) {
			int p = i - (b + i) % j;
			if (p >= 0) {
				dp_b[i] = min(dp_b[i], dp_b[p] + 1);
			}
		}
	}
}

void calc_dp_a() {
	for(int i = MAXN - 2; i >= 0; i--) {
		dp_a[i] = LL_INF;
	}
	for(int i = MAXN - 1; i > 0; i--) {
		dp_a[i - 1] = min(dp_a[i - 1], dp_a[i] + 1);
		REPN(j, 2, k) {
			int p = i - (a - (MAXN - 1 - i)) % j;
			if (p >= 0) {
				dp_a[p] = min(dp_a[p], dp_a[i] + 1);
			}
		}
	}
}

void calc_dp_lcm() {
	REP(i, 1, LCM + 1) {
		dp_lcm[i] = dp_lcm[i - 1] + 1;
		REPN(j, 2, k) {
			int p = i - i % j;
			dp_lcm[i] = min(dp_lcm[i], dp_lcm[p] + 1);
		}
	}
}

void solve(){
	scanf("%lld%lld%d", &a, &b, &k);
	if (a - b < MAXN) {
		calc_dp_b();
		printf("%lld\n", dp_b[a - b]);
		return;
	}
	calc_dp_b();
	calc_dp_a();
	calc_dp_lcm();
	ll offset_a = MAXN - 1 - a % LCM;
	ll offset_b = LCM - (b % LCM);
	ll cnt = ((a - a % LCM) - (b + offset_b)) / LCM;
	ll ans = LL_INF;
	//printf("%lld %lld %lld %lld\n", dp_b[offset_b], dp_lcm[LCM], cnt, dp_a[offset_a]);
	//printf("%lld\n", dp_lcm[LCM] * cnt);
	ans = dp_b[offset_b] + dp_lcm[LCM] * cnt + dp_a[offset_a];
	//printf("%lld %lld\n", dp_a[offset_a], dp_lcm[a % LCM]);
	printf("%lld\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}