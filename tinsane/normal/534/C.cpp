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

int n, res[MAXN];
long long mas[MAXN], a, sum(0);

void init()
{
    cin >> n >> a;
    for(int i(0); i < n; ++i)
        cin >> mas[i], sum += mas[i], res[i] = 0;
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        long long mi(a - n + 1), ma(a - sum + mas[i] - 1);
        if(mi < mas[i])
            res[i] += mas[i] - mi;
        if(ma > 0)
            res[i] += ma;
    }
}

void output()
{
    for(int i(0); i < n; ++i)
        cout << res[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}