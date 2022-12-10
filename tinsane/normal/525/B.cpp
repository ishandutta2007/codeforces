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

#pragma comment(linker, "/STACK:1677721600")

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    int m, mas[200000], x, n;
    cin >> s >> m;
    n = s.size();
    for(int i(0); i < n / 2; ++i)
        mas[i] = 0;
    while(m--)
    {
        cin >> x;
        --x;
        mas[x] ^= 1;
    }
    for(int i(0); i < n / 2; ++i)
    if(mas[i])
    {
        mas[i + 1] ^= 1;
        swap(s[i], s[n - i - 1]);
    }
    cout << s;
    return 0;
}