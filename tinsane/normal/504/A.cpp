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

struct ver
{
    int deg, xor, num;
};

struct comp
{
    bool operator() (const ver& f, const ver& s)
    {
        if(f.deg != s.deg)
            return f.deg < s.deg;
        else
            return f.num > s.num;
    }
};

int main()
{
    ver mas[100000];
    int n, ans(0);
    set<ver, comp> lol;
    cin >> n;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i].deg >> mas[i].xor;
        mas[i].num = i;
        ans += mas[i].deg;
    }
    ans /= 2;
    cout << ans << '\n';
    for(int i(0); i < n; ++i)
        lol.insert(mas[i]);
    while(lol.size())
    if(lol.begin()->deg)
    {
        int tmp = lol.begin()->xor;
        cout << lol.begin()->num << ' ' << tmp << '\n';
        lol.erase(lol.find(mas[tmp]));
        --mas[tmp].deg;
        mas[tmp].xor ^= lol.begin()->num;
        lol.erase(lol.begin());
        lol.insert(mas[tmp]);
    }
    else
        lol.erase(lol.begin());
    return 0;
}