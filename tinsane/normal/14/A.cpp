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
    bool ye(0);
    int n, m, lb(0), rib, ub, lefb(0);
    string mas[50];
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    ye = 0;
    ub = n;
    rib = m;
    for(int i(n - 1); i >= 0; --i, --ub)
    {
        for(int j(0); !ye && j < m; ++j)
            if(mas[i][j] == '*')
                ye = 1;
        if(ye)
            break;
    }
    ye = 0;
    for(int i(0); i < n; ++i, ++lb)
    {
        for(int j(0); !ye && j < m; ++j)
            if(mas[i][j] == '*')
                ye = 1;
        if(ye)
            break;
    }
    ye = 0;
    for(int i(0); i < m; ++i, ++lefb)
    {
        for(int j(0); !ye && j < n; ++j)
            if(mas[j][i] == '*')
                ye = 1;
        if(ye)
            break;
    }
    ye = 0;
    for(int i(m - 1); i >= 0; --i, --rib)
    {
        for(int j(0); !ye && j < n; ++j)
            if(mas[j][i] == '*')
                ye = 1;
        if(ye)
            break;
    }

    for(int i(lb); i < ub; ++i, cout << '\n')
        for(int j(lefb); j < rib; ++j)
            cout << mas[i][j];
    return 0;
}