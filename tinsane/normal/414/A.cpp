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
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if(n / 2 > k || (n == 1 && k != 0))
    {
        cout << -1;
        return 0;
    }
    if(k == n / 2)
    {
        for(int i(1); i <= n; ++i)
            cout << i << ' ';
        return 0;
    }
    k -= n / 2 - 1;
    cout << k << ' ' << k * 2 << ' ';
    for(int i(300000000), j(2); j < n; ++j, ++i)
        cout << i << ' ';
    return 0;
}