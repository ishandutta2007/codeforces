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
const ll INF = 1e12;
const int MAXN = 3e5 + 5;
const int MAXV = 5e3 + 5;
const ll MOD = 1e9 + 7;

ll dp[MAXV][MAXV];

int a[MAXN];

void solve(){
    int i, j, n, k, limj, ind, ind1, ind2, len;
    ll tmp, ans;
    scanf("%d%d", &n, &k);
    limj = n % k;
    len = n / k;
    REP(i, 1, n + 1){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    a[0] = a[1];
    REP(i, 0, k + 1){
        REP(j, 0, limj + 1){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0ll;
    REP(i, 1, k + 1){
        REP(j, 0, limj + 1){
            ind = j * (len + 1) + (i - j) * len;
            ind1 = ind - len;
            ind2 = ind - len - 1;
            if (ind1 >= 0){
                tmp = dp[i - 1][j] + a[ind1 + 1] - a[ind1];
                dp[i][j] = max(dp[i][j], tmp);
            }
            if (j && ind2 >= 0){
                tmp = dp[i - 1][j - 1] + a[ind2 + 1] - a[ind2];
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
    }
    ans = a[n] - a[1] - dp[k][limj];
    cout << ans << endl;
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