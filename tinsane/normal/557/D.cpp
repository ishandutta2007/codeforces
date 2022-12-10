#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
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
const double eps = 1e-11;
const int MAXN = 1e5 + 10;
    
struct ver
{
    int num;
    vector<int> edges;
} mas[MAXN];

bool dfs(int v)
{
    bool ret(0);
    for(int i(0); i < mas[v].edges.size(); ++i)
    {
        int to = mas[v].edges[i];
        if(mas[to].num)
        {
            if(mas[to].num == mas[v].num)
                return 1;
        }
        else
            mas[to].num = 3 - mas[v].num, ret |= dfs(to);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long n, m, res(0);
    int a, b, wave[MAXN], wsi;
    bool f(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        mas[i].num = 0;
    if(!m)
    {
        cout << 3 << ' ' << n * (n - 1) * (n - 2) / 6;
        return 0;
    }
    for(int i(0); i < m; ++i)
    {
        cin >> a >> b;
        --a, --b;
        mas[a].edges.push_back(b);
        mas[b].edges.push_back(a);
        f |= (mas[a].edges.size() > 1);
        f |= (mas[b].edges.size() > 1);
    }
    if(!f)
    {
        cout << "2 " << m * (n - 2);
        return 0;
    }
    for(int i(0); i < n; ++i)
    if(!mas[i].num && (mas[i].num = 1) && dfs(i))
    {
        cout << "0 1";
        return 0;
    }
    cout << "1 ";
    for(int i(0); i < n; ++i)
    if(mas[i].num != 3)
    {
        long long c[3];
        c[1] = c[2] = 0;
        wsi = 1;
        wave[0] = i;
        ++c[mas[i].num];
        mas[i].num = 3;
        for(int j(0); j < wsi; ++j)
        for(int k(0); k < mas[wave[j]].edges.size(); ++k)
        {
            int to = mas[wave[j]].edges[k];
            if(mas[to].num == 3)
                continue;
            ++c[mas[to].num], mas[to].num = 3;
            wave[wsi++] = to;
        }
        res += (c[1] * (c[1] - 1) / 2) + (c[2] * (c[2] - 1) / 2);
    }
    cout << res;
    return 0;
}