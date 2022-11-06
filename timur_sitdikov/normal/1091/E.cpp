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

const int MAXN = 5e5 + 5;

typedef ll temp_type;
struct segment_tree {
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

segment_tree tt;

int n;

int cnt[MAXN];
int vals[MAXN];

vi ans;

int cur_pos;

void upd(int cand) {
	if (cand == 0) {
		return;
	}
	for(; vals[cur_pos + 1] == cand; cur_pos++);
	vals[cur_pos]--;
	tt.upd_val(cur_pos, n, -1);
	int r = cur_pos - 1;
	int l = max(0, vals[cur_pos]);
	if (l <= r) {
		tt.upd_val(l, r, 1);
	}
	
	/*printf("%d %d\n", cand, cur_pos);
	REPN(i, 0, n) {
		printf("%04lld ", tt.get_val(i, i));
	}
	putchar('\n');*/
}

void solve(){
	scanf("%d", &n);
	ll sum = 0ll;
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
		sum += a;
	}
	sum += n;
	cnt[n]++;
	int top = 0;
	for(int i = n; i >= 0; i--) {
		REP(j, 0, cnt[i]) {
			vals[top++] = i;
		}
	}
	
	/*REPN(i, 0, n) {
		printf("%04d ", vals[i]);
	}
	putchar('\n');*/
	
	tt.n = n + 1;
	
	// vals[i]
	REP(i, 0, n) {
		tt.upd_val(i, n, vals[i]);
	}
	// i * (i + 1)
	REP(i, 0, n) {
		tt.upd_val(i, i, -(ll)i * (ll)(i + 1));
	}
	
	/*REPN(i, 0, n) {
		printf("%04lld ", tt.get_val(i, i));
	}
	putchar('\n');*/
	
	// min(vals[i], i + 1
	ll tmp = 0ll;
	REPN(i, 1, n) {
		tmp += min(1ll, (ll)vals[i]);
	}
	tt.upd_val(0, 0, -tmp);	
	
	int r = n;
	REP(i, 1, n) {
		//printf("%04lld ", tmp);
		
		tmp -= min(i, vals[i]);
		for(; r >= 0 && vals[r] <= i; r--);
		if (r > i) {
			tmp += (r - i);
		}
		
		tt.upd_val(i, i, -tmp);
	}
	//putchar('\n');
	/*putchar('\n');
	REP(i, 0, n) {
		ll aa = 0ll;
		REPN(j, 0, i) {
			aa += vals[j];
		}
		aa -= i * (i + 1);
		REPN(j, i + 1, n) {
			aa -= min(i + 1, vals[j]);
		}
		printf("%04lld ", aa);
	}
	putchar('\n');*/
	
	/*REPN(i, 0, n) {
		printf("%04lld ", tt.get_val(i, i));
	}
	putchar('\n');*/
	
	for(int cand = n; cand >= 0; cand--, sum--) {
		if (sum & 1) {
			upd(cand);
			continue;
		}
		if (tt.get_val(0, n - 1) <= 0) {
			ans.pb(cand);
		}
		upd(cand);
	}
	
	// output answer
	if (ans.empty()) {
		ans.pb(-1);
	}
	reverse(BE(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d ", ans[i]);
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