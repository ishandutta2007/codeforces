#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const ll N = 1e5 + 5, MOD = 998244353;

ll n, a[N];
ll dp[N][205][2];

int main()
{
    cin>>n;
    for (ll i = 1; i <= n; i++)
        cin>>a[i];
    dp[0][1][0] = 1;
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= 200; j++)
            dp[i][j][0] = (dp[i][j - 1][0] + dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1]) % MOD;
        for (ll j = 200; j >= 1; j--)
            dp[i][j][1] = (dp[i][j + 1][1] - dp[i - 1][j + 1][0] + dp[i - 1][j][0] + dp[i - 1][j][1] + MOD) % MOD;
        if (a[i] != -1)
            for (ll j = 1; j <= 200; j++)
                if (j != a[i])
                    dp[i][j][0] = 0, dp[i][j][1] = 0;
    }
    ll ans = 0;
    for (ll i = 1; i <= 200; i++)
        ans = (ans + dp[n][i][1]) % MOD;
    cout<<ans<<endl;
    return 0;
}