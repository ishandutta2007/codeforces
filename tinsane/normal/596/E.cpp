#define _CRT_SECURE_NO_WARNINGS
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
#include <bitset>
#include <cassert>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

#ifdef MEM_EXT
const int MMEM = 6e7;
int cmem = 0;
char mem[MMEM];
void * operator new (size_t n)
{
    return (void*)(mem + ((cmem += n) - n));
}
void operator delete (void*) {}
#endif

const double PI = 3.1415926535897932384626433;
const int MODUL = 1000000007;
const int MAXINT = 1e9 + 2;
const ll MAXLL = 2e18 + 2;
const double eps = 1e-9;

struct Cage
{
    char fig;
    bool beg, incyc;
    int cyc;
};

const int N = 201;
const int M = 201;
const int ALP = 10;
const int S = 1e6 + 10;
int n, m, q, now, dx[ALP], dy[ALP], curcyc, cont[S];
bool incyc;
string s;
Cage mas[N][M];
vector<int> cycles;

bool correct(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int dfs(int x, int y)
{
    if (mas[x][y].cyc != -1)
    {
        if (mas[x][y].cyc != now)
            mas[x][y].beg = 0;
        else
        {
            incyc = mas[x][y].incyc = 1;
            curcyc |= 1 << mas[x][y].fig;
        }
        return mas[x][y].cyc;
    }
    mas[x][y].cyc = now;
    if (correct(x + dx[mas[x][y].fig], y + dy[mas[x][y].fig]))
        mas[x][y].cyc = dfs(x + dx[mas[x][y].fig], y + dy[mas[x][y].fig]);
    else
    {
        mas[x][y].incyc = 1;
        curcyc = 1 << mas[x][y].fig;
    }
    if (mas[x][y].incyc)
        incyc = 0;
    else if (incyc)
    {
        mas[x][y].incyc = 1;
        curcyc |= 1 << mas[x][y].fig;
    }
    return mas[x][y].cyc;
}

void init()
{
    cin >> n >> m >> q;
    for (int i(0); i < n; ++i)
        for (int j(0); j < m; ++j)
            cin >> mas[i][j].fig, mas[i][j].cyc = -1, mas[i][j].fig -= '0';
    for (int i(0); i < ALP; ++i)
        cin >> dx[i] >> dy[i];
    for (int i(0); i < n; ++i)
    for (int j(0); j < m; ++j)
    if (mas[i][j].cyc == -1)
    {
        incyc = 0;
        mas[i][j].beg = 1;
        curcyc = 0;
        dfs(i, j);
        ++now;
        cycles.push_back(curcyc);
    }
}

bool check(int x, int y)
{
    if (now == s.size())
        return 1;
    if (!correct(x, y))
        return 0;
    if (mas[x][y].incyc)
        return ((cont[now] & cycles[mas[x][y].cyc]) == cont[now]);
    if (mas[x][y].fig == s[now])
        ++now;
    return check(x + dx[mas[x][y].fig], y + dy[mas[x][y].fig]);
}

void solve()
{
    while (q--)
    {
        bool ans = 0;
        cin >> s;
        for (int i(0); i < s.size(); ++i)
            s[i] -= '0';
        cont[s.size()] = 0;
        for (int i(s.size() - 1); i >= 0; --i)
            cont[i] = cont[i + 1] | (1 << s[i]);
        for (int i(0); i < n; ++i)
        for (int j(0); j < m; ++j)
        if (mas[i][j].beg)
        {
            now = 0;
            ans |= check(i, j);
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

void output()
{

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}