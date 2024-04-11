#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

// Segment tree for sum and single value update.

// Time: O(n) for build, O(log n) for get, O(log n) for update
// Memory: O(n)

// Features: 0-indexed, recursive, with template type

// Use: fill n, fill vals
// Call build()
// Call get_val(l, r) for get query
// Call upd_val(int pos, int val) for update query

// Modification: modify combine function for calculating other function (max, min, gcd, etc.)

const int MAXN = 1e5 + 5;

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	// Values
	int vals[MAXN];
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return max(v1, v2);
	}
	
	// Recursive build
	void build(int ind, int tl, int tr){
		if (tl == tr){
			tt[ind] = vals[tl];
			return;
		}
		int tm = (tl + tr) >> 1;
		build(ind << 1, tl, tm);
		build((ind << 1) + 1, tm + 1, tr);
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]);
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
	
	// Build (for call)
	void build(){
		build(1, 0, n - 1);
	}
	
	// Get (for call)
	temp_type get_val(int l, int r){
		if (l > r) {
			return 0;
		}
		return get_val(1, 0, n - 1, l, r);
	}
	
	// Recursive update (for call)
	void upd_val(int pos, temp_type new_val){
		upd_val(1, 0, n - 1, pos, new_val);
	}
};

segment_tree<int> tt;

struct point {
	ll x, y;
	int ind;
} pt[MAXN];

ll p1, q1, p2, q2;

bool cmp1(const point &a, const point &b) {
	ll dx = b.x - a.x, dy = b.y - a.y;
	return dx * p1 < dy * q1;
}

bool cmp2(const point &a, const point &b) {
	ll dx = b.x - a.x, dy = b.y - a.y;
	ll v = dx * p2 - dy * q2;
	if (v) {
		return v < 0;
	}
	return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

void solve(){
	int n;
	scanf("%d%lld/%lld%lld/%lld", &n, &p1, &q1, &p2, &q2);
	REPN(i, 1, n) {
		scanf("%lld%lld", &pt[i].x, &pt[i].y);
	}
	sort(pt, pt + n + 1, cmp1);
	/*REPN(i, 0, n) {
		printf("%lld %lld\n", pt[i].x, pt[i].y);
	}
	return;*/
	int m = 0;
	REPN(i, 1, n) {
		if (cmp1(pt[i - 1], pt[i])) {
			m++;
		}
		pt[i].ind = m;
	}
	tt.n = m + 1;
	sort(pt, pt + n + 1, cmp2);
	/*REPN(i, 0, n) {
		printf("%lld %lld: %d\n", pt[i].x, pt[i].y, pt[i].ind);
	}
	return;*/
	REPN(i, 0, n) {
		int mx = tt.get_val(pt[i].ind + 1, tt.n - 1);
		//printf("%d: %d\n", i, mx);
		if (pt[i].x == 0 && pt[i].y == 0) {
			printf("%d\n", mx);
			return;
		}
		tt.upd_val(pt[i].ind, mx + 1);
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