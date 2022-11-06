#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e3 + 5;

int dp[MAXN][MAXN], v[MAXN];
int dpl[MAXN], dpr[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n){
		scanf("%d", &v[i]);
		dpl[i] = dpl[i - 1] + (v[i] == 1 ? 1 : 0);
	}
	for(int i = n; i > 0; i--){
		dpr[i] = dpr[i + 1] + (v[i] == 2 ? 1 : 0);
	}
	for(int i = n; i >= 1; i--){
		dp[i][i] = 1;
		REPN(j, i + 1, n){
			dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
			if (v[i] == 2){
				dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
			}
			if (v[j] == 1){
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
			}
		}
	}
	int ans = 0;
	REPN(i, 1, n){
		REPN(j, i, n){
			ans = max(ans, dpl[i - 1] + dpr[j + 1] + dp[i][j]);
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