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

map<ll, pair<ll, ll> > segs;

void solve(){
	ll last = 1;
	REPN(i, 1, 10) {
		REP(j, 0, 1 << i) {
			ll v = 0;
			ll st10 = 1;
			REP(k, 0, i) {
				// v *= 10;
				if (j & (1 << k)) {
					v += 7 * st10;
				} else {
					v += 4 * st10;
				}
				st10 *= 10;
			}
			segs[v] = mp(last, v);
			//cout << v << " " << last << " " << v << endl;
			last = v + 1;
		}
	}
	ll l, r;
	cin >> l >> r;
	ll ans = 0;
	FA(it, segs) {
		ll cnt = min(r, it->_2._2) - max(l, it->_2._1) + 1;
		cnt = max(cnt, 0ll);
		ans += cnt * it->_1;
	}
	cout << ans << endl;
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