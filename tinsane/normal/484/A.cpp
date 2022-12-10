#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>
#include <wchar.h>
using namespace std;
#pragma comment(linker, "/STACK:167772160")
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 1000000010;
const long long MAXLL = 1000000000000000000;

template <typename T>
inline T MIN(T lef, T ri)
{
    return (lef < ri ? lef : ri);
}

template <typename T>
inline T MAX(T lef, T ri)
{
    return (lef > ri ? lef : ri);
}

template <typename T>
inline T MOD(T val)
{
    return (val > 0 ? val : -val);
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long l, r, x, ans;
    int n, lbx;
    cin >> n;
    for (; n; --n)
    {
        cin >> l >> r;
        x = l ^ (r );
        ans = r;
        lbx = 0;
        for (; x; x >>= 1, ++lbx);
        ans >>= lbx;
        ans <<= lbx;
        --lbx;
        long long tmp = 1;
        bool f(1);
        for (int i(0); i <= lbx; ++i)
        {
            tmp = 1;
            tmp <<= i;
            if (!(tmp & r))
            {
                f = 0;
                break;
            }
        }
        tmp = 1;
        --lbx;
        for (int i(0); i < lbx; ++i)
        {
            tmp <<= 1;
            ++tmp;
        }
        if (f)
        {
            cout << r << '\n';
            continue;
        }
        ans += tmp;
        cout << ans << '\n';
    }
    return 0;
}