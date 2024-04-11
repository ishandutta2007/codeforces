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

#pragma comment(linker, "/STACK:1677721600")

struct otr
{
    long long f, l;
};

struct comp
{
    bool operator() (otr& f, otr& s)
    {
        return f.f < s.f;
    }
};

struct que
{
    char c;
    long long v;
};

int main()
{
    ios_base::sync_with_stdio(0);
    set<long long> x, y;
    stack<long long> ans;
    long long n, s, h, w, tmp;
    que mas[200000];
    cin >> h >> w >> n;
    x.insert(0);
    x.insert(w);
    y.insert(0);
    y.insert(h);
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i].c >> mas[i].v;
        if(mas[i].c == 'V')
            y.insert(mas[i].v);
        else
            x.insert(mas[i].v);
    }
    s = 0;
    w = 0;
    h = 0;
    auto it = x.begin(), it1 = x.begin();
    ++it1;
    for(; it1 != x.end(); ++it1, ++it)
        w = MAX(w, (*it1) - (*it));
    it = y.begin();
    it1 = y.begin();
    ++it1;
    for(; it1 != y.end(); ++it1, ++it)
        h = MAX(h, (*it1) - (*it));
    s = w * h;
    ans.push(s);
    for(int i(n - 1); i > 0; --i)
    {
        if(mas[i].c == 'V')
        {
            tmp = mas[i].v;
            it = y.find(tmp);
            --it;
            y.erase(y.find(tmp));
            it1 = it;
            ++it1;
            if(it1 != y.end())
                h = MAX(h, (*it1) - (*it));
        }
        else
        {
            tmp = mas[i].v;
            it = x.find(tmp);
            --it;
            x.erase(x.find(tmp));
            it1 = it;
            ++it1;
            if(it1 != x.end())
                w = MAX(w, (*it1) - (*it));
        }
        s = h * w;
        ans.push(s);
    }
    for(;ans.size(); cout << ans.top() << ' ', ans.pop());
    return 0;
}