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

bool b[100][100], a[100][100], nb[100][100], f;
int n, m, x;

void init()
{
    cin >> n >> m;
    for(int i(0); i < n; ++i)
    for(int j(0); j < m; ++j)
        cin >> x, b[i][j] = x, a[i][j] = 1;
}

void solve()
{
    for(int i(0); i < n; ++i)
    for(int j(0); j < m; ++j)
    if(!b[i][j])
    {
        for(int k(0); k < m; ++k)
            a[i][k] = 0;
        for(int k(0); k < n; ++k)
            a[k][j] = 0;
    }
    for(int i(0); i < n; ++i)
    for(int j(0); j < m; ++j)
    {
        f = 0;
        for(int k(0); k < m; ++k)
            f |= a[i][k];
        for(int k(0); k < n; ++k)
            f |= a[k][j];
        nb[i][j] = f;
    }
    f = 1;
    for(int i(0); i < n; ++i)
    for(int j(0); j < m; ++j)
        f &= b[i][j] == nb[i][j];
}

void output()
{
    if(f)
    {
        cout << "YES\n";
        for(int i(0); i < n; ++i)
        for(int j(0); j < m; ++j)
            cout << (a[i][j] ? 1 : 0) << ' ';
    }
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}