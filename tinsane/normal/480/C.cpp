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

int main()
{
    int n, a,  b, k;
    long long w[5000], tmp[5000], ans(0);
    cin >> n >> a >> b >> k;
    for(int i(0); i < n; ++i)
        w[i] = 0;
    --a;
    --b;
    w[a] = 1;
    for(int i(0); i < k; ++i)
    {
        tmp[0] = w[0];
        for(int j(1); j < n; ++j)
            tmp[j] = tmp[j - 1] + w[j];
        for(int j(0); j < b; ++j)
            w[j] = (tmp[(j + b - 1) >> 1] - w[j]) % MODUL;
        for(int j(b + 1); j < n; ++j)
            w[j] = (tmp[n - 1] - w[j] - tmp[(j + b) >> 1]) % MODUL;
    }
    for(int i(0); i < n; ++i)
        ans += w[i];
    cout << ans % MODUL;
    return 0;
}