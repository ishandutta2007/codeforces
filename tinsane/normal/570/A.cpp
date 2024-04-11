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
const int MAXN = 1e3 + 10;

int n, m, cnt[101], cnt2[101], ans(0), ma(0);

void init()
{
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cnt[i] = 0;
    for(int i(0); i < m; ++i)
    {
        ma = 0;
        for(int j(0); j < n; ++j)
        {
            cin >> cnt2[j];
            if(cnt2[j] > cnt2[ma])
                ma = j;
        }
        ++cnt[ma];
    }
    for(int i(1); i < n; ++i)
    if(cnt[i] > cnt[ans])
        ans = i;
}

void solve()
{
}

void output()
{
    cout << ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}