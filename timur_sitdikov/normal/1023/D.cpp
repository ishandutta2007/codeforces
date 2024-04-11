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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

template<typename temp_type> struct segment_tree {
	// Elements count
	int n;
	
	// Values
	int vals[MAXN];
	
	// Tree
	temp_type tt[4 * MAXN];
	
	// Combine from two values
	temp_type combine(temp_type v1, temp_type v2){
		return v1 + v2;
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

segment_tree<ll> tt;

int val[MAXN];

vi vv[MAXN];

void solve(){
	int n, q;
	scanf("%d%d", &n, &q);
	int fl = 0;
	REP(i, 0, n) {
		scanf("%d", &val[i]);
		if (val[i]) {
			fl = 1;
		}
	}
	if (!fl) {
		printf("YES\n");
		REP(i, 0, n) {
			printf("%d ", q);
		}
		putchar('\n');
		return;
	}
	
	int last = 0;
	int pos0 = -1;
	int posq = -1;
	REP(i, 0, n) {
		if (val[i]) {
			last = val[i];
			if (last == q) {
				posq = i;
			}
		} else {
			pos0 = i;
			val[i] = last;
		}
	}
	for(int i = 0; !val[i]; i++) {
		val[i] = 1;
	}
	
	if (posq == -1) {
		if (pos0 == -1) {
			printf("NO\n");
			return;
		}
		val[pos0] = q;
	}
	
	REP(i, 0, n) {
		vv[val[i]].pb(i);
	}
	tt.n = n;
	for(int i = q; i; i--) {
		if (vv[i].empty()) {
			continue;
		}
		REP(j, 0, SZ(vv[i])) {
			tt.upd_val(vv[i][j], 1);
		}
		int l = vv[i][0], r = vv[i][SZ(vv[i]) - 1];
		if (tt.get_val(l, r) != r - l + 1) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	REP(i, 0, n) {
		printf("%d ", val[i]);
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