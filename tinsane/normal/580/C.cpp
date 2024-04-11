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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

struct Node
{
    int cnt;
    bool used;
    vector<int> edges;

    int operator[] (int v) const
    {
        return edges[v];
    }
} mas[MAXN];

int n, m, a, b, ans(0);

void dfs(int v, int c)
{
    mas[v].cnt = (mas[v].cnt ? c + 1 : 0);
    mas[v].used = 1;
    if(mas[v].cnt > m)
        return;
    if(mas[v].edges.size() == 1 && v != 0)
        ++ans;
    for(int i(0); i < mas[v].edges.size(); ++i)
    if(!mas[mas[v][i]].used)
        dfs(mas[v][i], mas[v].cnt);
}

void init()
{
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cin >> mas[i].cnt, mas[i].used = 0;
    for(int i(1); i < n; ++i)
        cin >> a >> b, --a, --b, mas[a].edges.push_back(b), mas[b].edges.push_back(a);
}

void solve()
{
    dfs(0, 0);
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