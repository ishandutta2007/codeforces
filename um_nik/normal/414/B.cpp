#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = (ll)(1e9 + 7);
int n, k;
ll dp[2010][2010];

ll f(int k, int n)
{
    if (dp[k][n] != -1)
        return dp[k][n];
    dp[k][n] = 0LL;
    for (int i = 1; i <= n; i++)
        dp[k][n] = (dp[k][n] + f(k - 1, n / i)) % MOD;
    return dp[k][n];
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = -1;
    for (int i = 1; i <= n; i++)
        dp[1][i] = (ll)i;
    printf("%I64d\n", f(k, n));
//  cin >> n;
    return 0;
}