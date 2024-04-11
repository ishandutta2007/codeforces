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
const int MAXN = 3e5 + 10;
const int MAXK = 5e3 + 10;

int n, k, mas[MAXN], sum, dp[MAXK][MAXK], per, cnt;

void init()
{
    cin >> n >> k;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    sort(mas, mas + n);
    sum = mas[n - 1] - mas[0];
    per = (n - 1) / k + 1;
    cnt = n - (per - 1) * k;
    dp[k - 1][cnt] = dp[0][0] = sum;
}

void solve()
{
    for(int i(1); i < k; ++i)
    {
        dp[i][0] = dp[i - 1][0] - (mas[i * (per - 1)] - mas[i * (per - 1) - 1]);
        if(cnt < i)
        {
            for(int j(1); j <= cnt; ++j)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) - (mas[i * (per - 1) + j] - mas[i * (per - 1) + j - 1]);
        }
        else
        {
            for(int j(1); j < i; ++j)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) - (mas[i * (per - 1) + j] - mas[i * (per - 1) + j - 1]);
            dp[i][i] = dp[i - 1][i - 1] - (mas[i * per] - mas[i * per - 1]);
        }
    }
}

void output()
{
    cout << min(dp[k - 1][cnt], dp[k - 1][cnt - 1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}