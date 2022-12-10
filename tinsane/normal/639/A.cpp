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

const int N = 200500;
const int K = 10;

int n, k, q;
int lvl[N];
int mx[K];
int sz;

void add(int id)
{
    bool added = false;
    for (int i = 0; i < sz; i++)
        if (lvl[mx[i]] < lvl[id])
        {
            for (int j = sz; j > i; j--)
                mx[j] = mx[j - 1];
            mx[i] = id;
            sz++;
            added = true;
            break;
        }
    if (!added)
        mx[sz++] = id;
    while (sz > k)
        sz--;
}

bool query(int id)
{
    for (int i = 0; i < sz; i++)
        if (mx[i] == id)
            return true;
    return false;
}

void solve()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &lvl[i]);

    for (int i = 0; i < q; i++)
    {
        int type, id;
        scanf("%d%d", &type, &id);
        id--;
        if (type == 1)
            add(id);
        else
            puts(query(id) ? "YES" : "NO");
    }
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