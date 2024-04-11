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
#include <bitset>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mk make_pair

typedef pair<int, int> pii;

//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = 1e3 + 10;

long long ans(MAXINT), cnt(2), d12, d13, d23;
long long n, m, d[3][MAXN][MAXN], t, wave[MAXN * MAXN], wsi;
char mas[MAXN][MAXN], c;

void init()
{
    scanf("%d%d", &n, &m);
    for(int i(1); i <= n; ++i)
    {
        scanf("%c", &c);
        for(int j(1); j <= m; ++j)
            scanf("%c", &mas[i][j]);
    }
    for(int i(0); i <= n + 1; ++i)
        mas[i][0] = mas[i][m + 1] = '#';
    for(int i(0); i <= m + 1; ++i)
        mas[0][i] = mas[n + 1][i] = '#';
}

void tr(int x, int y, int v)
{
    if(d[t][x][y] == -1 && mas[x][y] != '#')
    {
        d[t][x][y] = v;
        wave[wsi++] = x * MAXN + y;
    }
}

void move(int x, int y)
{
    tr(x - 1, y, d[t][x][y] + 1);
    tr(x + 1, y, d[t][x][y] + 1);
    tr(x, y + 1, d[t][x][y] + 1);
    tr(x, y - 1, d[t][x][y] + 1);
}

void solve()
{
    for(t = 0; t < 3; ++t)
    {
        for(int i(1); i <= n; ++i)
        for(int j(1); j <= m; ++j)
            d[t][i][j] = -1;
        wsi = 0;
        for(int i(1); i <= n; ++i)
        for(int j(1); j <= m; ++j)
        if(mas[i][j] == '1' + t)
        {
            wave[wsi++] = i * MAXN + j;
            d[t][i][j] = 0;
        }
        if(wsi == 0)
        {
            for(int i(1); i <= n; ++i)
            for(int j(1); j <= m; ++j)
                d[t][i][j] = 0;
            continue;
        }
        for(int i(0); i < wsi; ++i)
            move(wave[i] / MAXN, wave[i] % MAXN);
    }
    for(t = 0; t < 3; ++t)
    for(int i(1); i <= n; ++i)
    for(int j(1); j <= m; ++j)
    if(d[t][i][j] == -1)
        d[t][i][j] = MAXINT;
    for(int i(1); i <= n; ++i)
    for(int j(1); j <= m; ++j)
        ans = min(ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);

    d12 = MAXINT;
    for(int i(1); i <= n; ++i)
    for(int j(1); j <= m; ++j)
        d12 = min(d12, d[0][i][j] + d[1][i][j] - 1);
    d13 = MAXINT;
    for(int i(1); i <= n; ++i)
    for(int j(1); j <= m; ++j)
        d13 = min(d13, d[0][i][j] + d[2][i][j] - 1);
    d23 = MAXINT;
    for(int i(1); i <= n; ++i)
    for(int j(1); j <= m; ++j)
        d23 = min(d23, d[2][i][j] + d[1][i][j] - 1);
    ans = min(ans, d12 + d13);
    ans = min(ans, d12 + d23);
    ans = min(ans, d13 + d23);
}

void output()
{
    if(ans >= MAXINT - 10)
        printf("-1");
    else
        printf("%I64d", ans);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
}