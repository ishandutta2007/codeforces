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
const int MAXN = 1e5 + 10;

int n, mas[MAXN], dp, ans(1);

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
}

void solve()
{
    dp = 1;
    for(int i(1); i < n; ++i)
    {
        if(mas[i] >= mas[i - 1])
        {
            ++dp;
            ans = max(ans, dp);
        }
        else
            dp = 1;
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