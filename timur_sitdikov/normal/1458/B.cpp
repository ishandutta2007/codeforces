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

const int MAXN = 105, MAXW = 20005;

int a[MAXN], b[MAXN];

int dp[2][MAXN][MAXW];

int ans[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	int sum_a = 0;
	REPN(i, 1, n) {
		scanf("%d%d", &b[i], &a[i]);
		sum_a += a[i];
	}
	REP(i, 0, 2) {
		REPN(j, 0, n) {
			REP(k, 0, MAXW) {
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][0][0] = 0;
	REP(i, 0, n) {
		int ind = (i & 1);
		REPN(j, 0, i + 1) {
			REP(k, 0, MAXW) {
				dp[ind ^ 1][j][k] = max(dp[ind ^ 1][j][k], dp[ind][j][k]);
				if (j && k >= b[i + 1] && dp[ind][j - 1][k - b[i + 1]] != -1) {
					dp[ind ^ 1][j][k] = max(dp[ind ^ 1][j][k], dp[ind][j - 1][k - b[i + 1]] + a[i + 1]);
				}
			}
		}
	}
	REPN(i, 1, n) {
		REP(j, 0, MAXW) {
			if (dp[n & 1][i][j] != -1) {
				ans[i] = max(ans[i], min(2 * j, sum_a + dp[n & 1][i][j]));
			}
		}
	}
	REPN(i, 1, n) {
		printf("%.12lf ", ans[i] / 2.);
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