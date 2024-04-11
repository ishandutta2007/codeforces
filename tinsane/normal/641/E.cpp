#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 1000500;
const int PLUS1 = (int)1e9;
const int MINUS1 = -(int)1e9;

struct FenTree
{
    int a[N];

    FenTree(): a() {}

    void add(int p, int val)
    {
        for (int i = p; i < N; i |= i + 1)
            a[i] += val;
    }

    int get(int p)
    {
        int s = 0;
        for (int i = p; i >= 0; i = (i & (i + 1)) - 1)
            s += a[i];
        return s;
    }
};

int n;
map<int, vector<pair<int, int>>> events;
int coord[N], sz;
FenTree fen;
int res[N];

void solve(const vector<pair<int, int>> &vec)
{
    for (auto e : vec)
    {
        int t = lower_bound(coord, coord + sz, e.first) - coord;
        int type = e.second;
        if (type == PLUS1)
            fen.add(t, 1);
        else if (type == MINUS1)
            fen.add(t, -1);
        else
            res[type] = fen.get(t);
    }

    for (auto e : vec)
    {
        int t = lower_bound(coord, coord + sz, e.first) - coord;
        int type = e.second;
        if (type == PLUS1)
            fen.add(t, -1);
        else if (type == MINUS1)
            fen.add(t, 1);
    }
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, t, x;
        scanf("%d%d%d", &a, &t, &x);
        coord[sz++] = t;
        if (a == 1)
            events[x].emplace_back(t, PLUS1);
        if (a == 2)
            events[x].emplace_back(t, MINUS1);
        if (a == 3)
            events[x].emplace_back(t, i);
    }

    sort(coord, coord + sz);
    sz = unique(coord, coord + sz) - coord;

    memset(res, -1, sizeof(res));
    for (auto e : events)
        solve(e.second);

    for (int i = 0; i < n; i++)
        if (res[i] != -1)
            printf("%d\n", res[i]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}