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
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

ll v[MAXN];
ll red[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%lld", &v[i]);
		red[i] = 0;
	}
	ll ans = 0;
	REPN(i, 1, n) {
		// Upd ans 
		ans += max(0ll, v[i] - 1 - red[i]);
		//printf("%lld ", ans);
		
		// Upd next
		ll cnt1 = max(0ll, red[i] - (v[i] - 1));
		red[i + 1] += cnt1;
		
		// Upd rest
		ll lim = n - i + 1;
		v[i] = min(v[i], lim);
		REPN(j, 2, v[i]) {
			red[i + j]++;
		}
	}
	printf("%lld\n", ans);
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