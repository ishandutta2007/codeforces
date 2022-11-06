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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

// Segment tree for sum and single value update.

// Time: O(n) for build, O(log n) for get, O(log n) for update
// Memory: O(n)

// Features: 0-indexed, recursive, with template type

// Use: fill n, fill vals
// Call build()
// Call get_val(l, r) for get query
// Call upd_val(int pos, int val) for update query

// Modification: modify combine function for calculating other function (max, min, gcd, etc.)

const int MAXN = 2e5 + 5;

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return mp(v1._1 + v2._1, v1._2 + v2._2);
	}
	
	// Recursive get
	temp_type get_val(int ind, int tl, int tr, int l, int r){
		if (l > r) {
			return mp(0, 0ll);
		}
		if (tl == l && tr == r){
			return tt[ind];
		}
		int tm = (tl + tr) >> 1;
		if (r <= tm){
			return get_val(ind << 1, tl, tm, l, r);
		} else if (l > tm){
			return get_val((ind << 1) + 1, tm + 1, tr, l, r);
		} else {
			return combine(get_val(ind << 1, tl, tm, l, tm), get_val((ind << 1) + 1, tm + 1, tr, tm + 1, r));
		}
	}

	// Recursive get
	int get_kth(int ind, int tl, int tr, int k){
		if (tt[ind]._1 < k){
			return -1;
		}		
		if (tl == tr){
			return tl;
		}
		int tm = (tl + tr) >> 1;
		if (tt[ind << 1]._1 >= k){
			return get_kth(ind << 1, tl, tm, k);
		} else {
			return get_kth((ind << 1) + 1, tm + 1, tr, k - tt[ind << 1]._1);
		}
	}	
	
	// Recursive update (set value)
	void upd_val(int ind, int tl, int tr, int pos, temp_type new_val){
		if (tl == tr){
			tt[ind] = new_val;
			return;
		}
		int tm = (tl + tr) >> 1;
		if (pos <= tm){
			upd_val(ind << 1, tl, tm, pos, new_val);
		} else {
			upd_val((ind << 1) + 1, tm + 1, tr, pos, new_val);
		}
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]);
	}
	
	// Get (for call)
	temp_type get_val(int l, int r){
		return get_val(1, 0, n - 1, l, r);
	}
	
	// Recursive update (for call)
	void upd_val(int pos, temp_type new_val){
		upd_val(1, 0, n - 1, pos, new_val);
	}
	
	int get_kth(int k) {
		return get_kth(1, 0, n - 1, k);
	}
};

segment_tree<pair<int, ll> > tt;

pii per[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	tt.n = n;
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		a--;
		per[i] = mp(a, i);
	}
	sort(per, per + n);
	ll inv = 0ll;
	REP(i, 0, n) {
		int pos = per[i]._2;
		//printf("%d\n", pos);
		tt.upd_val(pos, mp(1, (ll)pos + 1));
		
		inv += tt.get_val(pos + 1, n - 1)._1;
		
		int median = i / 2 + 1;
		int med_ind = tt.get_kth(median);
		ll add_left = 0;
		if (i > 1) {
			ll cnt = median - 1;
			ll mn = med_ind - cnt + 1;
			ll sum_opt = cnt * (cnt - 1) / 2 + mn * cnt;
			ll sum_real = tt.get_val(0, med_ind - 1)._2;
			add_left = sum_opt - sum_real;
		}
		ll add_right = 0;
		if (i > 0) {
			ll cnt = i + 1 - median;
			ll mn = med_ind + 2;
			ll sum_opt = cnt * (cnt - 1) / 2 + mn * cnt;
			ll sum_real = tt.get_val(med_ind + 1, n - 1)._2;
			add_right = sum_real - sum_opt;
		}
		ll ans = inv + add_left + add_right;
		printf("%lld ", ans);
	}
	putchar('\n');
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