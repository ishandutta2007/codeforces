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
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

// Segment tree for sum and update on segment (set const value on segment).

// Time: O(n) for build, O(log n) for get, O(log n) for update
// Memory: O(n)

// Features: 0-indexed, recursive, with template type

// Use: fill n, fill vals
// Call build()
// Call get_val(l, r) for get query
// Call upd_val(l, r, val) for update query

// Modification: modify set_const_value and combine (and probably push) functions 
// for calculating other function (max, sum, gcd, etc.)

// Segment tree for sum and single value update.

// Time: O(n) for build, O(log n) for get, O(log n) for update
// Memory: O(n)

// Features: 0-indexed, recursive, with template type

// Use: fill n, fill vals
// Call build()
// Call get_val(l, r) for get query
// Call upd_val(int pos, int val) for update query

// Modification: modify combine function for calculating other function (max, min, gcd, etc.)

// Segment tree for sum and update on segment (set const value on segment).

// Time: O(n) for build, O(log n) for get, O(log n) for update
// Memory: O(n)

// Features: 0-indexed, recursive, with template type

// Use: fill n, fill vals
// Call build()
// Call get_val(l, r) for get query
// Call upd_val(l, r, val) for update query

// Modification: modify set_const_value and combine (and probably push) functions 
// for calculating other function (max, sum, gcd, etc.)

template<typename temp_type> struct segment_tree_2 {
	// Elements count
	int n;
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return max(v1, v2);
	}
	
	// Recursive get
	temp_type get_val(int ind, int tl, int tr, int l, int r){
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
};

segment_tree_2<ll> tt1;

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return max(v1, v2);
	}
	
	// Recursive get
	temp_type get_val(int ind, int tl, int tr, int pos){
		if (tl == tr){
			return tt[ind];
		}
		int tm = (tl + tr) >> 1;
		if (pos <= tm){
			return combine(tt[ind], get_val(ind << 1, tl, tm, pos));
		} else {
			return combine(tt[ind], get_val((ind << 1) + 1, tm + 1, tr, pos));
		}
	}	
	
	// Recursive update (set value)
	void upd_val(int ind, int tl, int tr, int l, int r, temp_type add_val){
		if (tl == l && tr == r){
			tt[ind] = combine(tt[ind], add_val);
			return;
		}
		int tm = (tl + tr) >> 1;
		if (r <= tm){
			upd_val(ind << 1, tl, tm, l, r, add_val);
		} else if (l > tm){
			upd_val((ind << 1) + 1, tm + 1, tr, l, r, add_val);
		} else {
			upd_val(ind << 1, tl, tm, l, tm, add_val);
			upd_val((ind << 1) + 1, tm + 1, tr, tm + 1, r, add_val);
		}
	}
	
	// Get (for call)
	temp_type get_val(int pos){
		return get_val(1, 0, n - 1, pos);
	}
	
	// Recursive update (for call)
	void upd_val(int l, int r, temp_type add_val){
		upd_val(1, 0, n - 1, l, r, add_val);
	}
};

segment_tree<ll> tt2;

set<int> pos;

int h[MAXN], b[MAXN], l[MAXN], r[MAXN];
pii pp[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%d", &h[i]);
	}
	REPN(i, 1, n) {
		scanf("%d", &b[i]);
	}
	REPN(i, 1, n) {
		pp[i] = {h[i], i};
	}
	
	sort(pp + 1, pp + n + 1);
	pos.insert(0);
	pos.insert(n + 1);
	REPN(i, 1, n) {
		int cur = pp[i]._2;
		auto it = pos.upper_bound(cur);
		r[cur] = (*it);
		--it;
		l[cur] = (*it);
		pos.insert(cur);
	}
	
	tt1.n = tt2.n = n + 1;
	REP(i, 0, 4 * n) {
		tt2.tt[i] = -LL_INF;
	}
	REPN(i, 1, n) {
		ll new_val = tt1.get_val(l[i], i - 1) + b[i];
		ll set_val = max(new_val, tt2.get_val(i));
		tt2.upd_val(i, r[i] - 1, new_val);
		tt1.upd_val(i, set_val);
	}
	ll ans = tt1.get_val(n, n);
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