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
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = 1e3 + 10;

int n, l, r, d, mas[15], ans(0), sum(0);

void dfs(int x, int mi, int ma)
{
    if(x == n)
    {
        if(sum >= l && sum <= r && ma - mi >= d)
            ++ans;
        return;
    }
    dfs(x + 1, mi, ma);
    sum += mas[x];
    ma = max(ma, mas[x]);
    mi = min(mi, mas[x]);
    dfs(x + 1, mi, ma);
    sum -= mas[x];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l >> r >> d;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
    dfs(0, MAXINT, -MAXINT);
    cout << ans;
    return 0;
}