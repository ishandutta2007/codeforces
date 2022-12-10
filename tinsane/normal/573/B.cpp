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

int n, mas[MAXN], ans, mi(1), ma(1e5 + 1);
bool seg[MAXN * 4];

void s_init(int l, int r, int ind)
{
    seg[ind] = 0;
    if(l != r)
        s_init(l, (l + r) / 2, ind * 2), s_init((l + r) / 2 + 1, r, ind * 2 + 1);
}

void make(int l, int r, int ind, int L, int R)
{
    if(l == L && r == R)
    {
        seg[ind] = 1;
        return;
    }
    if(L > R)
        return;
    make(l, (l + r) / 2, ind * 2, L, min(R, (l + r) / 2));
    make((l + r) / 2 + 1, r, ind * 2 + 1, max(L, (l + r) / 2 + 1), R);
}

bool get(int l, int r, int ind)
{
    if(l == r)
        return !seg[ind];
    if(seg[ind])
        return 0;
    else
        return (get(l, (l + r) / 2 , ind * 2) || get((l + r) / 2 + 1, r, ind * 2 + 1));
}

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
}

void solve()
{
    while(ma - mi > 1)
    {
        ans = (ma + mi) / 2;
        s_init(0, n - 1, 1);
        if(ans != 1)
            make(0, n - 1, 1, 0, min(ans - 2, n - 1)), make(0, n - 1, 1, max(0, n + 1 - ans), n - 1);
        for(int i(0); i < n; ++i)
        if(mas[i] < ans)
            make(0, n - 1, 1, max(0, i - (ans - mas[i] - 1)), min(n - 1, i + (ans - mas[i] - 1)));
        if(get(0, n - 1, 1))
            mi = ans;
        else
            ma = ans;
    }
    ans = mi;
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