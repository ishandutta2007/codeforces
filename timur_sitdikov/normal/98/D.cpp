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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

vi vv;
map<int, int> cnt;

vector<pii> ans;

void rec_sol_a(int from, int mid, int to, int ind) {
	if (ind < 0) {
		return;
	}
	rec_sol_a(from, to, mid, ind - 1);
	REP(i, 0, vv[ind]) {
		ans.pb(mp(from, to));
	}
	rec_sol_a(mid, from, to, ind - 1);
}

void rec_sol_b(int from, int mid, int to, int ind) {
	if (vv[ind] == 1) {
		rec_sol_a(from, mid, to, ind);
		return;
	}
	if (ind == 0) {
		REP(i, 0, vv[ind] - 1) {
			ans.pb(mp(from, mid));
		}
		ans.pb(mp(from, to));
		REP(i, 0, vv[ind] - 1) {
			ans.pb(mp(mid, to));
		}
		return;
	}
	rec_sol_a(from, mid, to, ind - 1);
	REP(i, 0, vv[ind]) {
		ans.pb(mp(from, mid));
	}
	rec_sol_a(to, mid, from, ind - 1);
	REP(i, 0, vv[ind]) {
		ans.pb(mp(mid, to));
	}
	rec_sol_b(from, mid, to, ind - 1);
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	FA(it, cnt) {
		vv.pb(it->_2);
	}
	rec_sol_b(1, 2, 3, SZ(vv) - 1);
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d %d\n", ans[i]._1, ans[i]._2);
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