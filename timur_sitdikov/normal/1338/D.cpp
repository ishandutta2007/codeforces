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

vi g[MAXN];

int dp0[MAXN], dp1[MAXN], dp_prv0[MAXN], dp_prv1[MAXN], ans0[MAXN], ans1[MAXN];
int prv[MAXN];

int get_0(int mx0, int mx1, int cnt) {
	return max(mx0, mx1) + cnt - 1;
}

int get_1(int mx0) {
	return mx0 + 1;
}

void upd(int s, bool use_prv, int &ans0, int &ans1) {
	int mx0 = 0, mx1 = 0, cnt = 0;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (to != prv[s]) {
			cnt++;
			mx0 = max(mx0, dp0[to]);
			mx1 = max(mx1, dp1[to]);
		} else if (use_prv) {
			cnt++;
			mx0 = max(mx0, dp_prv0[s]);
			mx1 = max(mx1, dp_prv1[s]);
		}
	}
	ans0 = get_0(mx0, mx1, cnt);
	ans1 = get_1(mx0);
}

void dfs1(int s) {
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (to != prv[s]) {
			prv[to] = s;
			dfs1(to);
		}
	}
	upd(s, false, dp0[s], dp1[s]);
}

void upd_max(int cur, int &mx, int &mxx) {
	if (cur >= mx) {
		mxx = mx, mx = cur;
	} else if (cur >= mxx) {
		mxx = cur;
	}
}

void dfs2(int s) {
	upd(s, true, ans0[s], ans1[s]);
	int mx0 = dp_prv0[s], mx1 = dp_prv1[s], mxx0 = 0, mxx1 = 0, cnt = SZ(g[s]) - 1;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (to != prv[s]) {
			upd_max(dp0[to], mx0, mxx0);
			upd_max(dp1[to], mx1, mxx1);
		}
	}
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (to != prv[s]) {
			int cur0 = (dp0[to] == mx0 ? mxx0 : mx0);
			int cur1 = (dp1[to] == mx1 ? mxx1 : mx1);
			dp_prv0[to] = get_0(cur0, cur1, cnt);
			dp_prv1[to] = get_1(cur0);
			dfs2(to);
		}
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
	dfs1(1);
	dfs2(1);
	int res = 0;
	REPN(i, 1, n) {
		res = max(res, max(ans0[i], ans1[i]));
	}
	printf("%d\n", res);
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