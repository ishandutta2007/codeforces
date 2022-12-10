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

struct poi
{
    int x, w;
};

bool c1(poi& x, poi& y)
{
    return x.x < y.x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    poi mas[200000];
    int dp, cou(1);
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i].x >> mas[i].w;
    sort(mas, mas + n, c1);
    dp = mas[0].x + mas[0].w;
    for(int i(1); i < n; ++i)
    {
        if(mas[i].x - dp >= mas[i].w)
        {
            ++cou;
            dp = mas[i].x + mas[i].w;
        }
        else if(mas[i].x + mas[i].w < dp)
            dp = mas[i].x + mas[i].w;
    }
    cout << cou;
    return 0;
}