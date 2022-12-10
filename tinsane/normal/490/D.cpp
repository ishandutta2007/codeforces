#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;

long long gcd(long long a, long long b)
{
    return (a % b ? gcd(b, a % b) : b);
}

long long a1, b1, a2, b2, s1, s2, g;
int m(0), c1(0), c2(0), d1(0), d2(0);

void init()
{
    cin >> a1 >> b1 >> a2 >> b2;
    s1 = a1 * b1;
    s2 = a2 * b2;
    g = gcd(s1, s2);
    s1 /= g, s2 /= g;
}

void solve()
{
    for(; s1 % 3 == 0; s1 /= 3, s1 *= 2, ++m, ++c1);
    for(; s2 % 3 == 0; s2 /= 3, s2 *= 2, ++m, ++c2);
    g = gcd(s1, s2);
    s1 /= g;
    s2 /= g;

    for(; s1 % 2 == 0; s1 /= 2, ++m, ++d1);
    for(; s2 % 2 == 0; s2 /= 2, ++m, ++d2);
    if(s1 != 1 || s2 != 1)
        m = -1;

    for(; a1 % 3 == 0 && c1; a1 /= 3, a1 *= 2, --c1);
    for(; b1 % 3 == 0 && c1; b1 /= 3, b1 *= 2, --c1);
    for(; a2 % 3 == 0 && c2; a2 /= 3, a2 *= 2, --c2);
    for(; b2 % 3 == 0 && c2; b2 /= 3, b2 *= 2, --c2);
    for(; a1 % 2 == 0 && d1; a1 /= 2, --d1);
    for(; b1 % 2 == 0 && d1; b1 /= 2, --d1);
    for(; a2 % 2 == 0 && d2; a2 /= 2, --d2);
    for(; b2 % 2 == 0 && d2; b2 /= 2, --d2);
}

void output()
{
    if(m == -1)
        cout << m;
    else
    {
        cout << m << '\n';
        cout << a1 << ' ' << b1 << '\n';
        cout << a2 << ' ' << b2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}