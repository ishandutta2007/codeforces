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
#include <list>
using namespace std;
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

#pragma comment(linker, "/STACK:167772160")

const int MAXN = 500000;

inline int vow(char c)
{
    switch(c)
    {
    case 'I':
    case 'E':
    case 'A':
    case 'O':
    case 'U':
    case 'Y':
        return 1;
    default:
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    long long ri[MAXN], lef[MAXN], mas[MAXN];
    double ans(0);
    string s;
    cin >> s;
    n = s.size();
    for(int i(0); i < n; ++i)
        s[i] = vow(s[i]);
    if(n == 1)
    {
        if(s[0])
            cout << "1.000000";
        else
            cout << "0.000000";
        return 0;
    }

    lef[0] = s[0];
    for(int i(2); i <= n; ++i)
        lef[i - 1] = lef[i - 2] + i * s[i - 1];

    ri[n - 1] = s[n - 1];
    for(int i(2); i <= n; ++i)
        ri[n - i] = ri[n - i + 1] + i * s[n - i];

    mas[0] = s[0];
    for(int i(1); i < n; ++i)
        mas[i] = mas[i - 1] + s[i];

    ans += mas[n - 1] * (n + 1.0) / n;
    for(int i(2); i <= (n + 1) / 2; ++i)
    {
        ans += (mas[n - i] - mas[i - 2]);
        ans += (lef[i - 2] + ri[n - i + 1]) * 1.0 / i;
    }
    for(int i((n + 1) / 2 + 1); i < n; ++i)
    {
        ans += (mas[i - 1] - mas[n - i - 1]) * (n - i + 1.0) / i;
        ans += (lef[n - i - 1] + ri[i]) * 1.0 / i;
    }
    cout << setprecision(7) << fixed;
    cout << ans;
    return 0;
}