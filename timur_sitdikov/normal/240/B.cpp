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

const int MAXN = 202, MAXK = 40404;

int dp[MAXN][MAXK][2];
int h[MAXN], sum[MAXN];

void solve(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	REP(i, 0, n) {
		scanf("%d", &h[i]);
		sum[i] = h[i];
		if (i) {
			sum[i] += sum[i - 1];
		}
	}
	REP(i, 0, n) {
		REP(j, 0, MAXK) {
			dp[i][j][0] = dp[i][j][1] = INF;
		}
	}
	if (h[0] <= a) {
		dp[0][h[0]][0] = 0;
	}
	if (h[0] <= b) {
		dp[0][0][1] = 0;
	}
	REP(i, 0, n - 1) {
		REP(j, 0, MAXK) {
			int a1 = j;
			int b1 = sum[i] - j;
			if (dp[i][j][0] < INF) {
				if (a1 + h[i + 1] <= a && b1 <= b) {
					dp[i + 1][a1 + h[i + 1]][0] = min(dp[i + 1][a1 + h[i + 1]][0], dp[i][j][0]);
				}
				if (a1 <= a && b1 + h[i + 1] <= b) {
					dp[i + 1][a1][1] = min(dp[i + 1][a1][1], dp[i][j][0] + min(h[i], h[i + 1]));
				}
			}
			if (dp[i][j][1] < INF) {
				if (a1 + h[i + 1] <= a && b1 <= b) {
					dp[i + 1][a1 + h[i + 1]][0] = min(dp[i + 1][a1 + h[i + 1]][0], dp[i][j][1] + min(h[i], h[i + 1]));
				}
				if (a1 <= a && b1 + h[i + 1] <= b) {
					dp[i + 1][a1][1] = min(dp[i + 1][a1][1], dp[i][j][1]);
				}
			}
		}
	}
	/*REP(i, 0, n) {
		REP(j, 0, 100) {
			REP(k, 0, 2) {
				if (dp[i][j][k] < INF) {
					printf("%d %d %d: %d\n", i, j, k, dp[i][j][k]);
				}
			}
		}
	}*/
	int ans = INF;
	REP(i, 0, MAXK) {
		ans = min(ans, dp[n - 1][i][0]);
		ans = min(ans, dp[n - 1][i][1]);
	}
	if (ans == INF) {
		ans = -1;
	}
	printf("%d\n", ans);
}

int main(){
freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}