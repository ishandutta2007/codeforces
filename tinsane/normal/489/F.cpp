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

long long ans(0), f[MAXN][MAXN];
int n, m, mod, cnt[MAXN], x(0), y(0);
string s[MAXN];

void init()
{
    cin >> n >> m >> mod;
    for(int i(0); i < m; ++i)
        cin >> s[i];
    for(int i(0); i < n; ++i)
        cnt[i] = 0;
    f[0][0] = 1;
    f[0][1] = 0;
}

void solve()
{
    for(int i(0); i < m; ++i)
    {
        for(int j(0); j < n; ++j)
        if(s[i][j] == '1')
            ++cnt[j];
    }
    for(int i(0); i < n; ++i)
    if(cnt[i] == 1)
        ++x;
    else if(cnt[i] == 0)
        ++y;
    for(long long i(2); i <= n * 2; ++i)
    {
        f[i][0] = i * (i - 1) / 2 % mod * f[i - 2][0] % mod;
        if(i & 1)
            f[i - 1][1] = ((i - 1) * (i - 2) / 2 % mod * f[i - 3][1] + (i - 1) % mod * f[i - 1][0]) % mod;
        for(long long j(2); j < i; ++j)
        if(!((i - j) & 1))
            f[i - j][j] = ((i - j) * (i - j - 1) / 2 % mod * f[i - j - 2][j] + 
            (i - j) * j % mod * f[i - j][j - 1] + 
            j * (j - 1) / 2 % mod * f[i - j + 2][j - 2]) % mod;
        f[0][i] = i * (i - 1) / 2 % mod * f[2][i - 2] % mod;
    }
    ans = f[x][y];
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