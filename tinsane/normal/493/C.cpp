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

int main()
{
    int n, m, a[200000], b[200000];
    long long sa(0), sb(0), maxd(-MAXINT), msa;
    cin >> n;
    for(int i(0); i < n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i(0); i < m; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    for(int i(0), j(0); i < n; ++i)
    {
        for(; j < m && b[j] < a[i]; ++j);
        sa = i * 2 + (n - i) * 3;
        sb = j * 2 + (m - j) * 3;
        if(maxd < sa - sb)
        {
            maxd = sa - sb;
            msa = sa;
        }
    }
    if((n - m) * 2 > maxd)
    {
        cout << n * 2 << ':' << m * 2;
        return 0;
    }
    cout << msa << ':' << msa - maxd;
    return 0;
}