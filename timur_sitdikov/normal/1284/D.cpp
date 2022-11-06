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

const int MAXN = 2e5 + 5;

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	// Values
	temp_type vals[MAXN];
	
	// Tree
	temp_type tt[4 * MAXN];
	temp_type add[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return max(v1, v2);
	}
	
	// Recursive build
	void build(int ind, int tl, int tr){
		if (tl == tr){
			tt[ind] = vals[tl];
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
	temp_type get_val(int ind, int tl, int tr, int l, int r){
		if (tl == l && tr == r){
			return tt[ind];
		}
		int tm = (tl + tr) >> 1;
		temp_type result;
		if (r <= tm){
			result = get_val(ind << 1, tl, tm, l, r);
		} else if (l > tm){
			result = get_val((ind << 1) + 1, tm + 1, tr, l, r);
		} else {
			result = combine(get_val(ind << 1, tl, tm, l, tm), get_val((ind << 1) + 1, tm + 1, tr, tm + 1, r));
		}
		result = result + add[ind];
		return result;
	}	
	
	// Recursive update (set value)
	void upd_val(int ind, int tl, int tr, int l, int r, temp_type add_val){
		if (tl == l && tr == r){
			add[ind] += add_val;
			tt[ind] += add_val;
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
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]) + add[ind];
	}
	
	// Build (for call)
	void build(){
		build(1, 0, n - 1);
	}
	
	// Get (for call)
	temp_type get_val(int l, int r){
		return get_val(1, 0, n - 1, l, r);
	}
	
	// Recursive update (for call)
	void upd_val(int l, int r, temp_type add_val){
		upd_val(1, 0, n - 1, l, r, add_val);
	}
};

segment_tree<int> tt;
int n;

map<int, int> coord1, coord2;
int n1, n2;
pair<pii, pii> pp[MAXN];

vector<pii> check[MAXN], add[MAXN];

int solve_ord() {
	tt.n = n2;
	REP(i, 0, MAXN) {
		tt.vals[i] = 0;
	}
	tt.build();
	
	REP(i, 0, MAXN) {
		check[i].clear();
		add[i].clear();
	}
	
	REP(i, 0, n) {
		check[coord1[pp[i]._1._1]].pb(mp(coord2[pp[i]._2._1], coord2[pp[i]._2._2]));
		add[coord1[pp[i]._1._2]].pb(mp(coord2[pp[i]._2._1], coord2[pp[i]._2._2]));
	}
	
	REP(i, 0, n1) {
		REP(j, 0, SZ(check[i])) {
			if (tt.get_val(check[i][j]._1, check[i][j]._2) > 0) {
				return 1;
			}
		}
		REP(j, 0, SZ(add[i])) {
			tt.upd_val(add[i][j]._1, add[i][j]._2, 1);
		}
	}
	
	return 0;
}

void solve(){
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d%d%d", &pp[i]._1._1, &pp[i]._1._2, &pp[i]._2._1, &pp[i]._2._2);
		coord1[pp[i]._1._1] = 0;
		coord1[pp[i]._1._2] = 0;
		coord2[pp[i]._2._1] = 0;
		coord2[pp[i]._2._2] = 0;
	}
	FA(it, coord1) {
		it->_2 = n1++;
	}
	FA(it, coord2) {
		it->_2 = n2++;
	}
	REP(k, 0, 2) {
		if (solve_ord()) {
			printf("NO\n");
			return;
		}
		REP(i, 0, n) {
			swap(pp[i]._1, pp[i]._2);
		}
		swap(coord1, coord2);
		swap(n1, n2);
	}
	printf("YES\n");
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