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

int n, m, k, mas[MAXN], x, num[MAXN];
long long res(0);

void init()
{
    cin >> n >> m >> k;
    for(int i(0); i < n; ++i)
        cin >> mas[i], num[mas[i]] = i;
}

void solve()
{
    for(int i(0); i < m; ++i)
    {
        cin >> x;
        res += num[x] / k + 1;
        if(num[x] != 0)
        {
            --num[x];
            ++num[mas[num[x]]];
            swap(mas[num[x]], mas[num[x] + 1]);
        }
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