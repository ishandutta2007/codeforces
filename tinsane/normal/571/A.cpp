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
const int MAXN = 2e4 + 10;
const int MAXQ = 5e4 + 10;

int a, b, c;
long long res(0), l;

void init()
{
    cin >> a >> b >> c >> l;
    if(a > b)
        swap(a, b);
    if(b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);
}

void solve()
{
    for(long long i(0); i <= l; ++i)
    {
        if(c >= a + b + i)
            continue;
        res += (i + 1) * (i + 2) / 2;
        long long k(min((a + b + i - c + 1) / 2, i + 1));
        res -= (i - k + 1) * (i - k + 2) / 2;
        k = min(i + 1, (a + c + i - b + 1) / 2);
        res -= (i - k + 1) * (i - k + 2) / 2;
        k = min(i + 1, (b + c + i - a + 1) / 2);
        res -= (i - k + 1) * (i - k + 2) / 2;
    }
}

void output()
{
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}