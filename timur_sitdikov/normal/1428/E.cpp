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

int a[MAXN];

set<pair<ll, pii> > st;

ll calc(ll l, ll c) {
	ll len1 = l / c;
	if (l % c) {
		ll c2 = l % c;
		ll c1 = c - c2;
		//printf("%lld %lld: %lld\n", l, c, c1 * len1 * len1 + c2 * (len1 + 1) * (len1 + 1));
		return c1 * len1 * len1 + c2 * (len1 + 1) * (len1 + 1);
	} else {
		//printf("%lld %lld: %lld\n", l, c, c * len1 * len1);
		return c * len1 * len1;
	}
	/*ll cnt1 = l / c;
	ll cnt2 = l % c;
	return cnt1 * c * c + cnt2 * (c + 1) * (c + 1);*/
}

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = 0;
	REP(i, 0, n) {
		scanf("%d", &a[i]);
		if (a[i] > 1) {
			st.insert({-(calc(a[i], 1) - calc(a[i], 2)), {i, 1}});
		} else {
			ans++;
		}
	}
	REP(i, n, k) {
		
		/*printf("st:\n");
		FA(it, st) {
			printf("%lld: %d %d\n", it->_1, it->_2._1, it->_2._2);
		}*/
		
		int ind = st.begin()->_2._1;
		ll l = a[ind];
		ll c = st.begin()->_2._2;
		c++;
		st.erase(st.begin());
		
		//printf("%lld %lld\n", l, c);
		
		if (l == c) {
			ans += c;
		} else {
			ll f1 = calc(l, c);
			ll f2 = calc(l, c + 1);
			st.insert({-(f1 - f2), {ind, c}});
		}
	}
	FA(it, st) {
		ll l = a[it->_2._1];
		ll c = it->_2._2;
		ans += calc(l, c);
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
    //cin >> t;
    while(t--){
        solve();
    }
}