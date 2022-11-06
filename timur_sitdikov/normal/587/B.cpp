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
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

vector<ll> dp[MAXN], dp_sum[MAXN];

pii v[MAXN];
int lim[MAXN];

void solve(){
    ll n, l, k, ans, tmp, j1, len;
    int i, j;
    cin >> n >> l >> k;
    REP(i, 0, n){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v, v + n);
    for(i = 0; i < n; ){
        for(j = i; j < (int)n && v[j].first == v[i].first; j++);
        for(; i < j; i++){
            lim[i] = j - 1;
        }
    }
    for(i = 0; i < n; i++){
        dp[i].pb(1ll);
        dp_sum[i].pb(lim[i] + 1ll);
    }
    for(j = 1; j < k; j++){
        for(i = 0; i < n; i++){
            dp[i].pb(dp_sum[lim[i]][j - 1]);
            dp_sum[i].pb(dp[i][j]);
            if (i){
                dp_sum[i][j] = (dp_sum[i][j] + dp_sum[i - 1][j]) % MOD;
            }
        }
    }
    ans = 0ll;
    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            j1 = j + 1ll;
            if (v[i].second < (l % n)){
                len = l / n + 1ll;
            } else {
                len = l / n;
            }
            tmp = max(0ll, len - j1 + 1ll) % MOD;
            //cout << i << " " << j << " " << dp[i][j] << " " << len << " " << tmp << " " << ans << endl;
            ans = (ans + tmp * dp[i][j]) % MOD;
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