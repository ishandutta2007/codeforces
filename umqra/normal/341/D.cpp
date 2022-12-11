#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#ifdef UMQRA
    #define getTime() fprintf(stderr, "Running time:%.3lf seconds\n", (double)(clock()) / CLOCKS_PER_SEC)
#else
    #define getTime()
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 1024;

ll f[4][N][N];

void addVal(int x, int y, ll val, int ind)
{
    for (int i = x; i < N; i |= (i + 1))
        for (int s = y; s < N; s |= (s + 1))
            f[ind][i][s] ^= val;
}

ll getSum(int x, int y, int ind)
{
    ll res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int s = y; s >= 0; s = (s & (s + 1)) - 1)
            res ^= f[ind][i][s];
    return res;
}

int getNumCoord(int x, int y)
{
    if (x & 1)
    {
        if (y & 1)
            return 0;
        return 1;
    }
    else
    {
        if (y & 1)
            return 2;
        return 3;
    }
}

void changeTable(int a, int b, int c, int d, ll val)
{
    addVal(a, b, val, getNumCoord(a, b));
    addVal(c + 1, d + 1, val, getNumCoord(c + 1, d + 1));
    addVal(a, d + 1, val, getNumCoord(a, d + 1));
    addVal(c + 1, b, val, getNumCoord(c + 1, b));
}

ll getXor(int a, int b)
{
    int t = getNumCoord(a, b);
    return getSum(a, b, t);
}

ll getXor(int a, int b, int c, int d)
{
    return getXor(c, d) ^ getXor(a - 1, d) ^ getXor(c, b - 1) ^ getXor(a - 1, b - 1);
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);   
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x0, y0, x1, y1;
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            printf("%lld\n", getXor(x0, y0, x1, y1));
        }
        else
        {
            int x0, y0, x1, y1;
            ll val;
            scanf("%d%d%d%d%lld", &x0, &y0, &x1, &y1, &val);
            changeTable(x0, y0, x1, y1, val);
        }
    }

    return 0;
}