#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;

int n, t;
double p, dp[MAXN][MAXN], res(0);

void init()
{
    cin >> n >> p >> t;
    for(int i(0); i <= t; ++i)
    for(int j(0); j <= n; ++j)
        dp[i][j] = 0;
    dp[0][0] = 1;
}

void solve()
{
    for(int i(0); i < t; ++i)
    {
        for(int j(0); j < n; ++j)
            dp[i + 1][j] += (1 - p) * dp[i][j], dp[i + 1][j + 1] += p * dp[i][j];
        dp[i + 1][n] += dp[i][n];
    }
    for(int i(0); i <= n; ++i)
        res += dp[t][i] * i;
}

void output()
{
    cout << setprecision(7) << fixed << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}