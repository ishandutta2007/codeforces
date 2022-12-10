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
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, mas[MAXN], cnt[MAXN * 10], lef[MAXN * 10], ri[MAXN * 10], ma(0), a1(0), a2;
    for(int i(0); i < MAXN * 10; ++i)
        cnt[i] = 0;
    cin >> n;
    a2 = n - 1;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i];
        ma = max(ma, ++cnt[mas[i]]);
        ri[mas[i]] = i;
        if(cnt[mas[i]] == 1)
            lef[mas[i]] = i;
    }
    for(int i(0); i < MAXN * 10; ++i)
    if(cnt[i] == ma)
    {
        if(a2 - a1 > ri[i] - lef[i])
            a1 = lef[i], a2 = ri[i];
    }
    cout << a1 + 1 << ' ' << a2 + 1;
    return 0;
}