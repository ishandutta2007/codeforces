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
    int num;
    bool used;
    int mt;
    vector<int> g;
} mas[10000];

struct lol
{
    long long num;
    vector<int> sv;
    int fw, si;
} a[300];

int msi(0);

bool try_kuhn (int v) 
{
    if (mas[v].used)  
        return false;
    mas[v].used = true;
    for (size_t i(0); i < mas[v].g.size(); ++i) 
    {
        int to = mas[v].g[i];
        if (mas[to].mt == -1 || try_kuhn (mas[to].mt)) 
        {
            mas[to].mt = v;
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m, ans(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        cin >> a[i].num;
    for(int i(0); i < m; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 > t2)
            swap(t1, t2);
        --t1;
        --t2;
        a[t2].sv.push_back(t1);
    }
    for(int i(0); i < n; ++i)
    {
        a[i].fw = msi;
        a[i].si = msi;
        for(int j(2); j * j <= a[i].num; ++j)
        while(a[i].num % j == 0)
        {
            ++a[i].si;
            mas[msi].num = j;
            mas[msi].used = 0;
            mas[msi].mt = -1;
            a[i].num /= j;
            for(int s(0); s < a[i].sv.size(); ++s)
                for(int s1(a[a[i].sv[s]].fw); s1 < a[a[i].sv[s]].si; ++s1)
                    if(mas[s1].num == j)
                    {
                        mas[s1].g.push_back(msi);
                        mas[msi].g.push_back(s1);
                    };
            ++msi;
        }
        if(a[i].num != 1)
        {
            int j = a[i].num;
            ++a[i].si;
            mas[msi].num = j;
            mas[msi].used = 0;
            mas[msi].mt = -1;
            a[i].num /= j;
            for(int s(0); s < a[i].sv.size(); ++s)
                for(int s1(a[a[i].sv[s]].fw); s1 < a[a[i].sv[s]].si; ++s1)
                    if(mas[s1].num == j)
                    {
                        mas[s1].g.push_back(msi);
                        mas[msi].g.push_back(s1);
                    };
            ++msi;
        }
    }
    for(int i(0); i < msi; ++i)
    {
        for(int j(0); j < msi; ++j)
            mas[j].used = 0;
        try_kuhn(i);
    }
    for(int i(0); i < msi; ++i)
        if(mas[i].mt != -1)
            ++ans;
    cout << ans / 2;
    return 0;
}