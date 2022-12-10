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
const int MAXN = 1e6 + 10;

struct otr
{
    int l, r;
};

struct comp
{
    bool operator() (otr f, otr s)
    {
        return f.r < s.r;
    }
};

int n, m, k, a, res(-1), cnt, x;
otr tmp, lef, ri;
set<otr, comp> mas;
set<otr, comp>::iterator it;

void init()
{
    cin >> n >> k >> a >> m;
    cnt = (n + 1) / (a + 1);
    tmp.l = 1;
    tmp.r = n;
    mas.insert(tmp);
}

void solve()
{
    for(int i(0); i < m; ++i)
    {
        cin >> x;
        tmp.l = tmp.r = x;
        it = mas.lower_bound(tmp);
        tmp = *it;
        mas.erase(it);
        cnt -= (tmp.r - tmp.l + 2) / (a + 1);
        lef.l = tmp.l, lef.r = x - 1;
        ri.l = x + 1, ri.r = tmp.r;
        if(x != lef.l)
        {
            cnt += (lef.r - lef.l + 2) / (a + 1);
            mas.insert(lef);
        }
        if(x != ri.r)
        {
            cnt += (ri.r - ri.l + 2) / (a + 1);
            mas.insert(ri);
        }
        if(cnt < k)
        {
            res = i + 1;
            return;
        }
    }
}

void output()
{
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}