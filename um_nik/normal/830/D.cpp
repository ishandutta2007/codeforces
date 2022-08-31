#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

const int N = 410;
ll C[N][N];
ll dp[N][N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    for (int i = 0; i < N; i++)
        C[i][0] = C[i][i] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < i; j++)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

    dp[1][0] = 1;
    for (int n = 2; n < N; n++) {
        
        dp[n][0] = add(dp[n][0], mult(2, dp[n - 1][0]));
        dp[n][0] = add(dp[n][0], mult(2, mult(add(1, dp[n - 1][0]), add(1, dp[n - 1][0]))));
        dp[n][0] = sub(dp[n][0], 1);
        dp[n][0] = add(dp[n][0], mult(2, dp[n - 1][1]));

        for (int k = 1; n + k < N; k++) {

            for (int i = 0; i <= k + 1; i++) {
                ll val = C[k + 1][i];
                if (i > 0)
                    val = mult(val, dp[n - 1][i - 1]);
                if (i < k + 1)
                    val = mult(val, dp[n - 1][k - i]);
                dp[n][k] = add(dp[n][k], val);
            }

            ll res = 0;
            for (int m = k; m <= k + 2; m++) {
                for (int i = 0; i <= m; i++) {
                    ll val = C[m][i];
                    if (m == k + 1)
                        val = mult(val, 2);
                    if (i > 0)
                        val = mult(val, dp[n - 1][i - 1]);
                    if (i < m)
                        val = mult(val, dp[n - 1][m - 1 - i]);
                    res = add(res, val);
                }
            }
            dp[n][k] = add(dp[n][k], mult(res, k + 1));

        }
    }


    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[n][0]);

    return 0;
}