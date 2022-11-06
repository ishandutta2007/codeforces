#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 5e5 + 5;

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
		return get_val(1, 0, n - 1, l, r);
	}
	
	// Recursive update (for call)
	void upd_val(int pos, temp_type new_val){
		upd_val(1, 0, n - 1, pos, new_val);
	}
};

segment_tree<int> tt;

vi inds[MAXN];

int ans[MAXN];
set<int> used;

void solve(){
	int n;
	scanf("%d", &n);
	tt.n = n;
	REPN(i, 0, n) {
		inds[i].clear();
		ans[i] = -1;
	}
	used.clear();
	used.insert(1);
	REP(i, 0, n) {
		int v;
		scanf("%d", &v);
		if (v != -1) {
			v--;
			inds[v].pb(i);
		}
		tt.vals[i] = v;
	}
	tt.build();
	int cur = n;
	for(int i = n; i >= 0; i--) {
		if (/*SZ(inds[i]) > 0 && */i < n && ans[i] == -1) {
			used.insert(-i);
			ans[i] = cur--;
		}
		REP(j, 0, SZ(inds[i])) {
			int pos = inds[i][j];
			int l = *used.lower_bound(-pos);
			l = (-l) + 1;
			int r = pos - 1;
			if (l <= r) {
				int v = tt.get_val(l, r);
				if (v > pos) {
					printf("-1\n");
					return;
				}
			}
			used.insert(-pos);
			ans[pos] = cur--;
		}
	}
	REP(i, 0, n) {
		if (ans[i] == -1) {
			ans[i] = cur--;
		}
	}
	REP(i, 0, n) {
		printf("%d ", ans[i]);
	}
	putchar('\n');
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();    
    }
}