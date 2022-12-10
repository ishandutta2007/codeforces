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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = (1 << 18) + 10;

int m, n, k, a, b, c;
long long ans(0), mas[20], dp[(1 << 18) + 10][18], inc[20][20];

void init()
{
    cin >> n >> m >> k;
    for(int i(0); i < n; ++i)
        cin >> mas[i], ++mas[i];
    for(int i(0); i < n; ++i)
    for(int j(0); j < n; ++j)
        inc[i][j] = 0;
    for(int i(0); i < k; ++i)
        cin >> a >> b >> c, --a, --b, inc[a][b] = c;
}

void solve()
{
    for(int i(0); i < MAXN; ++i)
    for(int j(0); j < n; ++j)
        dp[i][j] = 0;
    for(int i(0); i < n; ++i)
        dp[1 << i][i] = mas[i];
    for(int i(0); i < MAXN; ++i)
    for(int j(0); j < n; ++j)
    if(dp[i][j])
    {
        for(int k(0); k < n; ++k)
        if(!(i & (1 << k)))
            dp[i | (1 << k)][k] = max(dp[i][j] + mas[k] + inc[j][k], dp[i | (1 << k)][k]);
        int cnt = 0;
        for(int k(0); k < n; ++k)
        if(i & (1 << k))
            ++cnt;
        if(cnt == m)
            ans = max(ans, dp[i][j]);
    }
}

void output()
{
    cout << ans - m;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}