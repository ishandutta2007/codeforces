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
const int MAXN = 2e3 + 10;

struct Node
{
    vector<int> edges;
    long long dp;
    int num;

    int operator[] (int v)
    {
        return edges[v];
    }
    void push(int v)
    {
        edges.push_back(v);
    }
    int size()
    {
        return edges.size();
    }
} mas[MAXN];

int n, d, a, b, ft, ma;
long long ans;

void init()
{
    cin >> d >> n;
    for(int i(1); i <= n; ++i)
        cin >> mas[i].num;
    for(int i(1); i < n; ++i)
        cin >> a >> b, mas[a].push(b), mas[b].push(a);
}

void dfs(int v)
{
    mas[v].dp = 1;
    for(int i(0); i < mas[v].size(); ++i)
    if((mas[mas[v][i]].num < ma || (mas[mas[v][i]].num == ma && mas[v][i] > ft)) && ma - mas[mas[v][i]].num <= d && mas[mas[v][i]].dp == -1)
    {
        dfs(mas[v][i]);
        mas[v].dp = (mas[v].dp * (mas[mas[v][i]].dp + 1)) % MODUL;
    }
}

void solve()
{
    for(int i(1); i <= n; ++i)
    {
        for(int j(1); j <= n; ++j)
            mas[j].dp = -1;
        ma = mas[ft = i].num;
        dfs(i);
        ans = (ans + mas[i].dp) % MODUL;
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