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
const int MAXN = 1e5 + 10;

int n, p, ans(0), cnt(0), t(0), f, l;
string s;
bool ye[MAXN];

void init()
{
    cin >> n >> p >> s;
    for(int i(0); i < n; ++i)
        ye[i] = 0;
    for(int i(0); i < n / 2; ++i)
    if(s[i] != s[n - 1 - i])
        ye[i] = ye[n - 1 - i] = 1, ++cnt;
    --p;
    if(p >= (n + 1) / 2)
        p = n - 1 - p;
}

void solve()
{
    if(cnt)
    {
        for(int i(0); i < n; ++i)
        if(ye[i])
        {
            f = i;
            break;
        }
        for(int i(n / 2 - 1); i >= 0; --i)
        if(ye[i])
        {
            l = i;
            break;
        }
        if(p >= f && p <= l)
            ans = min(l - f + p - f, l - f + l - p);
        else if(p < f)
            ans = l - p;
        else 
            ans = p - f;
    }

    for(int i(0); i < n / 2; ++i)
        ans += min(abs((int)s[i] - (int)s[n - 1 - i]), 26 - abs((int)s[i] - (int)s[n - 1 - i]));
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