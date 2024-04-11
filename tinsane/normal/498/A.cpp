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

struct point
{
    long long x, y;
};

struct line
{
    long long a, b, c;
};



int main()
{
    int n, res(0);
    point ho, un;
    line tmp;
    cin >> ho.x >> ho.y >> un.x >> un.y >> n;
    while(n--)
    {
        cin >> tmp.a >> tmp.b >> tmp.c;
        long long t1, t2;
        t1 = tmp.a * ho.x + tmp.b * ho.y + tmp.c;
        t2 = tmp.a * un.x + tmp.b * un.y + tmp.c;
        if((t1 > 0 && t2 < 0) || (t1 < 0 && t2 > 0))
            ++res;
    }
    cout << res;
    return 0;
}