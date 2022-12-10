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
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 3e3 + 10;

struct ver
{
    int s1d, s2d, t1d, t2d, d, mt1, mt2, ms1, ms2;
    vector<int> edges;
};

ver mas[MAXN];
int n, m, s1, s2, t1, t2, l1, l2, a, b, wave[3000], wsi, ans(MAXINT), fw, to;

void tr(int to)
{
    if(mas[to].d + mas[to].ms1 + mas[to].mt1 <= l1 && mas[to].d + mas[to].ms2 + mas[to].mt2 <= l2)
        ans = min(ans, mas[to].d + mas[to].ms1 + mas[to].mt1 + mas[to].ms2 + mas[to].mt2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> b;
        --a, --b;
        mas[a].edges.push_back(b);
        mas[b].edges.push_back(a);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    --s1, --s2, --t1, --t2;
    for(int i(0); i < n; ++i)
        mas[i].s1d = mas[i].s2d = mas[i].t1d = mas[i].t2d = -1;
    mas[s1].s1d = 0;
    wave[0] = s1;
    wsi = 1;
    for(int i(0); i < wsi; ++i)
    {
        fw = wave[i];
        for(int j(0); j < mas[fw].edges.size(); ++j)
        {
            to = mas[fw].edges[j];
            if(mas[to].s1d == -1)
            {
                mas[to].s1d = mas[fw].s1d + 1;
                wave[wsi++] = to;
            }
        }
    }
    mas[s2].s2d = 0;
    wave[0] = s2;
    wsi = 1;
    for(int i(0); i < wsi; ++i)
    {
        fw = wave[i];
        for(int j(0); j < mas[fw].edges.size(); ++j)
        {
            to = mas[fw].edges[j];
            if(mas[to].s2d == -1)
            {
                mas[to].s2d = mas[fw].s2d + 1;
                wave[wsi++] = to;
            }
        }
    }
    
    mas[t1].t1d = 0;
    wave[0] = t1;
    wsi = 1;
    for(int i(0); i < wsi; ++i)
    {
        fw = wave[i];
        for(int j(0); j < mas[fw].edges.size(); ++j)
        {
            to = mas[fw].edges[j];
            if(mas[to].t1d == -1)
            {
                mas[to].t1d = mas[fw].t1d + 1;
                wave[wsi++] = to;
            }
        }
    }
    
    mas[t2].t2d = 0;
    wave[0] = t2;
    wsi = 1;
    for(int i(0); i < wsi; ++i)
    {
        fw = wave[i];
        for(int j(0); j < mas[fw].edges.size(); ++j)
        {
            to = mas[fw].edges[j];
            if(mas[to].t2d == -1)
            {
                mas[to].t2d = mas[fw].t2d + 1;
                wave[wsi++] = to;
            }
        }
    }

    if(mas[t1].s1d > l1 || mas[t2].s2d > l2)
    {
        cout << -1;
        return 0;
    }
    ans = mas[t1].s1d + mas[t2].s2d;

    for(int k(0); k < n; ++k)
    {
        for(int i(0); i < n; ++i)
            mas[i].d = -1, mas[i].ms1 = mas[i].s1d, mas[i].ms2 = mas[i].s2d, mas[i].mt1 = mas[i].t1d, mas[i].mt2 = mas[i].t2d;
        mas[k].d = 0;
        wsi = 1;
        wave[0] = k;
        for(int i(0); i < wsi; ++i)
        {
            fw = wave[i];
            tr(fw);
            for(int j(0); j < mas[fw].edges.size(); ++j)
            {
                to = mas[fw].edges[j];
                if(mas[to].d == -1)
                {
                    mas[to].d = mas[fw].d + 1;
                    wave[wsi++] = to;
                    mas[to].ms1 = min(mas[to].ms1, mas[fw].ms1);
                    mas[to].ms2 = min(mas[to].ms2, mas[fw].ms2);
                    mas[to].mt1 = min(mas[to].mt1, mas[fw].mt1);
                    mas[to].mt2 = min(mas[to].mt2, mas[fw].mt2);
                }
            }
        }
    }


    cout << m - ans;
    return 0;
}