#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll dp[100][100][2];

int main()
{

    ll n, t;
    scanf("%I64d%I64d", &n, &t);

    ll k;
    n++;
    for (k = 0; k < 60; k++)
        if (((ll)1 << k) == 2 * t)
            break;

    if (k == 60)
    {
        cout << 0;
        return 0;
    }

    dp[60][0][1] = 1;
    for (int i = 59; i >= 0; i--)   
    {
        ll bit = (((ll)1 << (ll)i) & n);
        for (int cnt = 0; cnt < 59; cnt++)
        {
            if (bit == 0)
            {
                dp[i][cnt][1] += dp[i + 1][cnt][1];
                dp[i][cnt][0] += dp[i + 1][cnt][0];
                dp[i][cnt + 1][0] += dp[i + 1][cnt][0];
            }
            else
            {
                dp[i][cnt + 1][1] += dp[i + 1][cnt][1];
                dp[i][cnt + 1][0] += dp[i + 1][cnt][0];
                dp[i][cnt][0] += dp[i + 1][cnt][0] + dp[i + 1][cnt][1];
            }
        }
    }

    ll ans = dp[0][k][0] + dp[0][k][1];
    if (k == 1)
        ans--;

    printf("%I64d", ans);

    return 0;
}