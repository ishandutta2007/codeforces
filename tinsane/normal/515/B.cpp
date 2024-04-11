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

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k, t;
    int g[100], b[100];
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        g[i] = 0;
    for(int i(0); i < m; ++i)
        b[i] = 0;
    cin >> k;
    while(k--)
    {
        cin >> t;
        g[t] = 1;
    }
    cin >> k;
    while(k--)
    {
        cin >> t;
        b[t] = 1;
    }
    b[0] = g[0] = (b[0] | g[0]);
    for(int i(1 % n), j(1 % m), cou(0); cou < 100000000; ++i, ++j, i %= n, j %= m, ++cou)
        g[i] = b[j] = (g[i] | b[j]);
    bool res(1);
    for(int i(0); i < n; ++i)
        res &= g[i];
    for(int i(0); i < m; ++i)
        res &= b[i];
    if(res)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}