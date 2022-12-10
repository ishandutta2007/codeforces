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
    bool used;
    int mt, val, fw;
    vector<int> edge;
};
node mas[200];
int n, c(0), nc(0);

bool kuhn(int v)
{
    if(mas[v].used)
        return 0;
    mas[v].used = 1;
    for(int i(0); i < mas[v].edge.size(); ++i)
    {
        int to = mas[v].edge[i];
        if(mas[to].mt == -1 || kuhn(mas[to].mt))
        {
            mas[to].mt = v;
            return 1;
        }
    }
    return 0;
}

bool kuhn2(int v)
{
    if(mas[v].used)
        return 0;
    mas[v].used = 1;
    for(int i(0); i < mas[v].edge.size(); ++i)
    {
        int to = mas[v].edge[i];
        if(to == mas[v].mt)
            continue;
        if(mas[to].fw == -1 || kuhn2(mas[to].fw))
        {
            mas[to].fw = v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    set<int> dev;
    bool prost[20001];
    for(int i(0); i < 20000; ++i)
        prost[i] = 1;
    for(int i(2); i < 20000; ++i)
    if(prost[i])
    {
        dev.insert(i);
        for(int j(2); j * i < 20000; ++j)
            prost[j * i] = 0;
    }
    cin >> n;
    for(int i(0); i < n; ++i)
    {
        cin >> mas[i].val;
        mas[i].fw = mas[i].mt = -1;
        if(mas[i].val & 1)
            ++nc;
        else
            ++c;
        for(int j(0); j < i; ++j)
        {
            if(dev.find(mas[i].val + mas[j].val) != dev.end())
            {
                mas[i].edge.push_back(j);
                mas[j].edge.push_back(i);
            }
        }
    }
    if(c != nc)
    {
        cout << "Impossible";
        return 0;
    }
    for(int i(0); i < n; ++i)
    {
        for(int j(0); j < n; ++j)
            mas[j].used = 0;
        kuhn(i);
    }
    for(int i(0); i < n; ++i)
    {
        for(int j(0); j < n; ++j)
            mas[j].used = 0;
        kuhn2(i);
    }
    for(int i(0); i < n; ++i)
    if(mas[i].mt == -1 || mas[i].fw == -1)
    {
        cout << "Impossible";
        return 0;
    };
    for(int i(0); i < n; ++i)
        mas[i].used = 0;
    vector<stack<int>> win;
    stack<int> em;
    for(int i(0); i < n; ++i)
    {
        if(!mas[i].used && mas[i].val & 1)
        {
            win.push_back(em);
            int beg = i;
            mas[i].used = 1;
            win.back().push(beg);
            for(int j(mas[beg].mt), k(0); j != beg; ++k)
            {
                mas[j].used = 1;
                win.back().push(j);
                if(!(k & 1))
                    j = mas[j].fw;
                else
                    j = mas[j].mt;
            }
        }
    }
    cout << win.size() << '\n';
    for(int i(0); i < win.size(); ++i)
    {
            cout << win[i].size() << ' ';
            for(; win[i].size(); cout << win[i].top() + 1 << ' ', win[i].pop());
            cout << '\n';
    }
    return 0;
}