#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
const int B = 1000;
int m, k, cnt, tot, a[100001], f[101][200001], g[101][200001], val[200001];
map<int, int> mp;
int get_id(int x)
{
    if (!mp.count(x))
    {
        val[++cnt] = x;
        return mp[x] = cnt;
    }
    return mp[x];
}
int main(int argc, char const *argv[])
{
    scanf("%d", &m);
    tot = (m - 1) / B + 1;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        a[i] = get_id(x);
    }
    for (int i = 1; i <= tot; i++)
    {
        int r = min(i * B - 1, m - 1);
        memcpy(f[i], f[i - 1], sizeof(f[i - 1]));
        memcpy(g[i], g[i - 1], sizeof(g[i - 1]));
        for (int j = B * (i - 1); j <= r; j++)
        {
            f[i][a[j]]++;
            g[i][f[i][a[j]]]++;
        }
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        y--;
        if (op == 1)
        {
            for (int j = y / B + 1; j <= tot; j++)
            {
                g[j][f[j][a[y]]]--;
                f[j][a[y]]--;
            }
            a[y] = get_id(x);
            for (int j = y / B + 1; j <= tot; j++)
            {
                f[j][a[y]]++;
                g[j][f[j][a[y]]]++;
            }
        }
        else
        {
            if (x == 1)
            {
                printf("%d\n", val[a[y]]);
            }
            else
            {
                int id = y / B;
                for (int j = id * B; j <= y; j++)
                {
                    f[id][a[j]]++;
                    g[id][f[id][a[j]]]++;
                }
                if (x & 1)
                {
                    printf("%d\n", g[id][f[id][a[y]]]);
                }
                else
                {
                    printf("%d\n", f[id][a[y]]);
                }
                for (int j = y; j >= id * B; j--)
                {
                    g[id][f[id][a[j]]]--;
                    f[id][a[j]]--;
                }
            }
        }
    }
    return 0;
}