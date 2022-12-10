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
    char ti;
    vector<int> edge;
};

node mas[256];
string now, bef;
char ans[256];
int n, pos(1);

bool dfs(char v)
{
    bool rval(0);
    mas[v].ti = 1;
    for (size_t i=0; i<mas[v].edge.size(); ++i) 
    {
        int to = mas[v].edge[i];
        if (!mas[to].ti)
            rval |= dfs (to);
        else if(mas[to].ti == 1)
            return 1;
    }
    mas[v].ti = 2;
    ans[pos] = v;
    ++pos;
    return rval;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> now;
    for(int i('a'); i <= 'z'; ++i)
        mas[i].ti = 0;
    for(int i(1); i < n; ++i)
    {
        bef = now;
        bool yep(0);
        cin >> now;
        for(int j(0), si = MIN(bef.size(), now.size()); j < si; ++j)
        {
            if(now[j] != bef[j])
            {
                mas[now[j]].edge.push_back(bef[j]);
                yep = 1;
                break;
            }
        }
        if(!yep && now.size() < bef.size())
        {
            cout << "Impossible";
            return 0;
        }
    }
    for(int i('a'); i <= 'z'; ++i)
    if(!mas[i].ti && dfs(i))
    {
        cout << "Impossible";
        return 0;
    }
    for(int i(1); i < 27; ++i)
        cout << ans[i];
    return 0;
}