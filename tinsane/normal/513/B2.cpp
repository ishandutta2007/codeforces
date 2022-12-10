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

struct node
{
    int l, r;
};

int main()
{
    ios_base::sync_with_stdio(0);
    long long n, ans[50], l, b(0);
    long long m, cou;
    cin >> n >> m;
    l = n - 1;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    cou = 1LL << (n - 2);
    for(int i(1); i <= n; ++i) 
    {
        if(m <= cou)
        {
            ans[b] = i;
            ++b;
        }
        else
        {
            ans[l] = i;
            --l;
            m -= cou;
        }
        cou /= 2;
    }
    for(int i(0); i < n; ++i)
        cout << ans[i] << ' ';
    return 0;
}