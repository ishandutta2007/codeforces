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
const ll MOD = 1e9 + 7;

const int MAXN = 1e3 + 5, MAXQ = 1e5 + 5;

int ans[MAXN][MAXN];

char op[MAXQ];

struct per_vec {
	vector<vi> per;
	int offset_i, offset_j, add;
	per_vec() {}
	per_vec(int n) {
		per.resize(n);
		REP(i, 0, n) {
			per[i].resize(n);
		}
		offset_i = 0;
		offset_j = 0;
		add = 0;
	}
};

void my_swap(per_vec &a, per_vec &b) {
	a.per.swap(b.per);
	swap(a.add, b.add);
	swap(a.offset_i, b.offset_i);
	swap(a.offset_j, b.offset_j);
}

void update(per_vec &pv1, per_vec &inv_pv1, per_vec &pv2, per_vec &inv_pv2, per_vec &pv12, per_vec &pv21, int add) {
	pv1.offset_i += add;
	inv_pv1.offset_i += add;
	pv2.offset_j += add;
	inv_pv2.add += add;
	pv12.offset_j += add;
	pv21.add += add;
}

per_vec per_row, inv_per_row, per_col, inv_per_col, ind_in_row, ind_in_col;

char add_op[200];

void solve(){
	int n, q;
	scanf("%d%d", &n, &q);
	add_op['R'] = add_op['D'] = 1;
	add_op['L'] = add_op['U'] = -1;
	per_row = per_vec(n);
	inv_per_row = per_vec(n);
	per_col = per_vec(n);
	inv_per_col = per_vec(n);
	ind_in_row = per_vec(n);
	ind_in_col = per_vec(n);
	REP(i, 0, n) {
		REP(j, 0, n) {
			int a;
			scanf("%d", &a);
			a--;
			per_row.per[i][j] = a;
			inv_per_row.per[i][a] = j;
			per_col.per[j][i] = a;
			inv_per_col.per[j][a] = i;
			ind_in_row.per[a][i] = j;
			ind_in_col.per[a][j] = i;
		}
	}
	scanf("%s", &op[0]);
	REP(j, 0, q) {
		char cur_op = op[j];
		if (cur_op == 'R' || cur_op == 'L') {
			update(per_col, inv_per_col, per_row, inv_per_row, ind_in_col, ind_in_row, add_op[cur_op]);
		} else if (cur_op == 'D' || cur_op == 'U') {
			update(per_row, inv_per_row, per_col, inv_per_col, ind_in_row, ind_in_col, add_op[cur_op]);
		} else if (cur_op == 'I') {
			my_swap(per_row, inv_per_row);
			my_swap(per_col, ind_in_row);
			my_swap(inv_per_col, ind_in_col);
		} else if (cur_op == 'C') {
			my_swap(per_col, inv_per_col);
			my_swap(per_row, ind_in_col);
			my_swap(inv_per_row, ind_in_row);
		}
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			int ind_i = ((i - per_row.offset_i) % n + n) % n;
			int ind_j = ((j - per_row.offset_j) % n + n) % n;
			ans[i][j] = ((per_row.per[ind_i][ind_j] + per_row.add) % n + n) % n;
		}
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			printf("%d ", ans[i][j] + 1);
		}
		putchar('\n');
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