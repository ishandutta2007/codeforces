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
	
	// Values
	temp_type vals[MAXN];
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return gcd(v1, v2);
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
	
	// Build (for call)
	void build(){
		build(1, 0, n - 1);
	}
	
	// Get (for call)
	temp_type get_val(int l, int r){
		return get_val(1, 0, n - 1, l, r);
	}
};

segment_tree<ll> tt;

ll v[MAXN], g[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%lld", &v[i]);
	}
	if (n == 1) {
		printf("1\n");
		return;
	}
	REP(i, 0, n - 1) {
		tt.vals[i] = abs(v[i + 1] - v[i]);
	}
	tt.n = n - 1;
	tt.build();
	int ans = 0;
	int l = 0, r = 0;
	for(; l < tt.n; l++) {
		for(r = max(r, l); r < tt.n && tt.get_val(l, r) > 1; r++);
		r--;
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans + 1);
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