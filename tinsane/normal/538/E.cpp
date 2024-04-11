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
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 5e4 + 10;

struct ver
{
    int h, si;
    vector<int> edges;
};

int n, x, y, m(0);
ver mas[200000];

void hi(int v, int h)
{
    if(h & 1)
        mas[v].si = MAXINT;
    else
        mas[v].si = 0;
    int cnt(0);
    mas[v].h = h;
    for(int i(0); i < mas[v].edges.size(); ++i)
    if(mas[mas[v].edges[i]].h == -1)
    {
        hi(mas[v].edges[i], h + 1);
        ++cnt;
        if(h & 1)
            mas[v].si = min(mas[v].si, mas[mas[v].edges[i]].si);
        else
            mas[v].si += mas[mas[v].edges[i]].si;
    }
    if(!cnt)
        mas[v].si = 1, ++m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i(1); i < n; ++i)
    {
        cin >> x >> y;
        --x, --y;
        mas[x].edges.push_back(y);
        mas[y].edges.push_back(x);
        mas[i].h = -1;
    }
    mas[0].h = 1;
    hi(0, 1);
    cout << m - mas[0].si + 1 << ' ';
    m = 0;
    for(int i(0); i < n; ++i)
        mas[i].h = -1;
    hi(0, 0);
    cout << mas[0].si;
    return 0;
}