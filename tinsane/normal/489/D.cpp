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
const int MAXN = 3e3 + 10;

int n, m, a ,b;
long long ans(0), cnt[MAXN];
vector<int> mas[MAXN];

void init()
{
    cin >> n >> m;
    for(int i(0); i < m; ++i)
        cin >> a >> b, mas[a].push_back(b);
}

void solve()
{
    for(int i(1); i <= n; ++i)
    {
        for(int j(1); j <= n; ++j)
            cnt[j] = 0;
        for(int j(0); j < mas[i].size(); ++j)
            for(int k(0); k < mas[mas[i][j]].size(); ++k)
                ++cnt[mas[mas[i][j]][k]];
        for(int j(1); j <= n; ++j)
            ans += cnt[j] * (cnt[j] - 1) / 2;
        ans -= cnt[i] * (cnt[i] - 1) / 2;
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