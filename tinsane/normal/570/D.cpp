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
const int MAXN = 5e5 + 10;

struct Node
{
    int anc, h, in, out, maxh;
    vector<int> edges;
    char c;

    void push(int x)
    {
        edges.push_back(x);
    }

    int operator[] (int x)
    {
        return edges[x];
    }

    int size()
    {
        return edges.size();
    }
} mas[MAXN];

int n, m, wave[MAXN], wsi(1), dp[MAXN][26], ti(0), be[MAXN], en[MAXN], v, h, tmp;
string s("");

void dfs(int v)
{
    mas[v].in = ti++;
    mas[v].maxh = mas[v].h;
    for(int j(0); j < mas[v].size(); ++j)
        mas[mas[v][j]].h = mas[v].h + 1, dfs(mas[v][j]), mas[v].maxh = max(mas[v].maxh, mas[mas[v][j]].maxh);
    mas[v].out = ti;
}

int bp1(int l, int r, int v)
{
    if(l == r)
        return l;
    int mi = (l + r) / 2;
    if(mas[wave[mi]].in > mas[v].in)
        return bp1(l, mi, v);
    else
        return bp1(mi + 1, r, v);
}

int bp2(int l, int r, int v)
{
    if(l == r)
        return l;
    int mi = (l + r) / 2 + 1;
    if(mas[wave[mi]].out <= mas[v].out)
        return bp2(mi, r, v);
    else
        return bp2(l, mi - 1, v);
}

void init()
{
    cin >> n >> m;
    for(int i(1); i < n; ++i)
        cin >> mas[i].anc, mas[--mas[i].anc].push(i);
    for(int i(0); i < n; ++i)
        cin >> mas[i].c;

    wave[0] = 0;
    mas[0].h = 0;
    dfs(0);

    for(int i(0); i < wsi; ++i)
    {
        s += mas[wave[i]].c;
        for(int j(0); j < mas[wave[i]].size(); ++j)
            wave[wsi++] = mas[wave[i]][j];
    }

    for(int i(0); i < 26; ++i)
        dp[0][i] = 0;

    for(int i(1); i <= n; ++i)
    {
        for(int j(0); j < 26; ++j)
            dp[i][j] = dp[i - 1][j];
        ++dp[i][s[i - 1] - 'a'];
    }

    be[0] = 0;
    for(int i(1); i < n; ++i)
    if(mas[wave[i]].h != mas[wave[i - 1]].h)
        be[mas[wave[i]].h] = i, en[mas[wave[i - 1]].h] = i - 1;
    en[mas[wave[n - 1]].h] = n - 1;
}

void solve()
{
}

void output()
{
    for(int i(0); i < m; ++i)
    {
        cin >> v >> h;
        if(--h <= mas[--v].h || h > mas[v].maxh)
        {
            cout << "Yes\n";
            continue;
        }
        int l = bp1(be[h], en[h], v), r = bp2(be[h], en[h], v);
        tmp = 0;
        for(int i(0); i < 26; ++i)
            tmp += ((dp[r + 1][i] - dp[l][i]) & 1);
        if(tmp < 2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}