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
const int MAXN = 1e5 + 10;

long long r, g, b, t(0);

void init()
{
    cin >> r >> g >> b;
    if(r > g)
        swap(r, g);
    if(g > b)
        swap(g, b);
    if(r > g)
        swap(r, g);
}

void solve()
{
    b -= r, g -= r;
    if(b >= g * 2)
    {
        t = g, b -= g * 2;
        if(b >= r * 3)
            t += 2 * r;
        else
            t += b / 3 + r;
    }
    else
    {
        t = b - g, b -= t * 2;
        t += r + (2 * b) / 3;
    }
}

void output()
{
    cout << t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}