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

int gcd(int a, int b)
{
    return (a % b ? gcd(b, a % b) : b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    long long a, x, y, b(0), c(0), num;
    char punch[2000001];
    string res[3];
    cin >> n >> x >> y;
    num = gcd(x, y);
    x /= num;
    y /= num;
    if(x == y)
    {
        for(int i(0); i < n; ++i)
            cout << "Both\n";
        return 0;
    }
    if(x < y)
    {
        b += x;
        punch[1] = 1;
    }
    else
    {
        c += y;
        punch[1] = 2;
    }
    for(int i(2); i <= x + y; ++i)
    {
        if(b + x < c + y)
        {
            b += x;
            punch[i] = 1;
        }
        else
        {
            c += y;
            punch[i] = 2;
        }
    }
    res[1] = "Vova\n";
    res[2] = "Vanya\n";
    while(n--)
    {
        cin >> a;
        a %= (x + y);
        if(!a || (a + 1) % (x + y) == 0)
        {
            cout << "Both\n";
            continue;
        }
        cout << res[punch[a]];
    }
    return 0;
}