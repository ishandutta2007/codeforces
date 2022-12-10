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
const double eps = 1e-7;
const int MAXN = 1.3e6 + 10;

int gcd(int a, int b)
{
    return (a % b ? gcd(b, a % b) : b);
}

long long p, q, g, dp[MAXN], dp2[MAXN], ans(1);
bool mas[MAXN];

bool isp(long long t)
{
    string s = to_string(t);
    bool f(1);
    int i(s.size() / 2 - 1 + (s.size() & 1)), j(s.size() / 2);
    for(; i >= 0; --i, ++j)
        f &= s[i] == s[j];
    return f;
}

void init()
{
    cin >> p >> q;
    g = gcd(p, q);
    p /= g, q /= g;
    dp[0] = dp[1] = 0;
    dp2[0] = 0;
    dp2[1] = 1;
    memset(mas, 0, MAXN);
}

void solve()
{
    for(int i(2); i < MAXN; ++i)
    {
        dp2[i] = dp2[i - 1];
        if(isp(i))
            ++dp2[i];
        dp[i] = dp[i - 1];
        if(!mas[i])
        {
            for(int j(2); j * i < MAXN; ++j)
                mas[i * j] = 1;
            ++dp[i];
        }
        if(dp[i] * q <= dp2[i] * p)
            ans = i;
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