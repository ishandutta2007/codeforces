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

const int MAXN = 5e5 + 5;

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	// Values
	int vals[MAXN];
	
	// Tree
	temp_type tt[4 * MAXN];
	temp_type const_val[4 * MAXN];
	bool is_const[4 * MAXN];
	
	// Set value on segment
	void set_const_value(int ind, int tl, int tr, temp_type val){
		is_const[ind] = true;
		const_val[ind] = val;
		tt[ind] = val;
	}
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return max(v1, v2);
	}
	
	// Push
	void push(int ind, int tl, int tr){
		if (tl != tr && is_const[ind]){
			int tm = (tl + tr) >> 1;
			set_const_value(ind << 1, tl, tm, const_val[ind]);
			set_const_value((ind << 1) + 1, tm + 1, tr, const_val[ind]);
			is_const[ind] = false;
		}
	}
	
	// Recursive build
	void build(int ind, int tl, int tr){
		if (tl == tr){
			tt[ind] = vals[tl];
			const_val[ind] = 0;
			is_const[ind] = false;
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
		push(ind, tl, tr);
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
	void upd_val(int ind, int tl, int tr, int l, int r, temp_type new_val){
		if (tl == l && tr == r){
			set_const_value(ind, tl, tr, new_val);
			return;
		}
		push(ind, tl, tr);
		int tm = (tl + tr) >> 1;
		if (r <= tm){
			upd_val(ind << 1, tl, tm, l, r, new_val);
		} else if (l > tm){
			upd_val((ind << 1) + 1, tm + 1, tr, l, r, new_val);
		} else {
			upd_val(ind << 1, tl, tm, l, tm, new_val);
			upd_val((ind << 1) + 1, tm + 1, tr, tm + 1, r, new_val);
		}
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]);
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
	void upd_val(int l, int r, temp_type new_val){
		upd_val(1, 0, n - 1, l, r, new_val);
	}
};

segment_tree<int> tree_fill, tree_empty;

vi g[MAXN];
int used[MAXN], tin[MAXN], tout[MAXN], _timer;

void dfs(int s) {
	used[s] = 1;
	tin[s] = tout[s] = _timer++;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (used[to]) {
			continue;
		}
		dfs(to);
		tout[s] = tout[to];
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	tree_fill.n = tree_empty.n = n;
	int q;
	scanf("%d", &q);
	REPN(i, 1, q) {
		int t, v;
		scanf("%d%d", &t, &v);
		if (t == 1) {
			tree_fill.upd_val(tin[v], tout[v], i);
		} else if (t == 2) {
			tree_empty.upd_val(tin[v], tin[v], i);
		} else {
			int last_fill = tree_fill.get_val(tin[v], tin[v]);
			int last_empty = tree_empty.get_val(tin[v], tout[v]);
			if (last_fill > last_empty) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
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