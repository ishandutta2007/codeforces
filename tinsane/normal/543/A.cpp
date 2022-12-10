#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e5 + 10;
    int n, m, b, mod, progs[502];
    long long dp[502][502], ans(0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> b >> mod;
    for(int i(0); i < n; ++i)
        cin >> progs[i];
    for(int i(0); i <= m; ++i)
    for(int j(0); j <= n; ++j)
        dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i(0); i < n; ++i)
    {
        for(int j(0); j <= m - 1; ++j)
        {
            for(int k(0); k <= b - progs[i]; ++k)
                dp[j][k] %= mod, dp[j + 1][k + progs[i]] += dp[j][k];
            if(b >= progs[i] - 1)
                for(int k(b - progs[i] + 1); k <= b; ++k)
                    dp[j][k] %= mod;
        }
    }
    for(int i(0); i <= b; ++i)
        ans += dp[m][i];
    cout << ans % mod;
    return 0;
}