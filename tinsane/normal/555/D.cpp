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
const int MAXN = 2e5 + 10;

struct kol
{
    long long x;
    int num;
};

kol mas[MAXN];
int n, m, a, b, de[MAXN];

int bsr(int b, int e, long long l)
{
    if(b == e)
        return b;
    int m = (b + e) / 2 + 1;
    if(mas[m].x <= l)
        return bsr(m, e, l);
    else
        return bsr(b, m - 1, l);
}
int bsl(int b, int e, long long l)
{
    if(b == e)
        return b;
    int m = (b + e) / 2;
    if(mas[m].x >= l)
        return bsl(b, m, l);
    else
        return bsl(m + 1, e, l);
}

int dfs(int v, long long l)
{
    int fw = bsr(v, n - 1, l + mas[v].x);
    long long dist;
    if(fw == v)
    {
        fw = bsl(0, v, mas[v].x - l);
        if(fw == v)
            return v;
        dist = mas[v].x - mas[fw].x;
    }
    else
        dist = mas[fw].x - mas[v].x;
    if((l / dist) & 1LL)
        return dfs(fw, l % dist);
    else
        return dfs(v, l % dist);
}
int dfsf(int v, long long l)
{
    int fw = bsr(v, n - 1, l + mas[v].x);
    return dfs(fw, l - mas[fw].x + mas[v].x);
}


bool comp(const kol& f, const kol& s)
{
    return f.x < s.x;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cin >> mas[i].x, mas[i].num = i + 1;
    sort(mas, mas + n, comp);
    for(int i(0); i < n; ++i)
        de[mas[i].num] = i;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> b;
        cout << mas[dfsf(de[a], b)].num << '\n';
    }
    return 0;
}