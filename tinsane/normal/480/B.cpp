#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>
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

int mas[100000];

bool bins(int d, int u, int val)
{
    if(u == d)
        if(mas[u] == val)
            return 1;
        else
            return 0;
    if(u == d + 1)
        if(mas[u] == val || mas[d] == val)
            return 1;
        else
            return 0;
    int m = (u + d) >> 1;
    if(mas[m] > val)
        return bins(d, m, val);
    else if(mas[m] < val)
        return bins(m, u, val);
    return 1;
}

int main()
{
    bool g(0), b(0);
    int n,l, x, y;
    cin >> n >> l >> x >> y;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    for(int i(1); i < n && !g; ++i)
        if(mas[i] >= x && bins(0, i - 1, mas[i] - x))
            g = 1;
    for(int i(1); i < n && !b; ++i)
        if(mas[i] >= y && bins(0, i - 1, mas[i] - y))
            b = 1;
    if(b && g)
    {
        cout << 0 << '\n';
        return 0;
    }
    if(b || g)
    {
        cout << 1 << '\n';
        if(b)
            cout << x;
        if(g)
            cout << y;
        return 0;
    }
    for(int i(1); i < n; ++i)
        if(mas[i] >= y + x && bins(0, i - 1, mas[i] - y - x))
        {
            cout << 1 << '\n' << mas[i] - y;
            return 0;
        };
    for(int i(1); i < n; ++i)
        if(mas[i] >= y - x && (mas[i] + x <= l || mas[i] - y >= 0) && bins(0, i - 1, mas[i] - y + x))
        {
            if(mas[i] + x <= l)
                cout << 1 << '\n' << mas[i] + x;
            else
                cout << 1 << '\n' << mas[i] - y;
            return 0;
        };
    cout << 2 << '\n' << x << ' ' << y;
    return 0;
}