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

int n, anc[MAXN], ind;
double dp[MAXN], ans, mi(0), ma(MAXINT), md, b[MAXN], x[MAXN], l;
bool used[MAXN];

void init()
{
    cin >> n >> l;
    for(int i(1); i <= n; ++i)
        cin >> x[i] >> b[i];
    dp[0] = 0;
}

void solve()
{
    while(ma - mi > eps)
    {
        ans = (mi + ma) / 2;
        for(int i(1); i <= n; ++i)
        {
            md = MAXLL;
            for(int j(0); j < i; ++j)
                md = min(md, dp[j] + sqrt(abs(l - x[i] + x[j])));
            dp[i] = md - b[i] * ans;
        }
        if(dp[n] > 0)
            mi = ans;
        else
            ma = ans;
    }
    ans = ma;
    for(int i(1); i <= n; ++i)
    {
        md = MAXLL;
        ind = -1;
        for(int j(0); j < i; ++j)
        if(md > dp[j] + sqrt(abs(l - x[i] + x[j])))
        {
            md = dp[j] + sqrt(abs(l - x[i] + x[j]));
            ind = j;
        }
        dp[i] = md - b[i] * ans;
        anc[i] = ind;
    }
}

void output()
{
    stack<int> ans;
    for(int i(n); i; i = anc[i])
        ans.push(i);
    for(; ans.size(); cout << ans.top() << ' ', ans.pop());
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}