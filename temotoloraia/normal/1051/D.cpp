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
using namespace std;
const ll N = 2005, MOD = 998244353;
ll n, K;
ll dp[N][N][2];
int main()
{
    //freopen ("in.in", "r", stdin);
    //freopen ("out.out", "w", stdout);
    cin>>n>>K;
    dp[1][1][0] = 2;
    dp[1][2][1] = 2;
    for (int i = 2; i <= n; i++){
        for (int k = 1; k <= i * 2 - 2; k++){
            dp[i][k][0] += dp[i - 1][k][0];
            dp[i][k][1] += dp[i - 1][k][1];
            dp[i][k + 1][0] += dp[i - 1][k][0];
            dp[i][k + 1][1] += 2 * dp[i - 1][k][0];
            dp[i][k + 2][1] += dp[i - 1][k][1];
            dp[i][k][0] += 2 * dp[i - 1][k][1];
        }
        for (int k = 1; k <= i * 2; k++)
            for (int l = 0; l < 2; l++)
                dp[i][k][l] %= MOD;
    }
    cout<<(dp[n][K][0] + dp[n][K][1]) % MOD<<endl;
    return 0;
}