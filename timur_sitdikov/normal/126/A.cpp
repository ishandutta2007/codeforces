#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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

const int MAXN = 2e5 + 5;

ll get_val(ll t1, ll t2, ll t0, ll x1) {
	return (x1 * (t0 - t1) + t2 - t0 - 1) / (t2 - t0);
}

void solve(){
	ll t1, t2, x1, x2, t0;
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t0 && t0 == t2) {
		cout << x1 << " " << x2 << endl;
		return;
	}
	if (t1 == t0) {
		cout << x1 << " " << 0 << endl;
		return;
	}
	if (t0 == t2) {
		cout << 0 << " " << x2 << endl;
		return;
	}
	ll ans1 = 0, ans2 = x2;
	for(ll y1 = 1; y1 <= x1; y1++) {
		ll y2 = get_val(t1, t2, t0, y1);
		// cout << y1 << " " << y2 << endl;
		if (y2 <= x2 && (t1 * y1 + t2 * y2) * (ans1 + ans2) <= (t1 * ans1 + t2 * ans2) * (y1 + y2)) {
			ans1 = y1, ans2 = y2;
		}
	}
	cout << ans1 << " " << ans2 << endl;
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