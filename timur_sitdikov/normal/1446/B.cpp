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

const int MAXN = 5005;

int dp[MAXN][MAXN];

char s[MAXN], t[MAXN];

void solve(){
	int n, m;
	scanf("%d%d%s%s", &n, &m, &s[0], &t[0]);
	int ans = 0;
	REPN(i, 0, n) {
		REPN(j, 0, m) {
			ans = max(ans, dp[i][j]);
			if (i < n && j < m && s[i] == t[j]) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
			}
			if (i < n) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
			}
			if (j < m) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
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