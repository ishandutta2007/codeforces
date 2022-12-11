#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;
                 
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
     a += b;
     if (a < mod)
        return a;
    return a - mod;
}

int dp[200][200];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
                
    dp[0][0] = 1;
    int n, k, d;
    cin >> n >> k >> d;
    for (int sum = 0; sum <= n; sum++)
        for (int mx = 0; mx <= n; mx++)
        {
            if (dp[sum][mx] == 0)
                continue;
            for (int w = 1; w <= k; w++)
            {
                dp[sum + w][max(mx, w)] = add(dp[sum + w][max(mx, w)], dp[sum][mx]);
            }   
        }
    int ans = 0;
    for (int i = d; i <= n; i++)
        ans = add(ans, dp[n][i]);
    cout << ans;;

    return 0;
}