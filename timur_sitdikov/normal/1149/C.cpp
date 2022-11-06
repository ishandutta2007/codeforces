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

const int MAXN = 2e5 + 5;

struct node {
	int d, a, _2b, a_2b, c_2b, ac_2b;
	node() {}
	node(int d, int a, int _2b, int a_2b, int c_2b, int ac_2b) {
		this->d = d, this->a = a, this->_2b = _2b;
		this->a_2b = a_2b, this->c_2b = c_2b, this->ac_2b = ac_2b;
	}
	void output() {
		printf("%d %d %d %d %d %d\n", d, a, _2b, a_2b, c_2b, ac_2b);
	}
};

struct segment_tree {
	// Elements count
	int n;
	
	// Values
	int vals[MAXN];
	
	// Tree
	node tt[4 * MAXN];
	
	// Combine from two values
	node combine(const node &v1, const node &v2){
		return node(
			v1.d + v2.d, 
			max(v1.a, v1.d + v2.a), 
			max(v1._2b, -2 * v1.d + v2._2b), 
			max(max(v1.a_2b, -v1.d + v2.a_2b), v1.a - 2 * v1.d + v2._2b),
			max(max(v1.c_2b, -v1.d + v2.c_2b), v1._2b + v1.d + v2.a),
			max(max(v1.ac_2b, v2.ac_2b), max(v1.a - v1.d + v2.c_2b, v1.a_2b + v1.d + v2.a))
		);
	}
	
	// Recursive build
	void build(int ind, int tl, int tr){
		if (tl == tr){;
			tt[ind] = node(vals[tl], vals[tl], -2 * vals[tl], -vals[tl], -vals[tl], 0);
			//printf("%d %d:\n", tl, tr);
			//tt[ind].output();
			return;
		}
		int tm = (tl + tr) >> 1;
		build(ind << 1, tl, tm);
		build((ind << 1) + 1, tm + 1, tr);
		tt[ind] = combine(tt[ind << 1], tt[(ind << 1) + 1]);
		//printf("%d %d:\n", tl, tr);
		//tt[ind].output();
	}	
	
	// Recursive get
	node get_val(int ind, int tl, int tr, int l, int r){
		if (tl == l && tr == r){
			return tt[ind];
		}
		int tm = (tl + tr) >> 1;
		node result;
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
	void upd_val(int ind, int tl, int tr, int pos, int new_val){
		if (tl == tr){
			vals[tl] = new_val;
			tt[ind] = node(vals[tl], vals[tl], -2 * vals[tl], -vals[tl], -vals[tl], 0);
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
	node get_val(int l, int r){
		return get_val(1, 0, n - 1, l, r);
	}
	
	// Recursive update (for call)
	void upd_val(int pos, int new_val){
		upd_val(1, 0, n - 1, pos, new_val);
	}
};

segment_tree tt;

char c[MAXN];

void solve(){
	int n, q, l, r;
	scanf("%d%d%s", &n, &q, &c[0]);
	tt.n = 2 * n - 2;
	REP(i, 0, tt.n) {
		/*if (i) {
			tt.vals[i] = tt.vals[i - 1];
		}
		if (c[i] == '(') {
			tt.vals[i]++;
		} else {
			tt.vals[i]--;
		}*/
		if (c[i] == '(') {
			tt.vals[i] = 1;
			//tt.upd_val(i, 1);
		} else {
			//tt.upd_val(i, -1);
			tt.vals[i] = -1;
		}
	}
	tt.build();
	node v = tt.get_val(0, tt.n - 1);
	printf("%d\n", v.ac_2b);
	while(q--) {
		scanf("%d%d", &l, &r);
		l--, r--;
		if (c[l] == '(') {
			tt.upd_val(l, -1);
			tt.upd_val(r, 1);
		} else {
			tt.upd_val(l, 1);
			tt.upd_val(r, -1);
		}
		swap(c[l], c[r]);
		v = tt.get_val(0, tt.n - 1);
		printf("%d\n", v.ac_2b);
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