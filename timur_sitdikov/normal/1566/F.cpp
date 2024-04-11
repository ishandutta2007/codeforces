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

const int MAXN = 6e5 + 5;

ll a[MAXN];
pair<ll, ll> segs[MAXN];

ll eval(ll x, ll vx, ll y, ll t) {
	if (t <= y) {
		return vx + 2 * (t - x);
	} else {
		return vx + 2 * (y - x) + (t - y);
	}
}

vector<pair<ll, ll> > pp;

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	REP(i, 0, m) {
		scanf("%lld%lld", &segs[i]._2, &segs[i]._1);
	}
	REP(i, 0, n) {
		segs[i + m] = {a[i], a[i]};
	}
	sort(segs, segs + m + n);
	/*REP(i, 0, n + m) {
		printf("%lld %lld\n", segs[i]._2, segs[i]._1);
	}*/
	ll l = segs[0]._1;
	ll x = a[0];
	ll vx = x - l;
	ll y = x + (x - l);
	int j = 0;
	for(; j < n + m && segs[j]._1 <= a[0]; j++);
	for(int i = 1; i < n; i++) {
		
		//printf("%lld %lld %lld\n", x, vx, y);
		
		pp.clear();
		l = a[i - 1];
		for(; j < n + m && segs[j]._1 <= a[i]; j++) {
			if (j > 0 && segs[j]._1 == segs[j - 1]._1) {
				l = max(l, segs[j]._2);
				continue;
			}
			ll add = eval(x, vx, y, l);
			ll len = a[i] - segs[j]._1;
			pp.pb({add + len, a[i] + len});
			l = max(l, segs[j]._2);
		}
		x = a[i];
		int ind = 0, ind1 = 0;
		REP(i, 0, SZ(pp)) {
			if (pp[i]._1 < pp[ind]._1) {
				ind = i;
			}
			if (pp[i]._1 + pp[i]._2 < pp[ind1]._1 + pp[ind1]._2) {
				ind1 = i;
			}
		}
		vx = pp[ind]._1;
		if (pp[ind]._1 + pp[ind]._2 == pp[ind1]._1 + pp[ind1]._2) {
			y = pp[ind]._2;
		} else {
			y = pp[ind1]._1 + pp[ind1]._2 - vx;
		}
	}
	
	//printf("%lld %lld %lld\n", x, vx, y);
	
	l = max(l, a[n - 1]);
	for(; j < n + m; j++) {
		l = max(l, segs[j]._2);
	}
	ll ans = eval(x, vx, y, l);
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