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
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 6e3 + 5;

ll x[MAXN], y[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", &x[i], &y[i]);
	}
	ll cnt31_tot = 0, cnt3_tot = 0;
	REP(i, 0, n) {
		ll cnt1 = 0, cnt3 = 0;
		REP(j, 0, n) {
			if (j == i) {
				continue;
			}
			ll g = gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
			if (g % 4 == 0) {
				cnt3++;
			} else {
				cnt1++;
			}
		}
		cnt3_tot += cnt3 * (cnt3 - 1) / 2;
		cnt31_tot += cnt3 * cnt1;
	}
	ll ans = cnt31_tot / 2 + cnt3_tot / 3;
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