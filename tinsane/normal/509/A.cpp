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

const int MAXN = 10;

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n, mas[MAXN][MAXN];
    cin >> n;
    for(int i(0); i < 10; ++i)
        mas[i][0] = mas[0][i] = 1;
    for(int i(1); i < n; ++i)
        for(int j(1); j < n; ++j)
            mas[i][j] = mas[i - 1][j] + mas[i][j - 1];
    cout << mas[n - 1][n - 1];
    return 0;
}