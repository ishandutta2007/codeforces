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

const int MAXN = 5e5 + 5;

struct edge {
	int s, to, t;
	edge() {}
	edge(int _s, int _to, int _t) {
		s = _s, to = _to, t = _t;
	}
	int get_to(int from) {
		return from == s ? to : s;
	}
} ee[MAXN];

vi g[MAXN];

int used[MAXN];
int dis[2][MAXN];

void dfs1(int ind, int s) {
	used[s] = 1;
	REP(i, 0, SZ(g[s])) {
		int to = ee[g[s][i]].get_to(s);
		if (!used[to]) {
			dis[ind][to] = dis[ind][s] + 1;
			dfs1(ind, to);
		}
	}
}

int tin[2][MAXN], tout[2][MAXN], _timer[2];
int ee_to[2][MAXN];

void dfs2(int ind, int s) {
	used[s] = 1;
	tin[ind][s] = tout[ind][s] = _timer[ind]++;
	REP(i, 0, SZ(g[s])) {
		int to = ee[g[s][i]].get_to(s);
		if (!used[to]) {
			ee_to[ind][g[s][i]] = to;
			dfs2(ind, to);
			tout[ind][s] = tout[ind][to];
		}
	}
}

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

struct item {
	int val[2];
	int t;
	
	item() {
		val[0] = val[1] = t = 0;
	}
	
	void swap() {
		t ^= 1;
		std::swap(val[0], val[1]);
	}
};

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	int vals[MAXN];
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(const temp_type &v1, const temp_type &v2){
		temp_type res;
		res.t = 0;
		REP(i, 0, 2) {
			res.val[i] = max(v1.val[i], v2.val[i]);
		}
		return res;
	}
	
	void push(int ind) {
		if (tt[ind].t) {
			tt[ind].swap();
			tt[ind << 1].swap();
			tt[(ind << 1) + 1].swap();
		}
	}
	
	// Recursive build
	void build(int ind, int tl, int tr){
		if (tl == tr){
			tt[ind].t = 0;
			tt[ind].val[0] = vals[tl];
			tt[ind].val[1] = -1;
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
		push(ind);
		int tm = (tl + tr) >> 1;
		temp_type result;
		if (r <= tm){
			result = get_val(ind << 1, tl, tm, l, r);
		} else if (l > tm){
			result = get_val((ind << 1) + 1, tm + 1, tr, l, r);
		} else {
			result = combine(get_val(ind << 1, tl, tm, l, tm), get_val((ind << 1) + 1, tm + 1, tr, tm + 1, r));
		}
		return result;
	}	
	
	// Recursive update (set value)
	void upd_val(int ind, int tl, int tr, int l, int r){
		if (tl == l && tr == r){
			tt[ind].swap();
			return;
		}
		push(ind);
		int tm = (tl + tr) >> 1;
		if (r <= tm){
			upd_val(ind << 1, tl, tm, l, r);
		} else if (l > tm){
			upd_val((ind << 1) + 1, tm + 1, tr, l, r);
		} else {
			upd_val(ind << 1, tl, tm, l, tm);
			upd_val((ind << 1) + 1, tm + 1, tr, tm + 1, r);
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
	void upd_val(int l, int r){
		upd_val(1, 0, n - 1, l, r);
	}
};

segment_tree<item> tt[2];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		scanf("%d%d%d", &ee[i].s, &ee[i].to, &ee[i].t);
		g[ee[i].s].pb(i);
		g[ee[i].to].pb(i);
	}
	dfs1(0, 1);
	int s = 1;
	REPN(i, 1, n) {
		if (dis[0][s] < dis[0][i]) {
			s = i;
		}
		used[i] = 0;
	}
	dis[0][s] = 0;
	dfs1(0, s);
	int f = 1;
	REPN(i, 1, n) {
		if (dis[0][f] < dis[0][i]) {
			f = i;
		}
		used[i] = 0;
	}
	dfs1(1, f);
	REPN(i, 1, n) {
		used[i] = 0;
	}
	dfs2(0, s);
	REPN(i, 1, n) {
		used[i] = 0;
	}
	dfs2(1, f);
	//printf("%d; %d;\n", s, f);
	REP(k, 0, 2) {
		tt[k].n = n;
		REPN(i, 1, n) {
			tt[k].vals[tin[k][i]] = dis[k][i];
		}
		tt[k].build();
		
		/*REP(i, 0, n) {
			printf("%d ", tt[k].vals[i]);
		}
		putchar('\n');*/
		
		//printf("%d\n", tt[k].get_val(0, n - 1).val[0]);
	}
	REP(i, 1, n) {
		if (ee[i].t) {
			REP(k, 0, 2) {
				int l = tin[k][ee_to[k][i]];
				int r = tout[k][ee_to[k][i]];
				tt[k].upd_val(l, r);
			}
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		REP(k, 0, 2) {
			int l = tin[k][ee_to[k][x]];
			int r = tout[k][ee_to[k][x]];
			//printf("%d: %d %d\n", q, l, r);
			tt[k].upd_val(l, r);
		}
		int ans = max(tt[0].get_val(0, n - 1).val[0], tt[1].get_val(0, n - 1).val[0]);
		printf("%d\n", ans);
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