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
    int n, mas[1001], x, mind(10000);
    cin >> n >> x;
    for(int i(0); i <= 1000; ++i)
        mas[i] = 0;
    for(int i(0); i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        for(int j(a); j <= b; ++j)
            ++mas[j];
    }
    for(int i(0); i < 1001; ++i)
        if(mas[i] == n)
            mind = MIN(mind, MOD(x - i));
    cout << (mind == 10000 ? -1 : mind);
    return 0;
}