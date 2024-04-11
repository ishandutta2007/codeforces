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
const int MAXN = 2e5 + 10;

int n, m, res(0), x;

void init()
{
    cin >> n >> m;
}

void solve()
{
    while(n > m && m > 0)
        ----n, --m, ++res;
    while(m > n && n > 0)
        ----m, --n, ++res;
    x = min(m, n) / 3;
    res += x * 2;
    m -= x * 3;
    n -= x * 3;
    if(min(m, n) > 0 && max(m, n) > 1)
        ++res;
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