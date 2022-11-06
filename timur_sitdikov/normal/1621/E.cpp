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

const int MAXN = 3e5 + 5;

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
		if (l > r) {
			return;
		}
		upd_val(1, 0, n - 1, l, r, add_val);
	}
};

segment_tree<int> tt;

ll teachers[MAXN];

vi pupils[MAXN];

ll sum_pupils[MAXN];

int is_good(int teacher_ind, ll sum, int cnt) {
	return teachers[teacher_ind] * cnt >= sum;
}

int get_ind(int n, ll sum, int cnt) {
	if (!is_good(n - 1, sum, cnt)) {
		return n;
	}
	if (is_good(0, sum, cnt)) {
		return 0;
	}
	int l = 0, r = n - 1;
	for(; l + 1 < r; ) {
		int mid = (l + r) >> 1;
		if (is_good(mid, sum, cnt)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return r;
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%lld", &teachers[i]);
	}
	sort(teachers, teachers + n);
	REP(i, 0, m) {
		int k;
		scanf("%d", &k);
		pupils[i].resize(k);
		sum_pupils[i] = 0;
		REP(j, 0, k) {
			scanf("%d", &pupils[i][j]);
			sum_pupils[i] += pupils[i][j];
		}
	}
	
	tt.n = n;
	REP(i, 0, tt.n) {
		tt.vals[i] = i + 1;
	}
	REP(i, 0, 4 * tt.n) {
		tt.tt[i] = 0;
		tt.add[i] = 0;
	}
	tt.build();
	REP(i, 0, m) {
		int pos = get_ind(n, sum_pupils[i], SZ(pupils[i]));
		tt.upd_val(0, pos - 1, 1);
	}
	
	REP(i, 0, m) {
		int pos_0 = get_ind(n, sum_pupils[i], SZ(pupils[i]));
		tt.upd_val(0, pos_0 - 1, -1);
		REP(j, 0, SZ(pupils[i])) {
			int pos_1 = get_ind(n, sum_pupils[i] - pupils[i][j], SZ(pupils[i]) - 1);
			tt.upd_val(0, pos_1 - 1, 1);
			if (tt.get_val(0, n - 1) > n) {
				putchar('0');
			} else {
				putchar('1');
			}
			tt.upd_val(0, pos_1 - 1, -1);
		}
		tt.upd_val(0, pos_0 - 1, 1);
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
    cin >> t;
    while(t--){
        solve();
    }
}