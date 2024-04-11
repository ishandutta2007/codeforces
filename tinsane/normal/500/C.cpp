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

int comp(const void* a, const void* b)
{
    return ((pair<int, int>*) a)->first - ((pair<int, int>*) b)->first;
}

int main()
{
    deque<pair<int, int> > lol;
    int n, m, mas[500], x, get[1000];
    pair<int, int> mi[500];
    long long ans(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i];
        mi[i].first = MAXINT;
        mi[i].second = i;
    }
    for(int i(0); i < m; ++i)
    {
        cin >> get[i];
        --get[i];
    }
    for(int i(m - 1); i >= 0; --i)
        mi[get[i]].first = i;
    qsort(mi, n, sizeof(pair<int, int>), comp);
    for(int i(0); i < n; ++i)
        lol.push_back(make_pair(0, mi[i].second));
    for(int i(0); i < m; ++i)
    {
        pair<int, int> tmp;
        x = get[i];
        auto it = lol.begin();
        for(; it->second != x; ++it)
            ++it->first;
        tmp.first = it->first;
        tmp.second = it->second;
        lol.erase(it);
        lol.push_front(tmp);
    }
    for(int i(0); i < n; ++i)
        ans += lol[i].first * mas[lol[i].second];
    cout << ans;
    return 0;
}