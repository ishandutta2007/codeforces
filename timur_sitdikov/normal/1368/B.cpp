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

string ss = "codeforces";

void solve(){
	ll n;
	cin >> n;
	ll ans = LL_INF;
	int mn = INF;
	pii pp_mn = {-1, -1};
	REPN(a, 1, 50) {
		REPN(i, 1, 10) {
			ll s = 0, p = 1;
			REPN(j, 1, 10) {
				if (j <= i) {
					s += a;
					p *= a;
				} else {
					s += (a + 1);
					p *= (a + 1);
				}
			}
			if (p >= n && s < mn) {
				mn = s;
				pp_mn = mp(a, i);
			}
		}
	}
	REP(i, 0, 10) {
		REP(j, 0, pp_mn._1) {
			putchar(ss[i]);
		}
		if (i >= pp_mn._2) {
			putchar(ss[i]);
		}
	}
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