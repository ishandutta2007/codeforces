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

#pragma comment(linker, "/STACK:1677721600")

struct point
{
    int x, y;
    bool used;

    point() : used(0){};
};

struct line
{
    int a, b, c;

    line(point f, point s)
    {
        a = f.y - s.y;
        b = s.x - f.x;
        c = f.x * s.y - f.y * s.x;
    }
    line() : a(0), b(0), c(0){};
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, ans(0);
    point bl, mas[1000];
    cin >> n >> bl.x >> bl.y;
    for(int i(0); i < n; ++i)
        cin >> mas[i].x >> mas[i].y;
    for(int i(0); i < n; ++i)
    if(!mas[i].used)
    {
        line lol(bl, mas[i]);
        for(int j(i); j < n; ++j)
            if(mas[j].x * lol.a + mas[j].y * lol.b + lol.c == 0)
                mas[j].used = 1;
        ++ans;
    }
    cout << ans;
    return 0;
}