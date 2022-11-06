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

const int MAXN = 5e3 + 5;

int dp[MAXN][MAXN], dp_mn[MAXN][MAXN];

int h[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%d", &h[i]);
	}
	REPN(i, 1, n) {
		REPN(j, 1, n + 1) {
			dp[i][j] = dp_mn[i][j] = INF;
		}
	}
	REPN(i, 1, n) {
		int r = i;
		ll h_cur = 0, h_l = 0;
		for(int j = i; j >= 1; j--) {
			h_cur += h[j];
			if (r >= j) {
				r = j;
				h_l = 0;
			} else {
				h_l -= h[j];
			}
			for(; r > 0 && h_l <= h_cur; r--) {
				h_l += h[r - 1];
			}
			h_l -= h[r];
			r++;
			dp[i][j] = min(dp[i][j], dp_mn[j - 1][r] + i - j);
			dp_mn[i][j] = min(dp_mn[i][j + 1], dp[i][j]);
			
			//printf("%d %d: %d, %d\n", i, j, dp[i][j], dp_mn[i][j]);
		}
	}
	printf("%d\n", dp_mn[n][1]);
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