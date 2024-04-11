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
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

struct ye
{
    long long v, n;
    int fw;
} tmp;

struct cit
{
    int esi, bad, fbad;
    bool t;
    vector<int> edges;
} mas[MAXN];

struct comp
{
    bool operator() (const ye& f, const ye& s)
    {
        return (f.v * s.n != f.n * s.v ? f.v * s.n > f.n * s.v : f.fw < s.fw);
    }
};

int n, m, k, a, b, ansi, wsi, wave[MAXN], lol;
long long ansv(1), ansn(1);
set<ye, comp> win;
set<ye,  comp>::iterator it;

void woans()
{
    while(win.size())
    {
        if(ansn * win.begin()->v < ansv * win.begin()->n)
        {
            ansv = win.begin()->v;
            ansn = win.begin()->n;
            ansi = win.begin()->fw;
        }
        a = win.begin()->fw;
        win.erase(win.begin());
        for(int i(0); i < mas[a].edges.size(); ++i)
        {
            int to = mas[a].edges[i];
            tmp.fw = to;
            tmp.v = mas[to].bad;
            tmp.n = mas[to].esi;
            if(win.find(tmp) != win.end())
            {
                win.erase(tmp);
                ++tmp.v;
                win.insert(tmp);
            }
            ++mas[mas[a].edges[i]].bad;
        }
    }
}

void wans()
{
    while(win.size())
    {
        if(ansi == win.begin()->fw)
        {
            it = win.begin();
            cout << win.size() << '\n';
            for(;it != win.end(); ++it)
                cout << it->fw + 1 << ' ';
            return;
        }
        a = win.begin()->fw;
        win.erase(win.begin());
        for(int i(0); i < mas[a].edges.size(); ++i)
        {
            int to = mas[a].edges[i];
            tmp.fw = to;
            tmp.v = mas[to].bad;
            tmp.n = mas[to].esi;
            if(win.find(tmp) != win.end())
            {
                win.erase(tmp);
                ++tmp.v;
                win.insert(tmp);
            }
            ++mas[mas[a].edges[i]].bad;
        }
    }
}

void bfs(int v, bool go)
{
    wsi = 1;
    lol = wave[0] = v;
    mas[v].t = !go;
    for(int i(0); i < wsi; ++i)
    {
        tmp.v = mas[wave[i]].bad;
        tmp.n = mas[wave[i]].esi;
        tmp.fw = wave[i];
        win.insert(tmp);
        for(int j(0); j < mas[wave[i]].edges.size(); ++j)
        {
            int to = mas[wave[i]].edges[j];
            if(mas[to].t == go)
            {
                mas[to].t = !go;
                wave[wsi++] = to;
            }
        }
    }
    if(go)
        wans();
    else
        woans();
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i(0); i < n; ++i)
        mas[i].bad = mas[i].esi = mas[i].t = 0;
    cin >> k;
    for(int i(0); i < k; ++i)
        cin >> a, mas[--a].t = 1;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> b;
        --a, --b;
        ++mas[a].esi, ++mas[b].esi;
        if(mas[a].t)
            ++mas[b].bad;
        else
            mas[b].edges.push_back(a);
        if(mas[b].t)
            ++mas[a].bad;
        else
            mas[a].edges.push_back(b);
    }
    for(int i(0); i < n; ++i)
        mas[i].fbad = mas[i].bad;
    for(int i(0); i < n; ++i)
    if(!mas[i].t)
        bfs(i, 0);
    for(int i(0); i < n; ++i)
        mas[i].bad = mas[i].fbad;
    if(ansv == 1 && ansn == 1)
        cout << "1\n" << lol + 1;
    else
        bfs(ansi, 1);
    return 0;
}