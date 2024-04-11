#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = (int)1e5 + 100;

typedef long double ld;

ld p[N];

ld dp[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);   
    p[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
                    

    if (n == 1)
    {
        cout << p[1];
        return 0;
    }

    dp[1] = p[1];

    ld sumCoef = (1 - p[2]) + p[2] * (1 - p[1]) + p[2] * p[1] * (1 - p[0]);
    ld magic = 1 * p[2] * (1 - p[1]) + 2 * p[2] * p[1] * (1 - p[0]);
    ld sumDp = (1 - p[2]) * dp[1] + p[2] * (1 - p[1]) * dp[0];
    ld sumSqr = 1 * p[2] * (1 - p[1]) + 4 * p[2] * p[1] * (1 - p[0]);

    for (int i = 2; i <= n; i++)
    {                                                        
        dp[i] = sumDp + sumSqr;                
        sumDp *= p[i + 1];
        sumDp += dp[i] * (1 - p[i + 1]);

        sumSqr = sumSqr + 2 * magic + sumCoef;
        sumSqr *= p[i + 1];
        magic += sumCoef;
        magic *= p[i + 1];
        sumCoef = (sumCoef * p[i + 1]) + (1 - p[i + 1]); 
    }               
                               
    cout << fixed << setprecision(6) << dp[n];
    return 0;
}