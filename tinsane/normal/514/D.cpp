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

struct node
{
    int num, cou;

    node(int num, int cou) : num(num), cou(cou){};
};

struct comp
{
    bool operator() (const node& l, const node& r)
    {
        return l.cou < r.cou;
    }
};
priority_queue<node, vector<node>, comp> win[5];
int n, m, k, mas[5][100000];

bool go(int len)
{
    int mink = MAXINT, tmp;
    for(int i(0); i < len; ++i)
    for(int j(0); j < m; ++j)
        win[j].push(node(i, mas[j][i]));
    tmp = 0;
    for(int j(0); j < m; ++j)
        tmp += win[j].top().cou;
    mink = MIN(mink, tmp);
    for(int i(len); i < n; ++i)
    {
        for(int j(0); j < m; ++j)
        {
            win[j].push(node(i, mas[j][i]));
            for(;win[j].top().num <= i - len; win[j].pop());
        }
        tmp = 0;
        for(int j(0); j < m; ++j)
            tmp += win[j].top().cou;
        mink = MIN(mink, tmp);
    }
    for(int j(0); j < m; ++j)
        for(;win[j].size();win[j].pop());
    if(mink <= k)
        return 1;
    else
        return 0;
}

int bins(int l, int r)
{
    if(l == r)
        return l;
    if(l == r - 1)
        if(go(r))
            return r;
        else
            return l;
    int mid = (l + r) / 2 + 1;
    if(go(mid))
        return bins(mid, r);
    else
        return bins(l, mid - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int len, mins(MAXINT), tmp;
    cin >> n >> m >> k;
    for(int i(0); i < n; ++i)
    {
        tmp = 0;
        for(int j(0); j < m; ++j)
        {
            cin >> mas[j][i];
            tmp += mas[j][i];
        }
        mins = MIN(tmp, mins);
    }
    if(mins > k)
    {
        for(int i(0); i < m; ++i)
            cout << "0 ";
        return 0;
    }
    len = bins(1, n);
    int mink = MAXINT;
    for(int i(0); i < len; ++i)
    for(int j(0); j < m; ++j)
        win[j].push(node(i, mas[j][i]));
    tmp = 0;
    for(int j(0); j < m; ++j)
        tmp += win[j].top().cou;
    mink = MIN(mink, tmp);
    if(mink <= k)
    {
        for(int j(0); j < m; ++j)
            cout << win[j].top().cou << ' ';
        return 0;
    }
    for(int i(len); i < n; ++i)
    {
        for(int j(0); j < m; ++j)
        {
            win[j].push(node(i, mas[j][i]));
            for(;win[j].top().num <= i - len; win[j].pop());
        }
        tmp = 0;
        for(int j(0); j < m; ++j)
            tmp += win[j].top().cou;
        mink = MIN(mink, tmp);
        if(mink <= k)
        {
            for(int j(0); j < m; ++j)
                cout << win[j].top().cou << ' ';
            return 0;
        }
    }

    return 0;
}