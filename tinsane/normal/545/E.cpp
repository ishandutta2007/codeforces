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

struct edge
{
    long long wei;
    int wh, num;
};
struct ver
{
    long long wei;
    vector<edge> edges;
} mas[300000];
struct sm
{
    int num;
    long long wei;
};
struct comp
{
    bool operator() (const sm& l, const sm& r)
    {
        return (l.wei != r.wei ? l.wei < r.wei : l.num < r.num);
    }
};

/*bool comp(const sm l, const sm r)
{
    return (l.wei != r.wei ? l.wei < r.wei : l.num < r.num);
}*/
set<sm, comp> dp;
int n, m, u, a, mn;
vector<int> ans;
long long mw, res(0);
edge t;
sm tmp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> t.wh >> t.wei;
        t.num = i + 1;
        --a, --t.wh;
        mas[a].edges.push_back(t);
        swap(t.wh, a);
        mas[a].edges.push_back(t);
    }
    tmp.wei = MAXLL;
    for(int i(0); i < n; ++i)
    {
        mas[i].wei = MAXLL;
        tmp.num = i;
        dp.insert(tmp);
    }
    cin >> u;
    --u;
    tmp.num = u;
    dp.erase(dp.find(tmp));
    mas[u].wei = 0;
    for(int i(0); i < mas[u].edges.size(); ++i)
    {
        int to = mas[u].edges[i].wh;
        mas[to].wei = mas[u].edges[i].wei;
        tmp.num = to;
        tmp.wei = MAXLL;
        dp.erase(dp.find(tmp));
        tmp.wei = mas[to].wei;
        dp.insert(tmp);
    }
    while(dp.size())
    {
        a = dp.begin()->num;
        mw = MAXLL;
        dp.erase(dp.begin());
        for(int i(0); i < mas[a].edges.size(); ++i)
        {
            int to = mas[a].edges[i].wh;
            if(mas[to].wei > mas[a].wei + mas[a].edges[i].wei)
            {
                tmp.num = to;
                tmp.wei = mas[to].wei;
                dp.erase(dp.find(tmp));
                tmp.wei = mas[to].wei = mas[a].wei + mas[a].edges[i].wei;
                dp.insert(tmp);
            }
            else if(mas[to].wei + mas[a].edges[i].wei == mas[a].wei)
            if(mas[a].edges[i].wei < mw)
            {
                mw = mas[a].edges[i].wei;
                mn = mas[a].edges[i].num;
            }
        }
        res += mw;
        ans.push_back(mn);
    }
    cout << res << '\n';
    for(int i(0); i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}