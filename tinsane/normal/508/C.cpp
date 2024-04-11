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

int m, t, r, mas[300], ti[1000], used[1000], cnt(0);

void init()
{
    cin >> m >> t >> r;
    for(int i(0); i < m; ++i)
        cin >> mas[i], mas[i] += 301;
    for(int i(0); i < 1000; ++i)
        ti[i] = used[i] = 0;
    sort(mas, mas + m);
}

void solve()
{
    for(int i(0), s(mas[0]); i < m; s = mas[++i])
    if(ti[s] < r)
    {
        for(int j(1); j <= t && ti[s] < r; ++j)
        if(!used[s - j])
        {
            ++cnt;
            used[s - j] = 1;
            for(int k(1); k <= t; ++k)
                ++ti[s - j + k];
        }
    }
    for(int i(0); i < m; ++i)
    if(ti[mas[i]] < r)
        cnt = -1;
}

void output()
{
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}