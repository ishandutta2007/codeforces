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
struct edge
{
    int wh;
    bool f;
};

struct ver
{
    int dol;
    vector<edge> edges;
} mas[MAXN];

bool dfs(int v)
{
    int to, res(1);
    for(int i(0); i < mas[v].edges.size(); ++i)
    {
        to = mas[v].edges[i].wh;
        if(mas[to].dol)
        {
            if((mas[to].dol == mas[v].dol && !mas[v].edges[i].f) ||
                (mas[to].dol != mas[v].dol && mas[v].edges[i].f))
                return 0;
        }
        else
        {
            if(!mas[v].edges[i].f)
                mas[to].dol = 3 - mas[v].dol;
            else
                mas[to].dol = mas[v].dol;
            res &= dfs(to);
        }
    }
    return res;
}

long long bpow(long long x, int p)
{
    return (p ? (p & 1) ? (bpow(x * x % MODUL, p / 2) * x) % MODUL : bpow(x * x % MODUL, p / 2) : 1);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, a, c, cnt(-1);
    edge tmp;
    cin >> n >> m;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> tmp.wh >> c;
        tmp.f = c;
        --a, --tmp.wh;
        mas[a].edges.push_back(tmp);
        swap(a, tmp.wh);
        mas[a].edges.push_back(tmp);
    }
    for(int i(0); i < n; ++i)
        mas[i].dol = 0;
    for(int i(0); i < n; ++i)
    if(!mas[i].dol)
    {
        mas[i].dol = 1;
        if(dfs(i))
            ++cnt;
        else
        {
            cout << 0;
            return 0;
        }
    }
    cout << bpow(2, cnt);
    return 0;
}