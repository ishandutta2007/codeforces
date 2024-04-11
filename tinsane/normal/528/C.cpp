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

struct ver
{
    int st;
    bool was;
    vector<int> edges;
};

struct edge
{
    int x, y;
    char fx;
};
    int n, m, x, y;
    vector<int> odd;
    ver mas[100001];
    vector<edge> g;
    edge tmp;

pair<int, int> cnt(int v)
{
    int in(0), out(0);
    for(int i(0); i < mas[v].edges.size(); ++i)
    {
        if(g[mas[v].edges[i]].x == v)
            if(g[mas[v].edges[i]].y == v)
                ++in, ++out;
            else if(g[mas[v].edges[i]].fx)
                ++out;
            else
                ++in;
        else
            if(g[mas[v].edges[i]].fx)
                ++in;
            else
                ++out;
    }
    return make_pair(in, out);
}

bool dfs(int v, int num)
{
    if(mas[v].was)
        return 0;
    mas[v].was = 1;
    pair<int, int> win;
    win = cnt(v);
    bool rev;
    rev = win.first & 1;
    for(int i(0); i < mas[v].edges.size(); ++i)
    {
        rev ^= dfs(g[mas[v].edges[i]].x, mas[v].edges[i]);
        rev ^= dfs(g[mas[v].edges[i]].y, mas[v].edges[i]);
    }
    if(rev)
        g[num].fx = !g[num].fx;
    return rev;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    ++n;
    g.resize(m);
    for(int i(0); i < m; ++i)
    {
        cin >> g[i].x >> g[i].y;
        g[i].fx = 0;
        if(g[i].x != g[i].y)
        {
            mas[g[i].x].edges.push_back(i);
            mas[g[i].y].edges.push_back(i);
            ++mas[g[i].x].st;
            ++mas[g[i].y].st;
        }
        else mas[g[i].y].edges.push_back(i);
    }
    for(int i(1); i < n; ++i)
    {
        mas[i].was = 0;
        if(mas[i].st & 1)
            odd.push_back(i);
    }
    for(int i(0); i < odd.size(); i += 2)
    {
        tmp.x = odd[i];
        tmp.y = odd[i + 1];
        tmp.fx = 0;
        g.push_back(tmp);
        mas[tmp.x].edges.push_back(g.size() - 1);
        mas[tmp.y].edges.push_back(g.size() - 1);
    }
    dfs(1, mas[1].edges[0]);
    for(int i(1); i < n; ++i)
    {
        mas[i].was = 0;
        if(cnt(i).first & 1)
        {
            tmp.x = tmp.y = i;
            g.push_back(tmp);
            mas[i].edges.push_back(g.size() - 1);
        }
    }
    dfs(1, mas[1].edges[0]);
    cout << g.size() << '\n';
    for(int i(0); i < g.size(); ++i)
        if(g[i].fx)
            cout << g[i].x << ' ' << g[i].y << endl;
        else
            cout << g[i].y << ' ' << g[i].x << endl;
    return 0;
}