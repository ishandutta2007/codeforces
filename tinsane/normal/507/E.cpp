#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
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
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

struct Edge
{
    int wh;
    bool rep;
} tmp;

struct Node
{
    int dist, mi, fw;
    vector<Edge> edges;

    Node() : dist(0), mi(MAXINT){}
    int size()
    {
        return edges.size();
    }
    void push(Edge v)
    {
        edges.push_back(v);
    }
    Edge operator[] (int v)
    {
        return edges[v];
    }
} mas[MAXN];

int n, m, a, c, wave[MAXN], wsi(1), asi(0), ax[MAXN], ay[MAXN], az[MAXN];

void init()
{
    cin >> n >> m;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> tmp.wh >> c;
        tmp.rep = c;
        mas[a].push(tmp);
        swap(a, tmp.wh);
        mas[a].push(tmp);
    }
    wave[0] = 1;
    mas[1].dist = 1;
    mas[1].fw = -1;
}

void solve()
{
    for(int i(0); i < wsi; ++i)
    {
        int v = wave[i];
        for(int j(0); j < mas[v].size(); ++j)
        if(!mas[mas[v][j].wh].dist)
        {
            wave[wsi++] = mas[v][j].wh;
            mas[mas[v][j].wh].fw = v;
            mas[mas[v][j].wh].mi = mas[v].mi + !mas[v][j].rep;
            mas[mas[v][j].wh].dist = mas[v].dist + 1;
        }
        else if(mas[mas[v][j].wh].dist == mas[v].dist + 1 && mas[mas[v][j].wh].mi > mas[v].mi + !mas[v][j].rep)
        {
            mas[mas[v][j].wh].mi = mas[v].mi + !mas[v][j].rep;
            mas[mas[v][j].wh].fw = v;
        }
    }
    for(int i(n), nex(-1); i > 1; nex = i, i = mas[i].fw)
    for(int j(0); j < mas[i].size(); ++j)
    if(mas[i][j].wh == mas[i].fw)
    {
        if(!mas[i][j].rep)
            ax[asi] = i, ay[asi] = mas[i].fw, az[asi++] = 1;
        mas[i].edges[j].rep = 0;
        break;
    }
    for(int i(mas[n].fw), nex(n); i > -1; nex = i, i = mas[i].fw)
    for(int j(0); j < mas[i].size(); ++j)
    if(mas[i][j].wh == nex)
    {
        mas[i].edges[j].rep = 0;
        break;
    }
    for(int i(1); i <= n; ++i)
    for(int j(0); j < mas[i].size(); ++j)
    if(mas[i][j].rep && mas[i][j].wh > i)
        ax[asi] = i, ay[asi] = mas[i][j].wh, az[asi++] = 0;
}

void output()
{
    cout << asi << '\n';
    for(int i(0); i < asi; ++i)
        cout << ax[i] << ' ' << ay[i] << ' ' << az[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}