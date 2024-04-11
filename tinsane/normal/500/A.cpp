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
    int n, t, x;
    cin >> n >> t;
    bool mas[100000];
    mas[1] = 1;
    for( int i(2); i <= t; ++i)
        mas[i] = 0;
    for(int i(1); i < t; ++i)
    {
        cin >> x;
        if(mas[i])
            mas[i + x] = 1;
    }
    if(mas[t])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}