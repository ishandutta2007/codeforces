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
int n, m, s;
char mas[2002][2002];
bool dfs1(int, int);
//bool dfs(int, int, int&, int&);
//bool move(int, int, int&, int&);
bool move1(int, int, int&, int&);

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    ++n, ++m;
    for(int i(1); i < n; ++i)
    for(int j(1); j < m; ++j)
        cin >> mas[i][j];
    for(int i(0); i <= n; ++i)
        mas[i][0] = mas[i][m] = '*';
    for(int i(0); i <= m; ++i)
        mas[0][i] = mas[n][i] = '*';
    /*for(int i(1); i < n; ++i)
    for(int j(1); j < m; ++j)
    if(mas[i][j] == '.')
    {
        s = 0;
        int st = 0;
        st += (mas[i + 1][j] == ';');
        st += (mas[i - 1][j] == ';');
        st += (mas[i][j + 1] == ';');
        st += (mas[i][j - 1] == ';');
        if(st == 1 && (dfs(i, j, n, m) || (s & 1)))
        {
            cout << "Not unique";
            return 0;
        }
    }*/
    for(int i(1); i < n; ++i)
    for(int j(1); j < m; ++j)
    if(dfs1(i, j))
    {
        cout << "Not unique";
        return 0;
    }
    for(int i(1); i < n; ++i)
    for(int j(1); j < m; ++j)
    if(mas[i][j] == '.')
    {
        cout << "Not unique";
        return 0;
    }
    for(int i(1); i < n; ++i, cout << '\n')
    for(int j(1); j < m; ++j)
        cout << mas[i][j];
    return 0;
}

bool move1(int x, int y, int& fx, int& fy)
{
    if(mas[x][y] != '.')
        return 0;
    if(x == fx - 1)
    {
        mas[x][y] = '^';
        mas[fx][fy] = 'v';
    }
    else if(x == fx + 1)
    {
        mas[x][y] = 'v';
        mas[fx][fy] = '^';
    }
    else if(y == fy - 1)
    {
        mas[x][y] = '<';
        mas[fx][fy] = '>';
    }
    else
    {
        mas[x][y] = '>';
        mas[fx][fy] = '<';
    }
    return (dfs1(x + 1, y) ||
        dfs1(x - 1, y) ||
        dfs1(x, y + 1) ||
        dfs1(x, y - 1));
}

bool dfs1(int x, int y)
{
    if(mas[x][y] != '.')
        return 0;
    int st = 0;
    st += (mas[x + 1][y] == '.');
    st += (mas[x - 1][y] == '.');
    st += (mas[x][y + 1] == '.');
    st += (mas[x][y - 1] == '.');
    if(st == 0)
        return 1;
    if(st != 1)
        return 0;
    return (move1(x + 1, y, x, y) || 
        move1(x - 1, y, x, y) || 
        move1(x, y + 1, x, y) || 
        move1(x, y - 1, x, y));
}

/*
bool move(int x, int y, int& fx, int& fy)
{
    if(mas[x][y] == '*')
        return 0;
    if(mas[x][y] == ',')
        return 1;
    if(mas[x][y] == '.')
        return dfs(x, y, fx, fy);
    return 0;
}

bool dfs(int x, int y, int& fx, int& fy)
{
    ++s;
    bool res = 0;
    mas[x][y] = ',';
    if(fx != x + 1)
        res |= move(x + 1, y, x, y);
    if(fx != x - 1)
        res |= move(x - 1, y, x, y);
    if(fy != y + 1)
        res |= move(x, y + 1, x, y);
    if(fy != y - 1)
        res |= move(x, y - 1, x, y);
    mas[x][y] = ';';
    return res;
}*/