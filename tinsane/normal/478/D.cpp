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
const int MAXN = 2e5 + 10;

int g, r, pt(0), nr, cnt(0);
long long dp[2][MAXN], ans(0);

void init()
{
    cin >> g >> r;
    for(int i(0); i < g; ++i)
        dp[pt][i] = 0;
    dp[pt][g] = 1;
}

void solve()
{
    for(int h(1); 1; ++h, pt = !pt)
    {
        int pre = h * (h - 1) / 2;
        cnt = 0;
        for(int i(0); i <= g; ++i)
                dp[!pt][i] = 0;
        for(int i(0); i <= g; ++i)
        if(dp[pt][i])
        {
            nr = r - pre + (g - i);
            if(nr >= h)
                dp[!pt][i] = dp[pt][i], ++cnt;
            if(i >= h)
                dp[!pt][i - h] = (dp[!pt][i - h] + dp[pt][i]) % MODUL, ++cnt;
        }
        if(!cnt)
        {
            for(int i(0); i <= g; ++i)
                ans += dp[pt][i];
            ans %= MODUL;
            return;
        }
    }
}

void output()
{
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}