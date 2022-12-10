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

int n, t, x, mas[301], anc[301], ran[300];

int get(int v)
{
    return (v == anc[v] ? v : anc[v] = get(anc[v]));
}

void unite(int v, int k)
{
    v = get(v);
    k = get(k);
    if(v == k)
        return;
    if(ran[v] < ran[k])
        swap(v, k);
    anc[k] = v;
    ran[v] += ran[k];
}

int main()
{
    vector<int> em;
    vector<vector<int>> qs1, qs2;
    char c;
    cin >> n;
    ++n;
    for(int i(1); i < n; ++i)
    {
        cin >> mas[i];
        anc[i] = i;
        ran[i] = 1;
    }
    for(int i(1); i < n; ++i)
    {
        for(int j(1); j < n; ++j)
        {
            cin >> c;
            if(c == '1')
                unite(i, j);
        }
    }
    for(int i(1); i < n; ++i)
    {
        int s = get(i), t(-1);
        for(int j(0); j < qs1.size(); ++j)
        if(qs1[j][0] == s)
        {
            t = j;
            break;
        };
        if(t == -1)
        {
            qs1.push_back(em);
            qs2.push_back(em);
            qs1.back().push_back(s);
            qs2.back().push_back(mas[s]);
            if(s != i)
            {
                qs1.back().push_back(i);
                qs2.back().push_back(mas[i]);
            }
            continue;
        }
        if(s == i)
            continue;
        qs1[t].push_back(i);
        qs2[t].push_back(mas[i]);
    }
    for(int i(0); i < qs1.size(); ++i)
    {
        sort(qs1[i].begin(), qs1[i].end());
        sort(qs2[i].begin(), qs2[i].end());
        for(int j(0); j < qs1[i].size(); ++j)
            mas[qs1[i][j]] = qs2[i][j];
    }
    for(int i(1); i < n; ++i)
        cout << mas[i] << ' ';
    return 0;
}