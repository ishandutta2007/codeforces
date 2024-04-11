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

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e8;
const int MAXN = 505;
const ll MOD = 1e9 + 7;

int v[MAXN];
int dp[MAXN][MAXN];

void solve(){
    int n, i, j, k, lim, fl;
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d", &v[i]);
    }
    REP(i, 0, n){
        REP(j, 0, n){
            dp[i][j] = INF;
        }
    }
    for(i = n - 1; i >= 0; i--){
        dp[i][i] = 1;
        if (i < n - 1){
            dp[i][i + 1] = 2;
            if (v[i] == v[i + 1]){
                dp[i][i + 1] = 1;
            }
        }
        for(j = i + 2; j < n; j++){
            for(k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (v[i] == v[j]){
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]); 
            }
            /*lim = (i - j ) / 2;
            fl = 0;
            for(k = 1; k <= lim; k++){
                if (v[i + k - 1] == v[j - k + 1]){
                    dp[i][j] = min(dp[i][j], dp[i + k][j - k]);
                }
            }*/
        }
    }
    printf("%d\n", dp[0][n - 1]);
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