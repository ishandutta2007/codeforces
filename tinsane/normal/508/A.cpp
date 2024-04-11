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

int n, m, k, x, y;
bool mas[MAXN][MAXN];

void init()
{
    cin >> n >> m >> k;
    ++++n, ++++m;
    for(int i(0); i < n; ++i)
    for(int j(0); j < m; ++j)
        mas[i][j] = 0;
}

void solve()
{
    for(int i(0); i < k; ++i)
    {
        cin >> x >> y;
        mas[x][y] = 1;
        if(mas[x - 1][y - 1] && mas[x][y - 1] && mas[x - 1][y])
        {
            cout << i + 1;
            return;
        }
        if(mas[x - 1][y] && mas[x - 1][y + 1] && mas[x][y + 1])
        {
            cout << i + 1;
            return;
        }
        if(mas[x][y + 1] && mas[x + 1][y + 1] && mas[x + 1][y])
        {
            cout << i + 1;
            return;
        }
        if(mas[x + 1][y] && mas[x + 1][y - 1] && mas[x][y - 1])
        {
            cout << i + 1;
            return;
        }
    }
    cout << 0;
}

void output()
{
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}