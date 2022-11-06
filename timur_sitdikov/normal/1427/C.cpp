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

const int MAXN = 3e5 + 5, LIM = 3000;

int dp[MAXN];

int x[MAXN], y[MAXN], t[MAXN];

void solve(){
	int r, n;
	scanf("%d%d", &r, &n);
	REPN(i, 1, n) {
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
	}
	x[0] = y[0] = 1;
	REP(i, 0, n) {
		if (i > 0 && dp[i] == 0) {
			continue;
		}
		REPN(j, 1, LIM) {
			if (i + j > n) {
				break;
			} else if (abs(x[i + j] - x[i]) + abs(y[i + j] - y[i]) <= t[i + j] - t[i]) {
				dp[i + j] = max(dp[i + j], dp[i] + 1);
			}
		}
	}
	int ans = 0;
	REPN(i, 1, n) {
		ans = max(ans, dp[i]);
		//printf("%d: %d\n", i, dp[i]);
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