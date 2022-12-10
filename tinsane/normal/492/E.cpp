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

long long bpow(long long x, int pow, long long mod)
{
    if(pow == 0)
        return 1;
    if(pow & 1)
        return x * bpow(x * x % mod, pow / 2, mod) % mod;
    else
        return bpow(x * x % mod, pow / 2, mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long n, dx, dy, fn(1), add, x, y, ody, t;
    int m, mas[1000000];
    cin >> n >> m >> dx >> dy;
    if(n == 1)
    {
        cout << "0 0";
        return 0;
    }
    for(int i(0); i < n; ++i)
        mas[i] = 0;
    add = n;
    for(int i(2); i * i <= add; ++i)
    {
        if(!(add % i))
        {
            fn *= i - 1;
            add /= i;
            while(!(add % i))
            {
                add /= i;
                fn *= i;
            }
        }
    }
    if(add != 1)
        fn *= add - 1;
    ody = bpow(dy, fn - 1, n);
    for(int i(0); i < m; ++i)
    {
        cin >> x >> y;
        t = y * ody % n;
        ++mas[((x - t * dx) % n + n) % n];
    }
    int map(0);
    for(int i(1); i < n; ++i)
        if(mas[i] > mas[map])
            map = i;
    cout << map << " 0";
    return 0;
}