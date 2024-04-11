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

// 0-indexed Fenwick tree (for sum)
// Use: fill n, call init(MyArray)
// Call get_val(l, r) and upd_val(pos, add)
struct fenwick_tree{
	// Number of elements
	int n;
	
	// Items of the tree
	ll ft[MAXN];
	
	// Get query [l ... r]
	ll get_val(int l, int r){
		return get_val(r) - get_val(l - 1);
	}
	
	// Get query [0 ... r]
	ll get_val(int r){
		ll res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1){
			res += ft[r];
		}
		return res;
	}
	
	// Update query
	void upd_val(int pos, ll add){
		for(; pos < n; pos = (pos | (pos + 1))){
			ft[pos] += add;
		}
	}
};

fenwick_tree ft;

// Segment tree for max and update on segment (add value on segment).

// Time: O(n) for build, O(log n) for get, O(log n) for update
// Memory: O(n)

// Features: 0-indexed, recursive, with template type

// Use: fill n, fill vals
// Call build()
// Call get_val(l, r) for get query
// Call upd_val(l, r, val) for update query

// Modification: modify combine function 
// for calculating other function (min, sum, gcd, etc.)

struct segment_tree {
	// Elements count
	int n;
	
	// Values
	int vals[MAXN];
	
	// Tree
	pii tt[4 * MAXN];
	int add[4 * MAXN];
	
	// Combine from two values
	pii combine(const pii & v1, const pii & v2){
		// Reg rightmost max
		return max(v1, v2);
	}
	
	// Recursive build
	void build(int ind, int tl, int tr){
		if (tl == tr){
			int vv = vals[tl] - 1 - tl;
			if (vv > 0) {
				vv = -INF;
			}
			tt[ind] = mp(vv, tl);
			add[ind] = 0;
			return;
		}
		int tm = (tl + tr) >> 1;
		build(ind << 1, tl, tm);
		build((ind << 1) + 1, tm + 1, tr);
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]);
		add[ind] = 0;
	}	
	
	// Recursive get
	pii get_val(int ind, int tl, int tr, int l, int r){
		if (tl == l && tr == r){
			return tt[ind];
		}
		int tm = (tl + tr) >> 1;
		pii result;
		if (r <= tm){
			result = get_val(ind << 1, tl, tm, l, r);
		} else if (l > tm){
			result = get_val((ind << 1) + 1, tm + 1, tr, l, r);
		} else {
			result = combine(get_val(ind << 1, tl, tm, l, tm), get_val((ind << 1) + 1, tm + 1, tr, tm + 1, r));
		}
		result._1 += add[ind];
		return result;
	}	
	
	// Recursive update (set value)
	void upd_val(int ind, int tl, int tr, int l, int r, int add_val){
		if (tl == l && tr == r){
			add[ind] += add_val;
			tt[ind]._1 += add_val;
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
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]);
		tt[ind]._1 += add[ind];
	}
	
	// Build (for call)
	void build(){
		build(1, 0, n - 1);
	}
	
	// Get (for call)
	pii get_val(int l, int r){
		return get_val(1, 0, n - 1, l, r);
	}
	
	// Recursive update (for call)
	void upd_val(int l, int r, int add_val){
		if (l > r) {
			return;
		}
		upd_val(1, 0, n - 1, l, r, add_val);
	}
};

segment_tree tt;

vi to[MAXN];

vector<pii> qq[MAXN];

int ans[MAXN];

void solve(){
	int n, q;
	scanf("%d%d", &n, &q);
	REP(i, 0, n) {
		scanf("%d", &tt.vals[i]);
	}
	tt.n = n;
	tt.build();
	pii pp;
	for(int i = n - 1; i >= 0; i--) {
		while(1) {
			pp = tt.get_val(i, n - 1);
			if (pp._1 != 0) {
				break;
			}
			to[i].pb(pp._2);
			tt.upd_val(pp._2, pp._2, -INF);
			tt.upd_val(pp._2 + 1, n - 1, 1);
		}
	}
	REP(i, 0, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		r = n - 1 - r;
		qq[l].pb(mp(r, i));
	}
	ft.n = n;
	for(int i = n - 1; i >= 0; i--) {
		REP(j, 0, SZ(to[i])) {
			ft.upd_val(to[i][j], 1);
		}
		REP(j, 0, SZ(qq[i])) {
			ans[qq[i][j]._2] = ft.get_val(qq[i][j]._1);
		}
	}
	REP(i, 0, q) {
		printf("%d\n", ans[i]);
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