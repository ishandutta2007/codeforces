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

int main()
{
    string fr[100]; 
    int n, m, pr[100], lol[100], now(0), mi(0), ma(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cin >> pr[i];
    sort(pr, pr + n);
    for(int i(0); i < m; ++i)
        cin >> fr[i];
    sort(fr, fr + m);
    lol[0] = 1;
    for(int i(1); i < m; ++i)
        if(fr[i] == fr[i - 1])
            ++lol[now];
        else
            lol[++now] = 1;
    ++now;
    sort(lol, lol + now);
    for(int i(now - 1), j(0); i >= 0; --i, ++j)
        mi += lol[i] * pr[j];
    for(int i(now - 1), j(n - 1); i >= 0; --i, --j)
        ma += lol[i] * pr[j];
    cout << mi << ' ' << ma;
    return 0;
}