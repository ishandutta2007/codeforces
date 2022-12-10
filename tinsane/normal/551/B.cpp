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
const int MAXN = 1e6 + 10;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s, sb, sc;
    int a[256], b[256], c[256], mres(0), bcou(0);
    for(int i(0); i < 256; ++i)
        a[i] = b[i] = c[i] = 0;
    cin >> s;
    for(int i(0); i < s.size(); ++i)
        ++a[s[i]];
    cin >> s;
    sb = s;
    for(int i(0); i < s.size(); ++i)
        ++b[s[i]];
    cin >> s;
    sc = s;
    for(int i(0); i < s.size(); ++i)
        ++c[s[i]];
    for(int i(0); i < 100003; ++i)
    {
        int ma = MAXINT;
        bool f(0);
        for(int j(0); j < 256 && !f; ++j)
        if(a[j] < b[j] * i)
            f = 1;
        if(f)
            break;
        for(int j(0); j < 256; ++j)
        if(c[j])
            ma = min(ma, (a[j] - b[j] * i) / c[j]);
        if(ma + i > mres)
        {
            mres = ma + i;
            bcou = i;
        }
    }
    for(int i(0); i < bcou; ++i)
        cout << sb;
    for(int i(0); i < mres - bcou; ++i)
        cout << sc;
    for(char i(0); i < 127; ++i)
    {
        a[i] -= b[i] * bcou + c[i] * (mres - bcou);
        for(;a[i]-- > 0; cout << i);
    }   
    return 0;
}