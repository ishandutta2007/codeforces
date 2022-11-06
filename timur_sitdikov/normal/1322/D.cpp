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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 5e3 + 55;
const int MAXLOG = 14;

int dp[MAXN][MAXN];
int eval[MAXN][MAXN];
int dp_max[MAXN];
int dp_new[MAXN];

int level[MAXN], cost[MAXN], gain[MAXN];

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REPN(i, 1, n) {
		scanf("%d", &level[i]);
	}
	REPN(i, 1, n) {
		scanf("%d", &cost[i]);
	}
	REPN(i, 1, n + m) {
		scanf("%d", &gain[i]);
	}
	
	for(int i = n + m; i >= 1; i--) {
		REPN(j, 1, n) {
			eval[i][j] = eval[i + 1][j / 2] + gain[i + 1] * (j / 2);
		}
	}
	REPN(i, 1, n + m) {
		REPN(j, 1, n) {
			dp[i][j] = -INF;
		}
		dp_max[i] = -INF;
	}
	dp_max[0] = -INF;
	
	for(int i = n; i >= 1; i--) {
		int l = level[i];
		// Init
		REP(j, 0, n) {
			dp_new[j + 1] = -INF;
		}
		// Append
		REP(j, 0, n) {
			if (dp[l][j] != -INF) {
				dp_new[j + 1] = dp[l][j] + gain[l] - cost[i];
			}
		}
		// Eval all from prev
		if (l - MAXLOG >= 1 && dp_max[l - MAXLOG] != -INF) {
			dp_new[1] = max(dp_new[1], dp_max[l - MAXLOG] + gain[l] - cost[i]);
		}
		// Eval partial from prev 
		for(int k = max(1, l - MAXLOG); k < l; k++) {
			int mn = 1 << (l - k);
			REP(j, 0, mn) {
				if (dp[k][j] != -INF) {
					dp_new[1] = max(dp_new[1], dp[k][j] + eval[k][j]  + gain[l] - cost[i]);
				}
			}
			REP(j, mn, n){
				if (dp[k][j] != -INF) {
					int offset = (j >> (l - k));
					int ev = eval[k][j] - eval[l][offset];
					dp_new[1 + offset] = max(dp_new[1 + offset], dp[k][j] + ev + gain[l] - cost[i]);
				}
			}
		}
		
		REPN(j, 1, n) {
			dp[l][j] = max(dp[l][j], dp_new[j]);
			if (dp[l][j] != -INF) {
				dp_max[l] = max(dp_max[l], dp[l][j] + eval[l][j]);
			}
		}
		
		REPN(k, l + 1, n + m) {
			dp_max[k] = max(dp_max[k], dp_max[k - 1]);
		}
		
		/*printf("%d: %d\n", i, l);
		REPN(i0, 1, n) {
			REPN(j0, 1, n) {
				printf("%d ", dp[i0][j0]);
			}
			putchar('\n');
		}
		putchar('\n');*/
	}
	
	int ans = 0;
	REPN(i, 1, n + m) {
		REPN(j, 1, n) {
			if (dp[i][j] != -INF) {
				ans = max(ans, dp[i][j] + eval[i][j]);
			}
		}
	}
	printf("%d\n", ans);
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