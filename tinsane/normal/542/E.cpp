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
const int MAXN = 5e5 + 10;

struct ver
{
    int h, com;
    vector<int> edges;
};
ver mas[1000], mas1[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    int ans(-1), n, m, a, b, wave[1000], wsi(1), ma, csi(0), loc(0), n1;
    bool f;
    cin >> n >> m;
    for(int i(0); i < m; ++i)
    {
        cin >> a >> b;
        --a, --b;
        mas1[a].edges.push_back(b);
        mas1[b].edges.push_back(a);
    }
    for(int i(0); i < n; ++i)
        mas1[i].com = -1;

    for(int t(0); t < n; ++t)
    if(mas1[t].com == -1)
    {
        mas1[t].com = csi;
        wave[0] = t;
        wsi = 1;
        for(int i(0); i < wsi; ++i)
        {
            int fw = wave[i], to;
            for(int j(0); j < mas1[fw].edges.size(); ++j)
            {
                to = mas1[fw].edges[j];
                if(mas1[to].com == -1)
                    mas1[to].com = csi, wave[wsi++] = to;
            }
        }
        ++csi;
    }

    n1 = n;
    for(int k(0); k < csi; ++k)
    {
    ans = -1;
        for(int i(0); i < n1; ++i)
        if(mas1[i].com == k)
            mas[i] = mas1[i];
        else
            mas[i].com = -1;
        for(int t(0); t < n; ++t)
        {
            if(mas[t].com == -1)
                continue;
            ma = f = 0;
            for(int i(0); i < n; ++i)
                mas[i].h = -1;
            mas[t].h = 0;
            wave[0] = t;
            wsi = 1;
            for(int i(0); i < wsi && !f; ++i)
            {
                int fw = wave[i], to;
                for(int j(0); j < mas[fw].edges.size(); ++j)
                {
                    to = mas[fw].edges[j];
                    if(mas[to].h == mas[fw].h)
                    {
                        f = 1;
                        break;
                    }
                    if(mas[to].h == -1)
                    {
                        mas[to].h = mas[fw].h + 1;
                        wave[wsi++] = to;
                        ma = max(ma, mas[to].h);
                    }
                }
            }
            if(!f)
                ans = max(ans, ma);
        }
        if(ans == -1)
        {
            cout << -1;
            return 0;
        }
        loc += ans;
    }
    cout << loc;
    return 0;
}