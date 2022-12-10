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
    long long n, m, mas[100][100], a[100], b[100], mb, lol(0);
    cin >> n >> m;
    for(long long i(0); i < n; ++i)
    for(long long j(0); j < m; ++j)
        cin >> mas[i][j];
    for(long long k(0); k < n; ++k)
    {
        lol = -1;
        a[k] = 0;
        mb = 0;
        for(long long i(0); i < m; ++i)
        {
            b[i] = mas[k][i];
            if(b[i] < b[mb])
                mb = i;
        }
        for(long long i(0); i < n; ++i)
            a[i] = mas[i][mb] - b[mb];
        bool win(1);
        for(long long i(0); win && i < n; ++i)
        for(long long j(0); win && j < m; ++j)
        if(mas[i][j] != a[i] + b[j])
        {
            if(lol == -1)
                lol = MOD(a[i] + b[j] - mas[i][j]);
            else if(mas[i][j] != (a[i] + b[j]) % lol)
                win = 0;
        }
        if(lol == -1)
            lol = MAXINT * 2;
        for(int i(0); i < n; ++i)
            a[i] += lol;
        win = 1;
        for(long long i(0); win && i < n; ++i)
        for(long long j(0); win && j < m; ++j)
        if(mas[i][j] != (a[i] + b[j]) % lol)
            win = 0;
        if(win)
        {
            cout << "YES\n" << lol << '\n';
            for(long long i(0); i < n; ++i)
                cout << a[i] << ' ';
            cout << '\n';
            for(long long i(0); i < m; ++i)
                cout << b[i] << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "NO";
    return 0;
}