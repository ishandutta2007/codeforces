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
const int INF = 1e8 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 3e3 + 5;

vector<pii> g[MAXN];

int dp[MAXN][3][2];

int get_dif(int past_dp, int actual_dir, int expected_dp, int expected_dir) {
	int res = expected_dp;
	if (expected_dir != actual_dir) {
		res++;
	}
	res -= past_dp;
	if (actual_dir == 0) {
		res--;
	}
	return res;
}

void dfs(int s, int p) {
	int sum = 0;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i]._1;
		if (to == p) {
			continue;
		}
		dfs(to, s);
		sum += dp[to][0][0] + (g[s][i]._2 == 1 ? 0 : 1);
	}
	dp[s][0][0] = dp[s][1][1] = dp[s][1][0] = dp[s][2][1] = sum;
	//dp[s][2][1] = INF;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i]._1;
		if (to == p) {
			continue;
		}
		dp[s][1][1] = min(dp[s][1][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 0));

		dp[s][1][0] = min(dp[s][1][0], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 0));
		dp[s][1][0] = min(dp[s][1][0], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 1));
		dp[s][1][0] = min(dp[s][1][0], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][0], 1));
		
		dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][2][1], 0));
		dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 0));
		dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 1));
		dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][0], 1));
		REP(j, 0, SZ(g[s])) {
			int to2 = g[s][j]._1;
			if (to2 == p || to2 == to) {
				continue;
			}
			dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 0) + get_dif(dp[to2][0][0], g[s][j]._2, dp[to2][1][1], 0));
			dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 0) + get_dif(dp[to2][0][0], g[s][j]._2, dp[to2][1][1], 1));
			dp[s][2][1] = min(dp[s][2][1], sum + get_dif(dp[to][0][0], g[s][i]._2, dp[to][1][1], 0) + get_dif(dp[to2][0][0], g[s][j]._2, dp[to2][1][0], 1));
		}
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb({b, 1});
		g[b].pb({a, 0});
	}
	dfs(1, 0);
	printf("%d\n", dp[1][2][1]);
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