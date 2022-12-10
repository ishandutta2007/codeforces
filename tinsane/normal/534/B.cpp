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
const int MAXN = 5e5 + 10;

int v1, v2, t, d, ans(0), mas[101];

void init()
{
    cin >> v1 >> v2 >> t >> d;
}

void solve()
{
    mas[0] = v1;
    for(int i(1); i < t; ++i)
        mas[i] = mas[i - 1] + d;
    mas[t - 1] = v2;
    for(int i(t - 2); i; --i)
    if(mas[i] - mas[i + 1] <= d)
        break;
    else
        mas[i] = mas[i + 1] + d;
    for(int i(0); i < t; ++i)
        ans += mas[i];
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