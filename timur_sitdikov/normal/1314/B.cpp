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

const int MAXN = 17;

int dp[1 << MAXN][MAXN + 1][4];

int _move[4][4][4];

int good[1 << MAXN];

void add_move(int i, int j, int k, int v) {
	_move[i][j][k] = _move[j][i][k] = v;
}

void solve(){
	REP(i, 0, 4) {
		REP(j, 0, 4) {
			REP(k, 0, 4) {
				_move[i][j][k] = -INF;
			}
		}
	}
	
	add_move(0, 0, 0, 0);
	add_move(0, 1, 1, 1);
	add_move(0, 1, 2, 2);
	add_move(0, 2, 2, 2);
	add_move(0, 3, 3, 3);
	add_move(1, 1, 3, 2);
	add_move(1, 2, 3, 3);
	add_move(1, 3, 3, 3);
	add_move(2, 2, 2, 2);
	add_move(2, 3, 3, 3);
	add_move(3, 3, 3, 3);
	
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int a;
		scanf("%d", &a);
		good[a - 1] = 1;
	}
	REP(i, 0, 1 << n) {
		REPN(j, 0, n) {
			REP(k, 0, 4) {
				dp[i][j][k] = -INF;
			}
		}
	}
	for(int i = 0; i < (1 << n); i += 2) {
		int a = good[i] + good[i + 1];
		if (a == 0) {
			dp[i][1][0] = 0;
		} else if (a == 1) {
			dp[i][1][1] = 1;
			dp[i][1][2] = 1;
		} else {
			dp[i][1][3] = 1;
		}
	}
	
	REP(l, 1, n) {
		for(int s = 0; s < (1 << n); s += (1 << (l + 1))) {
			REP(i, 0, 4) {
				int a = dp[s][l][i];
				REP(j, 0, 4) {
					int b = dp[s + (1 << l)][l][j];
					REP(k, 0, 4) {
						int c = _move[i][j][k];
						if (a >= 0 && b >= 0 && c >= 0) {
							//printf("%d %d %d %d %d %d %d %d %d %d\n", l, s, i, j, k, a, b, c, dp[s][l + 1][k], a + b + c);
							dp[s][l + 1][k] = max(dp[s][l + 1][k], a + b + c);
						}
					}
				}
			}
		}
	}
	int ans = -INF;
	REP(i, 0, 4) {
		int a = dp[0][n][i];
		int c = 0;
		if (i) {
			c = 1;
		}
		ans = max(ans, a + c);
	}
	/*REP(i, 0, 4) {
		int a = dp[0][n - 1][i];
		REP(j, 0, 4) {
			int b = dp[1 << (n - 1)][n - 1][j];
			int c = 0;
			if (i || j) {
				c = 1;
			}
			ans = max(ans, a + b + c);
		}
	}*/
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