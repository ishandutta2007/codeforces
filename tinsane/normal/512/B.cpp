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

int gcd(int a, int b)
{
    return (a % b ? gcd(b, a % b) : b);
}

struct node
{
    int gcd, cost;
};

struct comp
{
    bool operator() (const node& l, const node& r)
    {
        return r.gcd < l.gcd;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, val[10000], cos[10000],ans(MAXINT);
    cin >> n;
    node tmp;
    set<node, comp> mas;
    for(int i(0); i < n; ++i)
        cin >> val[i];
    for(int j(0); j < n; ++j)
        cin >> cos[j];
    for(int i(0); i < n; ++i)
    {
        if(val[i] == 1)
            ans = MIN(ans, cos[i]);
        tmp.gcd = val[i];
        tmp.cost = cos[i];
        auto i1 = mas.find(tmp);
        if(i1 == mas.end())
            mas.insert(tmp);
        else if(i1->cost > tmp.cost)
        {
            mas.erase(i1);
            mas.insert(tmp);
        }
    }
    while(mas.size())
    {
        node t1 = *mas.begin();
        n = (0);
        mas.erase(mas.begin());
        for(auto it = mas.begin(); it != mas.end(); ++it)
        {
            val[n] = gcd(t1.gcd, it->gcd);
            cos[n] = t1.cost + it->cost;
            ++n;
        }
        for(int i(0); i < n; ++i)
        {
            if(val[i] == 1)
                ans = MIN(ans, cos[i]);
            tmp.gcd = val[i];
            tmp.cost = cos[i];
            auto i1 = mas.find(tmp);
            if(i1 == mas.end())
                mas.insert(tmp);
            else if(i1->cost > tmp.cost)
            {
                mas.erase(i1);
                mas.insert(tmp);
            }
        }
    }
    if(ans == MAXINT)
        cout << -1;
    else
        cout << ans;
    return 0;
}