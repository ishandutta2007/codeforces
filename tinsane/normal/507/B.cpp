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
const int MAXN = 1e4 + 10;

long long x, y, xx, yy, d, r, ans;

void init()
{
    cin >> r >> x >> y >> xx >> yy;
    r *= 2;
}

void solve()
{
    d = (xx - x) * (xx - x) + (yy - y) * (yy - y);
    ans = sqrt(d / (r * r) * 1.0);
    if(ans * ans * r * r < d)
        ++ans;
}

void output()
{
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}