#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
#include <map>
using namespace std;
#pragma comment(linker, "/STACK:1677721600")

const long long MAXLL = 2e18;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;

template <typename T>
T MOD(T a)
{
    return (a > 0 ? a : -a);
}

template <typename T>
T MAX(T a, T b)
{
    return (a > b ? a : b);
}

template <typename T>
T MIN(T a, T b)
{
    return (a > b ? b : a);
}
const double TL = 2;    // 2 sec

inline bool isTL()
{
    static bool is(0);
    static int cou(0);
    if (++cou > 1000)
    {
        cou = 0;
        is |= clock() > (TL - 0.08) * CLOCKS_PER_SEC;
    }
    return is;
}
int n, si, f(-1), l(-1);
string s, t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    si = s.size();
    n = t.size();
    int i(0), j(0);
    for (; i < n && j < si; ++i)
    if (t[i] == s[j])
    {
        ++j;
        if (j == si)
        {
            f = i;
            break;
        }
    }
    i = n - 1;
    j = si - 1;
    for (; i >= 0 && j >= 0; --i)
    if (t[i] == s[j])
    {
        --j;
        if (j == -1)
        {
            l = i;
            break;
        }
    }
    cout << MAX(0, l - f);
    return 0;
}