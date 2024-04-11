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
const int MAXN = 3e3 + 10;

int n, mas[MAXN], mip, asi(0), ax[MAXN], ay[MAXN];

void init()
{
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> mas[i];
}

void solve()
{
    for(int i(0); i < n; ++i)
    {
        mip = i;
        for(int j(i + 1); j < n; ++j)
        if(mas[j] < mas[mip])
            mip = j;
        if(mip != i)
        {
            ax[asi] = mip;
            ay[asi++] = i;
            swap(mas[i], mas[mip]);
        }
    }
}

void output()
{
    cout << asi << '\n';
    for(int i(0); i < asi; ++i)
        cout << ax[i] << ' ' << ay[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}