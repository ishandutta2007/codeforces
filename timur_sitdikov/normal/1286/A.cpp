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

const int MAXN = 105;

int dp[MAXN][MAXN][MAXN][2];

int lim[2];
int p[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%d", &p[i]);
		if (p[i]) {
			lim[p[i] & 1]++;
		}
	}
	lim[0] = n / 2 - lim[0];
	lim[1] = (n + 1) / 2 - lim[1];
	REPN(i, 1, n) {
		REPN(j, 0, lim[0]) {
			REPN(k, 0, lim[1]) {
				dp[i][j][k][0] = dp[i][j][k][1] = INF;
			}
		}
	}
	REPN(i, 1, n) {
		REPN(j, 0, lim[0]) {
			REPN(k, 0, lim[1]) {
				if (p[i]) {
					dp[i][j][k][p[i] & 1] = min(dp[i - 1][j][k][p[i] & 1], dp[i - 1][j][k][(p[i] & 1) ^ 1] + 1);
				} else {
					if (j) {
						dp[i][j][k][0] = min(dp[i - 1][j - 1][k][0], dp[i - 1][j - 1][k][1] + 1);
					}
					if (k) {
						dp[i][j][k][1] = min(dp[i - 1][j][k - 1][0] + 1, dp[i - 1][j][k - 1][1]);
					}
				}
			}
		}
	}
	printf("%d\n", min(dp[n][lim[0]][lim[1]][0], dp[n][lim[0]][lim[1]][1]));
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