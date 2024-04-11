#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int mod = 998244353;
ll dp[1005][2005][2];
int main() {
    int n, k;
    cin >> n >> k;
    dp[1][2][0] = 2;
    dp[1][1][1] = 2;
    for(int i=1;i<n;++i) {
        for(int j=1;j<=k;++j) {
            // dp[i][j][1] -> dp[i+1][j][1]
            // dp[i][j][1] -> dp[i+1][j+1][1]
            // dp[i][j][1] -> 2 * dp[i+1][j+1][0]

            // dp[i][j][0] -> dp[i+1][j+2][0]
            // dp[i][j][0] -> dp[i+1][j][0]
            // dp[i][j][0] -> 2 * dp[i+1][j][1]

            (dp[i+1][j][1] += dp[i][j][1]) %= mod;
            (dp[i+1][j+1][1] += dp[i][j][1]) %= mod;
            (dp[i+1][j+1][0] += 2 * dp[i][j][1]) %= mod;

            (dp[i+1][j+2][0] += dp[i][j][0]) %= mod;
            (dp[i+1][j][0] += dp[i][j][0]) %= mod;
            (dp[i+1][j][1] += 2 * dp[i][j][0]) %= mod;
        }
    }
    ll ans = (dp[n][k][0] + dp[n][k][1]) % mod;
    cout << ans << endl;
}