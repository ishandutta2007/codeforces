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
    int ma(0), n, l, a, b, mas[1000];
    cin >> n >> l;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    sort(mas, mas + n);
    ma = mas[0] * 2;
    b = mas[0];
    for(int i(1); i < n; ++i)
    {
        a = b;
        b = mas[i];
        ma = MAX(ma, b - a);
    }
    ma = MAX(ma, (l - b) * 2);
    if(ma & 1)
        cout << ma / 2 << ".50000000000";
    else
        cout << ma / 2;
    return 0;
}