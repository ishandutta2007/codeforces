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
const int INF = 1e9;
const int MAXN = 18;
const ll MOD = 1e9 + 7;

ll dp[1 << MAXN][MAXN];

int g[MAXN][MAXN], v[MAXN];

void solve(){
    int n, m, i, j, k, mask, a, b, c, cnt;
    cin >> n >> m >> k;
    REP(i, 0, n){
        cin >> v[i];
    }
    REP(i, 0, k){
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = c;
    }
    for(mask = 0; mask < (1 << n); mask++){
        for(i = 0; i < n; i++){
            dp[mask][i] = -1ll;
        }
    }
    for(i = 0; i < n; i++){
        dp[1 << i][i] = v[i];
    }
    ll ans = 0ll;
    for(mask = 0; mask < (1 << n); mask++){
        cnt = 0;
        for(i = 0; i < n; i++){
            if (mask & (1 << i)){
                cnt++;
            }
        }
        for(i = 0; i < n; i++){
            if (dp[mask][i] != -1){
                if (cnt == m){
                    ans = max(ans, dp[mask][i]);
                }
                for(j = 0; j < n; j++){
                    if (!(mask & (1 << j))){
                        dp[mask | (1 << j)][j] = max(dp[mask | (1 << j)][j], dp[mask][i] + g[i][j] + v[j]);
                    }
                }
            }
        }
    }
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