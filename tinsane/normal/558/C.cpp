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
    int n, mas[MAXN], an((1LL << 20) - 1), x, nan, res(MAXINT), tres, tt(0);
    cin >> n;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i];
        x = mas[i];
        for(; x < (1 << 19); x <<= 1);
        an &= x;
    }
    for(; !(an & 1); an >>= 1);
    nan = an;
    for(int i(0); i < n; ++i)
    {
        int la(0);
        x = mas[i];
        for(int cnt(0); x != nan; x >>= 1, ++cnt)
        {
            if(x & 1)
                la = cnt + 1;
        }
        tt += la;
        mas[i] >>= la;
    }
    for(int j(0); an < (1 << 19); an <<= 1, ++j)
    {
        tres = 0;
        for(int i(0); i < n; ++i)
        {
            x = mas[i];
            if(x < an)
                for(; x != an; x <<= 1, ++tres);
            else
                for(; x != an; x >>= 1, ++tres);
        }
        res = min(res, tres);
    }
    cout << res + tt;
    return 0;
}