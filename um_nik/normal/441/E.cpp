#include <iostream>
using namespace std;

const double eps = 1e-12;
const int MOD = 256;
double dp[300][300][2][2];
double p;
int x, n, q;

int main()
{
    scanf("%d%d%d", &x, &n, &q);
    p = (double)q / 100.;
    int y = x >> 8;
    x %= MOD;
    int z = 0;
    q = y & 1;
    if (y > 0)
    {
        while ((y & 1) == q)
        {
            z++;
            y /= 2;
        }
    }
    dp[x][z][q][0] = 1.;
    while (n--)
    {
        for (int mask = 0; mask < MOD; mask++)
            for (int k = 0; k < 300; k++)
                for (int q = 0; q < 2; q++)
                {
                    if (dp[mask][k][q][0] < eps)
                        continue;
                    int x = mask * 2;
                    int y = x / MOD;
                    x %= MOD;
                    if (y == q)
                        dp[x][k + 1][q][1] += dp[mask][k][q][0] * p;
                    else
                        dp[x][1][y][1] += dp[mask][k][q][0] * p;
                    if (mask == MOD - 1)
                    {
                        if (q == 0)
                            dp[0][1][1][1] += dp[mask][k][q][0] * (1. - p);
                        else
                            dp[0][k][0][1] += dp[mask][k][q][0] * (1. - p);
                    }
                    else
                    {
                        dp[mask + 1][k][q][1] += dp[mask][k][q][0] * (1. - p);
                    }
                }
        for (int mask = 0; mask < MOD; mask++)
            for (int k = 0; k < 300; k++)
                for (int q = 0; q < 2; q++)
                {
                    dp[mask][k][q][0] = dp[mask][k][q][1];
                    dp[mask][k][q][1] = 0.;
                }
    }
    double ans = 0.;
    for (int i = 1; i < 300; i++)
        ans += (double)i * dp[0][i][0][0];
    for (int mask = 0; mask < MOD; mask++)
    {
        int x = 0;
        while (x < 8 && (mask & (1 << x)) == 0) x++;
        for (int k = 0; k < 300; k++)
            for (int q = 0; q < 2; q++)
                ans += dp[mask][k][q][0] * (double)x;
    }
    printf("%.10lf\n", ans);
    return 0;
}