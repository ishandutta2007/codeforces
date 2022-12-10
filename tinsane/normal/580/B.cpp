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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

struct Friend
{
    long long mon, god;

    bool operator< (const Friend& f) const
    {
        return mon < f.mon;
    }
} mas[MAXN];

int n, d;
long long ans(0);

void init()
{
    cin >> n >> d;
    for(int i(0); i < n; ++i)
        cin >> mas[i].mon >> mas[i].god;
    sort(mas, mas + n);
    for(int i(1); i < n; ++i)
        mas[i].god += mas[i - 1].god;
}

void solve()
{
    for(int i(0), j(0); i < n; ++i)
    {
        for(; j < n && mas[j].mon - mas[i].mon < d; ++j);
        if(i == 0)
            ans = max(ans, mas[j - 1].god);
        else
            ans = max(ans, mas[j - 1].god - mas[i - 1].god);
    }
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