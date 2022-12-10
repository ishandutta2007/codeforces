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

int comp(const void* a, const void* b)
{
    pair<int,int> *f((pair<int,int> *)a), *s((pair<int,int> *)b);
    if(f->first - s->first)
        return f->first - s->first;
    else
        return f->second - s->second;
}

int main()
{
    vector<pair<int, int>> ans;
    int n, y[2][100000], d[2][200001];
    char c;
    cin >> n;
    cin >> c;
    for(int i(0); i < 200001; ++i)
        d[0][i] = d[1][i] = MAXINT;
    y[0][0] = y[1][0] = 0;
    ++y[c - '1'][0];
    d[c - '1'][1] = 1;
    d[0][0] = d[1][0] = 0;
    for(int i(1); i < n; ++i)
    {
        y[0][i] = y[0][i - 1];
        y[1][i] = y[1][i - 1];
        cin >> c;
        ++y[c - '1'][i];
        d[c - '1'][y[c - '1'][i]] = i + 1;
    }
    for(int i(1); i <= y[c - '1'][n - 1]; ++i)
    {
        int lasts = 0, l[2], sc = 0, res = 0;
        l[0] = l[1] = 0;
        while(1)
        {
            lasts = MIN(d[0][l[0] + i], d[1][l[1] + i]);
            if(lasts == MAXINT)
                break;
            if(y[c - '1'][lasts - 1] == l[c - '1'] + i)
                ++res;
            ++sc;
            l[0] = y[0][lasts - 1];
            l[1] = y[1][lasts - 1];
        }
        if(res * 2 > sc && l[c - '1'] == y[c - '1'][n - 1])
            ans.push_back(make_pair(res, i));
    }
    if(ans.size())
    {
    qsort(&ans[0], ans.size(),sizeof(pair<int,int>), comp);
    cout << ans.size() << '\n';
    for(int i(0); i < ans.size(); cout << ans[i].first << ' ' << ans[i].second << '\n', ++i);
    }
    else cout << 0;
    return 0;
}