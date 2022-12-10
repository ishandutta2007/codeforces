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
#include <list>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

#pragma comment(linker, "/STACK:167772160")

struct road
{
    int a, b;
    long long l;
};

struct town
{
    bool used;
    int h;
    long long cou;
    vector<int> con;
};
road mas[100000];
town gr[100001];
int n;
long long sum;

int dfs(int v, int h)
{
    gr[v].used = 1;
    gr[v].h = h;
    gr[v].cou = 1;
    for(int i(0); i < gr[v].con.size(); ++i)
        if(!gr[gr[v].con[i]].used)
            gr[v].cou += dfs(gr[v].con[i], h + 1);
    return gr[v].cou;
}

int main()
{
    int q, x, y;
    double res;
    cin >> n;
    for(int i(0); i < n - 1; ++i)
    {
        cin >> mas[i].a >> mas[i].b >> mas[i].l;
        gr[mas[i].a].con.push_back(mas[i].b);
        gr[mas[i].b].con.push_back(mas[i].a);
    }
    for(int i(1); i <= n; ++i)
        gr[i].used = 0;
    dfs(1, 0);
    sum = 0;
    for(int i(0); i < n - 1; ++i)
    {
        if(gr[mas[i].a].h < gr[mas[i].b].h)
            swap(mas[i].a, mas[i].b);
        sum += mas[i].l * 6 * gr[mas[i].a].cou * (n - gr[mas[i].a].cou);
    }
    cin >> q;
    cout << setprecision(7) << fixed;
    while(q--)
    {
        cin >> x >> y;
        --x;
        sum -= mas[x].l * 6 * gr[mas[x].a].cou * (n - gr[mas[x].a].cou);
        mas[x].l = y;
        sum += mas[x].l * 6 * gr[mas[x].a].cou * (n - gr[mas[x].a].cou);
        res = sum;
        cout << res / n / (n - 1) << '\n';
    }
    return 0;
}