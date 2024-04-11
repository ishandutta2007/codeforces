#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][105];
ll dp2[MAXN][105];
ll ps[MAXN][105];
ll sps[MAXN];
ll a[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, l;
    scanf("%lld%lld%lld\n", &n, &k, &l);
    if(l == 1) return printf("%d\n", 0), 0;

    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= k; j++){
        if(a[i] == -1 or a[i] == j){
          dp2[i][j] = dp2[i - 1][j] + 1;
        } else {
          dp2[i][j] = 0;
        }
      }
    }

    if(a[1] == -1){
      for(int i = 1; i <= k; i++){
        dp[1][i] = 1;
        ps[1][i] = 1;
      }
      sps[1] = k;
    } else {
      dp[1][a[1]] = 1;
      ps[1][a[1]] = 1;
      sps[1] = 1;
    }

    ll mxl;

    for(int i = 2; i <= n; i++){
      sps[i] = sps[i - 1];
      for(int j = 1; j <= k; j++) ps[i][j] = ps[i - 1][j];

      for(int j = 1; j <= k; j++){
        mxl = min(l - 1, dp2[i][j]);
        if(mxl == 0) {
          dp[i][j] = 0;
          continue;
        }
        if(i >= 1 + mxl) dp[i][j] = (sps[i - 1] - sps[i - 1 - mxl]) - (ps[i - 1][j] - ps[i - 1 - mxl][j]);
        else dp[i][j] = sps[i - 1] - ps[i - 1][j] + 1;
        dp[i][j] %= MOD;

        ps[i][j] += dp[i][j]; ps[i][j] %= MOD;
        sps[i] += dp[i][j]; sps[i] %= MOD;

      }
    }
    ll ans = 0;
    for(int j = 1; j <= k; j++) {
      ans += dp[n][j];
      ans %= MOD;
    }
    ans += MOD; ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}