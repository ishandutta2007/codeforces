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

const int MAXN = 1e5 + 5;

int n;
ll k;
int v[MAXN];
pair<ll, int> pp[MAXN];
ll bs_vals[MAXN];

int per[MAXN];

int ft[MAXN];

void add(int ind){
	for(int i = ind; i <= n; i = (i | (i + 1))){
		ft[i]++;
	}
}

int get(int r){
	int ans = 0;
	for(int i = r; i >= 0; i = (i & (i + 1)) - 1){
		ans += ft[i];
	}
	return ans;
}

bool check(ll mid) {
	//printf("Check %lld\n", mid);
	// Init
	REP(i, 0, n) {
		ft[i] = 0;
	}
	// Go one by one
	ll offset = 0;
	ll cur = 0;
	for(int i = n - 1; i >= 0; i--) {
		// Calculate count of greater or equal numbers
		int ind = lower_bound(bs_vals, bs_vals + n, mid + offset) - bs_vals;
		int ge = n - ind;
		int deleted = n - 1 - i;
		if (ind) {
			deleted -= get(ind - 1);
		}
		cur += ge - deleted;
		
		//printf("%d: check %lld, ge = %d, deleted = %d\n", i, mid + offset, ge, deleted);
		// Remove element
		add(per[i]);
		offset += v[i];
		//printf("Updating: remove at %d\n", per[i]);
	}
	//printf("Found in total %lld\n", cur);
	return cur >= k;
}


void solve(){
	scanf("%d%lld", &n, &k);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
	}
	ll sum = 0;
	for(int i = n - 1; i >= 0; i--) {
		sum += v[i];
		pp[i] = mp(sum, i);
	}
	sort(pp, pp + n);
	REP(i, 0, n) {
		bs_vals[i] = pp[i]._1;
		per[pp[i]._2] = i;
	}
	//check(4);
	ll l = -1e15 - 50, r = 1e15 + 50;
	for(; l + 1 < r; ) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%lld\n", l);
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